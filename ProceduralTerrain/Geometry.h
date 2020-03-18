#pragma once



#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#ifdef _INDEX16
typedef WORD Index;
#endif

#ifdef _INDEX32
typedef UINT Index;
#endif

using namespace DirectX;
using namespace std;

struct Vertex
{
	XMFLOAT3 Position;
	XMFLOAT3 Normal;
	XMFLOAT2 UV;
};

struct VoxelVertex
{
	XMFLOAT3 Position;
	float Density;
};

struct TerrainInstanceData
{
	XMFLOAT3 WorldPosition; // [64]{3}
	float Density[8];
};


struct TerrainInstances
{
	TerrainInstanceData* Instances = nullptr;
};

struct InputLayout
{
	vector<D3D11_INPUT_ELEMENT_DESC> InputElements;
	ID3D11InputLayout* IL = nullptr;


};

#ifdef _DEFERRED
struct Quad
{

};
#endif

struct Mesh
{
	vector<Vertex> Vertices;
	vector<Index> Indices;

};

struct Shader
{
	ID3D11VertexShader* VS = nullptr;
	ID3D11PixelShader* PS = nullptr;
	ID3D11GeometryShader* GS = nullptr;
	ID3D11ComputeShader* CS = nullptr;
	ID3D11HullShader* HS = nullptr;

	string VSEntry = "VS";
	string PSEntry = "PS";
	string GSEntry = "GS";
	string CSEntry = "CS";
	string HSEntry = "HS";

	string FileName;

	InputLayout InputLayouts;

};

struct Material
{
	Shader* MaterialShader = nullptr;
	string* FileName = &MaterialShader->FileName;

	Material() { MaterialShader = new Shader(); }
};

struct Model
{
	Mesh* ModelMesh = nullptr;
	MeshBuffer* ModelMeshBuffer = nullptr;
	GeometryBuffer* ModelGeoBuffer = nullptr;
};

void CreateCube(Model** OutModel);
void CreateTerrain(Model** OutModel);

#endif