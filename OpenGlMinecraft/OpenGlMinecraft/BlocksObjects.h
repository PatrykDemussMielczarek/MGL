#pragma once
 
class BlocksObjects
{
private:  
	BlocksID ID;

public:
	BlocksObjects(BlocksID ID_ = ID_Air);

	bool RenderSide[6];

	BlocksID GetID();
	bool* GetRenderSide(); 
};

