#pragma once

class BlockInstance
{
public: 
	BlockInstance(BlocksID BlockID_ = ID_GrassDirt);

	BlocksID BlockID;

	Square Side[6];
	 
};

