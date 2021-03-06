// OpenGlMinecraft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include "BlocksObjects.h" 
#include "Chunk.h"

using namespace std; 
 
float Start;
float Stop;
float Previous = 16.667;

GLfloat angleCube;
int refreshMills = 16.667;

Chunk Chunks[WorldSizeX][WorldSizeZ];

void InitGL(void) {
	//glClearColor(1, 1, 1, 0);
	//glMatrixMode(GL_MODELVIEW);
	//gluPerspective(90, 0, 0, 1000);

	srand(time(NULL)); 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest 
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
	 
	 
	for (int x = 0; x < WorldSizeX; x++) {
		for (int y = 0; y < WorldSizeZ; y++) {
			Chunks[x][y] = Chunk();
		}
	} 
}
/* Called back when timer expired [NEW] */
void Timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, Timer, 0); // next timer call milliseconds later
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display() { 


	Stop = GetTickCount();
	Previous = (Previous + (Stop - Start)) / 2;
	cout << (int)Previous << endl;
	Start = GetTickCount();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	  
	glLoadIdentity();                 // Reset the model-view matrix 

	gluLookAt(WorldSizeX*ChunkSizeX*BLOCK_SIZE, ChunkSizeY, 2*WorldSizeZ*ChunkSizeZ*BLOCK_SIZE, WorldSizeX*ChunkSizeX/2 * BLOCK_SIZE*BLOCK_SIZE, ChunkSizeY/2 * BLOCK_SIZE, WorldSizeZ*ChunkSizeZ/2 * BLOCK_SIZE, 0.0, 1.0, 0.0);
	 
	glRotatef(angleCube, angleCube, angleCube, 1.0f);
	   
	for (int x = 0; x < WorldSizeX; x++) {
		for (int y = 0; y < WorldSizeZ; y++) {
			Chunks[x][y].PrintChunk(Vector2(x,y));
		}
	} 

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

	angleCube += 0.64f; 
}
/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
								  // Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Minecraft");          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	InitGL();                       // Our own OpenGL initialization
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}

