#pragma once


#ifndef _DATA_H_
#define _DATA_H_

using namespace DirectX;

//enum CUSTOM_BUFFER_FLAG
//{
//	DEFAULT = 0x00000000,
//  	 EXTEND = 0x00000001,
//
//
//};

struct MeshBuffer
{
	ID3D11Buffer* VertexBuffer = nullptr;
	ID3D11Buffer* IndexBuffer = nullptr;
	ID3D11Buffer* ConstBuffer = nullptr;
	ID3D11Buffer* TerrainBuffer = nullptr;
	
};

struct GeometryBuffer
{
	ID3D11Buffer* StreamBuffer = nullptr;
	ID3D11Buffer* VertexStreamBuffer = nullptr;
};

struct Matrices
{
	XMMATRIX World;
	XMMATRIX View;
	XMMATRIX Projection;
};

struct TerrainBuffer
{
	float TerrainLength;
	XMFLOAT3 Padding;
};

struct Cell
{
	XMFLOAT3 CellPoints[8] = 
	{
		{ -1.0f, 1.0f, 1.0f }, // -++
		{ 1.0f, 1.0f, 1.0f }, // +++
		{ 1.0f, 1.0f, -1.0f }, // ++-
		{ -1.0f, 1.0f, -1.0f }, // -+-
		{ -1.0f, -1.0f, 1.0f }, // --+
		{ 1.0f, -1.0f, 1.0f }, // +-+
		{ 1.0f, -1.0f, -1.0f }, // +--
		{ -1.0f, -1.0f, -1.0f }, // ---
	
	}; // (x,y,z) w(density)


#ifdef _DEBUG
	float Density[8];
#endif
};

#endif