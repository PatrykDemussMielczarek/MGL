
#include "stdafx.h"    

void MinecraftGL::DrawVertex3D(Vector3 vector3, Vector3 OffSet) {
	glVertex3f(vector3.x + OffSet.x, vector3.y + OffSet.y, vector3.z + OffSet.z);
} 

void MinecraftGL::DrawVertex3D(float x, float y, float z, Vector3 OffSet){
	glVertex3f(x+ OffSet.x, y+ OffSet.y, z+ OffSet.z);
}

void MinecraftGL::SetColor(Color color) {
	glColor3f(color.r, color.g, color.b);
}

void MinecraftGL::SetColor(float r, float g, float b) {
	glColor3f(r,g,b);
}

void MinecraftGL::DrawSquare(Square square, Vector3 OffSet) {
	SetColor(square.color);
	for (int i = 0; i < 4; i++) {
		DrawVertex3D(square.vertex[i], OffSet);
	} 
} 