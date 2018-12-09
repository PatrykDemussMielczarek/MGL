#include "stdafx.h" 

BlockInstance::BlockInstance(BlocksID BlockID_) {

	BlockID = BlockID_;

	Color color[6] = {
		Color(0.0f, 1.0f, 0.0f),
		Color(0.588f, 0.39f, 0.196f), 
	};

	Side[0] = Square(FrontFace, color[1]);
	Side[1] = Square(RightFace, color[1]); 
	Side[2] = Square(BackFace, color[1]);
	Side[3] = Square(LeftFace, color[1]);
	Side[4] = Square(TopFace, color[0]);
	Side[5] = Square(BottomFace, color[1]);
} 