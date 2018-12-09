#include "stdafx.h"     

void BaseObjects::PrintBlock(BlocksID ID, Vector3 Coords, bool* RenderSide) {
	    
	if (ID != ID_Air) {
		 
		glBegin(GL_QUADS);

		for (int i = 0; i < 6; i++) {
			if(RenderSide[i]) GrassDirt.Side[i].DrawSquare(Coords);
		}

		glEnd();
	}
} 

BlockInstance BaseObjects::GrassDirt = BlockInstance(ID_GrassDirt);