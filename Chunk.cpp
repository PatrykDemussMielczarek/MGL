#include "stdafx.h"
#include "BlocksObjects.h"
#include "Chunk.h"


Chunk::Chunk()
{   
	int Overworld = ChunkSizeY / 4;
	for (int y = 0; y < ChunkSizeY; y++) {
		for (int x = 0; x < ChunkSizeX; x++) {
			for (int z = 0; z < ChunkSizeZ; z++) { 
				if (y < Overworld) {
					//if(rand() % 5 == 0) ChunkBlocks[x][y][z] = BlocksObjects(ID_Air);
					//else ChunkBlocks[x][y][z] = BlocksObjects(ID_GrassDirt);
					ChunkBlocks[x][y][z] = BlocksObjects(ID_GrassDirt);
				}
			}
		} 
	} 
} 



void Chunk::PrintChunk(Vector2 Coords) {
	int OffSetX = (Coords.x*ChunkSizeX);
	int OffSetZ = (Coords.y*ChunkSizeZ);

	for (int y = 0; y < ChunkSizeY; y++) {
		for (int x = 0; x < ChunkSizeX; x++) {
			for (int z = 0; z < ChunkSizeZ; z++) {
				BaseObjects::PrintBlock(ChunkBlocks[x][y][z].GetID(), Vector3(x + OffSetX, y, z + OffSetZ), ChunkBlocks[x][y][z].GetRenderSide());
			}
		}
	}
}


void Chunk::CalculateRender() {

	for (int y = 0; y < ChunkSizeY; y++) {
		for (int x = 1; x < ChunkSizeX - 1; x++) {
			for (int z = 1; z < ChunkSizeZ - 1; z++) { 
				if (ChunkBlocks[x][y][z].GetID() != ID_Air) { 
					
					//Front
					if (ChunkBlocks[x][y][z - 1].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[0] == true;
					else ChunkBlocks[x][y][z].RenderSide[0] = false;

					//Right
					if (ChunkBlocks[x + 1][y][z].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[1] == true;
					else ChunkBlocks[x][y][z].RenderSide[1] = false;

					//Back
					if (ChunkBlocks[x][y][z + 1].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[2] = true;
					else ChunkBlocks[x][y][z].RenderSide[2] = false;

					//Left
					if (ChunkBlocks[x - 1][y][z].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[3] = true;
					else ChunkBlocks[x][y][z].RenderSide[3] = false;

					//Top
					if (y != ChunkSizeY - 1) {
						if (ChunkBlocks[x][y + 1][z].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[4] = true;
						else ChunkBlocks[x][y][z].RenderSide[4] = false;
					}
					else ChunkBlocks[x][y][z].RenderSide[5] = true;

					//Bottom
					if (y != 0) {
						if (ChunkBlocks[x][y - 1][z].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[5] = true;
						else ChunkBlocks[x][y][z].RenderSide[5] = false;
					}
					else ChunkBlocks[x][y][z].RenderSide[5] = true;
				}
			}
		}
	}
}

void Chunk::CheckRenderForChunkSide(Side side, Chunk CheckChunk) {

	 
	switch (side)
	{
	case FrontFace:   
		for (int y = 0; y < ChunkSizeY; y++) {
			for (int x = 0; x < ChunkSizeX; x++) {
				if( CheckChunk.ChunkBlocks[x][y][ChunkSizeZ - 1].GetID() == ID_Air ) ChunkBlocks[x][y][0].RenderSide[0] = true;
				else ChunkBlocks[x][y][0].RenderSide[0] = false;
			}
		}
		break;
	case RightFace:
		for (int y = 0; y < ChunkSizeY; y++) {
			for (int z = 0; z < ChunkSizeZ; z++) {
				if (CheckChunk.ChunkBlocks[ChunkSizeX-1][y][z].GetID() == ID_Air) ChunkBlocks[0][y][z].RenderSide[1] = false;
				else ChunkBlocks[0][y][z].RenderSide[1] = false;
			}
		}
		break;
	case BackFace:
		for (int y = 0; y < ChunkSizeY; y++) {
			for (int x = 0; x < ChunkSizeX; x++) {
				if (CheckChunk.ChunkBlocks[x][y][0].GetID() == ID_Air) ChunkBlocks[x][y][ChunkSizeZ-1].RenderSide[2] = false;
				else ChunkBlocks[x][y][ChunkSizeZ-1].RenderSide[2] = false;
			}
		}
		break;
	case LeftFace:
		for (int y = 0; y < ChunkSizeY; y++) {
			for (int z = 0; z < ChunkSizeZ; z++) {
				if (CheckChunk.ChunkBlocks[0][y][z].GetID() == ID_Air) ChunkBlocks[ChunkSizeX-1][y][z].RenderSide[3] = false;
				else ChunkBlocks[ChunkSizeX - 1][y][z].RenderSide[3] = false;


			}
		}
		break;   
	}
} 
