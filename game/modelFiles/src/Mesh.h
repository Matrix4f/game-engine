#pragma once

struct Mesh
{
	float* vertices, *textures, *normals;
	unsigned int* indices;
	unsigned int vCount, iCount;

	inline Mesh()
		: vertices(nullptr), textures(nullptr), normals(nullptr), indices(nullptr),
		vCount(0), iCount(0)
	{

	}

	inline void free()
	{
		delete[] vertices;
		delete[] textures;
		delete[] normals;
		delete[] indices;
	}
};