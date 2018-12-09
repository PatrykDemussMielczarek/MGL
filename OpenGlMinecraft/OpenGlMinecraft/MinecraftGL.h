#pragma once 
#include "stdafx.h"

class MinecraftGL
{
public: 

	void DrawVertex3D(Vector3 vector3, Vector3 OffSet = Vector3());
	void DrawVertex3D(float x, float y, float z, Vector3 OffSet = Vector3());
	 
	void SetColor(Color color); 
	void SetColor(float r, float g, float b); 

	void DrawSquare(Square square, Vector3 OffSet = Vector3());
};

