#include "stdafx.h"
#include "BlocksObjects.h"
#include "Chunk.h"


Chunk::Chunk()
{   
	for (int y = 0; y < ChunkSizeY; y++) {
		for (int x = 0; x < ChunkSizeX; x++) {
			for (int z = 0; z < ChunkSizeZ; z++) { 
				if (y < 64) { 
					ChunkBlocks[x][y][z] = BlocksObjects(ID_GrassDirt);
				}
			}
		} 
	}
	for (int y = 0; y < ChunkSizeY; y++) {
		for (int x = 1; x < ChunkSizeX-1; x++) {
			for (int z = 1; z < ChunkSizeZ-1; z++) { 
				if (ChunkBlocks[x][y][z].GetID() != ID_Air){ 
					
					//Front
					if (ChunkBlocks[x][y][z - 1].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[0] == true;
					else ChunkBlocks[x][y][z].RenderSide[0] = false;

					//Right
					if (ChunkBlocks[x+1][y][z].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[1] == true;
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
					}else ChunkBlocks[x][y][z].RenderSide[5] = true;

					//Bottom
					if (y != 0) {
						if (ChunkBlocks[x][y - 1][z].GetID() == ID_Air) ChunkBlocks[x][y][z].RenderSide[5] = true;
						else ChunkBlocks[x][y][z].RenderSide[5] = false;
					}else ChunkBlocks[x][y][z].RenderSide[5] = true;
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
