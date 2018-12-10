#pragma once 

class Chunk
{
public:
	Chunk(); 

	BlocksObjects ChunkBlocks[ChunkSizeX][ChunkSizeY][ChunkSizeZ]; 
	 
	void PrintChunk(Vector2 Coords);
	void CalculateRender();
	void CheckRenderForChunkSide(Side side, Chunk CheckChunk);  
};

