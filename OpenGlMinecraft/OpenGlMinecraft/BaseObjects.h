#pragma once
#include "stdafx.h"   

#define BLOCK_SIZE 1
#define WorldSizeX 1
#define WorldSizeZ 1
#define ChunkSizeX 16
#define ChunkSizeZ 16
#define ChunkSizeY 256

static struct Vector3;
static struct Vector2;
static struct Color;
static struct Square;
static struct Cube;

static enum BlocksID {
	ID_Air,
	ID_Dirt,
	ID_GrassDirt,
};

static enum Side {
	TopFace,
	BottomFace,
	RightFace,
	LeftFace,
	FrontFace,
	BackFace
};

static struct Vector3 {
	float x;
	float z;
	float y;

	Vector3(float x_ = 0, float y_ = 0, float z_ = 0) {
		x = x_;
		y = y_;
		z = z_;
	}

	void DrawVector3AsVertex3(Vector3 OffSet = Vector3(0,0,0)) {
		glVertex3f(x + OffSet.x, y + OffSet.y, z + OffSet.z);
		//glVertex3f(x, y, z);
	}  
};

static struct Vector2 {
	float x;
	float y;

	Vector2(float x_ = 0, float y_ = 0) {
		x = x_;
		y = y_; 
	}
};

static struct Color {
	float r;
	float g;
	float b;
	float a;

	Color(float r_ = 1, float g_ = 1, float b_ = 1, float a_ = 1) {
		r = r_;
		g = g_;
		b = b_;
		a = a_;
	}

	void FillWithColor() {
		glColor3f(r, g, b);
	}
};

static struct Square {

	Color color;
	//[?] MATERIAL
	Vector3 vertex[4];
	Side side; 

	Square(Side side_ = TopFace, Color color_ = Color()) {
		color = color_;
		side = side_; 
		SetVertexs(side);
	}

	void SetVertexs(Side side) { 
		float size = BLOCK_SIZE;
		switch (side) {
		case TopFace:
			vertex[0] = Vector3(size, size, 0);
			vertex[1] = Vector3(0, size, 0);
			vertex[2] = Vector3(0, size, size);
			vertex[3] = Vector3(size, size, size);
			break;
		case BottomFace:
			vertex[0] = Vector3(size, 0, size);
			vertex[1] = Vector3(0, 0, size);
			vertex[2] = Vector3(0, 0, 0);
			vertex[3] = Vector3(size, 0, 0);
			break;
		case RightFace:
			vertex[0] = Vector3(size, size, 0);
			vertex[1] = Vector3(size, size, size);
			vertex[2] = Vector3(size, 0, size);
			vertex[3] = Vector3(size, 0, 0);
			break;
		case LeftFace:
			vertex[0] = Vector3(0, size, size);
			vertex[1] = Vector3(0, size, 0);
			vertex[2] = Vector3(0, 0, 0);
			vertex[3] = Vector3(0, 0, size);
			break;
		case FrontFace:
			vertex[0] = Vector3(size, size, size);
			vertex[1] = Vector3(0, size, size);
			vertex[2] = Vector3(0, 0, size);
			vertex[3] = Vector3(size, 0, size);
			break;
		case BackFace:
			vertex[0] = Vector3(size, 0, 0);
			vertex[1] = Vector3(0, 0, 0);
			vertex[2] = Vector3(0, size, 0);
			vertex[3] = Vector3(size, size, 0);
			break;
		}
	}
	 
	void DrawSquare(Vector3 OffSet) {
		color.FillWithColor();
		for (int i = 0; i < 4; i++) {
			vertex[i].DrawVector3AsVertex3(OffSet);
		}
	}
};   

class BaseObjects
{
public: 
	static void PrintBlock(BlocksID ID, Vector3 Coords, bool* RenderSide);

	static class BlockInstance GrassDirt;
}; 