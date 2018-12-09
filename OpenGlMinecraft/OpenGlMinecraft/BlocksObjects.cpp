#include "stdafx.h"
#include "BlocksObjects.h"
 
BlocksObjects::BlocksObjects(BlocksID ID_) { 
	ID = ID_;
}

BlocksID BlocksObjects::GetID() {
	return ID;
}


bool* BlocksObjects::GetRenderSide() {
	return RenderSide;
}