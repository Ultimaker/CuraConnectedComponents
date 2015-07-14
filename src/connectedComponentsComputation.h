#ifndef CONNECTED_COMPONENTS_COMPUTATION_H
#define CONNECTED_COMPONENTS_COMPUTATION_H

#include <unordered_map>
#include <queue>
#include <algorithm> // array fill

#include <iostream>
#include "debug.h"

// namespace CuraConnectedComponents
//{

struct VertexRaw
{
    float* vertices_raw;
    unsigned int idx;
    float getCoord(uint8_t dim) const { return *(vertices_raw + idx*3 + dim); }
    VertexRaw(float* vertices_raw, unsigned int idx) 
    : vertices_raw(vertices_raw), idx(idx) { }
    bool operator==(const VertexRaw& other) const { return idx == other.idx; }
};

struct VertexRaw_Hasher
{
    std::size_t operator()(const VertexRaw& vertex) const
    {
        return vertex.idx; // size_t(vertex.getCoord(0) * 10) + ( size_t(vertex.getCoord(1) * 10) << 5) + ( size_t(vertex.getCoord(2) * 10) << 10 );
    }
};

struct FaceRaw 
{
    unsigned int* faces_raw;
    unsigned int idx;
    unsigned int vertex_idx(uint8_t offset) const { return *(faces_raw + idx*3+offset); }
    FaceRaw(unsigned int* face_part_idx, unsigned int idx) 
    : faces_raw(face_part_idx), idx(idx) { }
    bool operator==(const FaceRaw& other) const { return idx == other.idx; }
};

struct Vertex
{
    float x,y,z;
    Vertex(float* begin) : x(*begin), y(*(begin+1)), z(*(begin+2)) { }
//     Vertex(VertexRaw& v) : x(v.getCoord(0)), y(v.getCoord(1)), z(v.getCoord(2)) { }
};

struct Face
{
    unsigned int p0, p1, p2;
    Face(unsigned int p0, unsigned int p1, unsigned int p2) : p0(p0), p1(p1), p2(p2) { }
};

struct Component
{
    std::vector<Vertex> verts;
    std::vector<Face> faces;
};

class ConnectedComponentsComputation 
{
    
    float* vertices_raw;
    unsigned int n_verts;
    
    unsigned int* faces_raw;
    unsigned int n_faces;
    
    int* vert_part_idx; // index '-1' is [yet unassigned vert]
    int* face_part_idx; // index '-1' is [yet unassigned face]

    
    std::unordered_multimap<VertexRaw, FaceRaw, VertexRaw_Hasher> vertex2faces;

    unsigned int lastUnassignedFace;
    unsigned int lastComponentId;

    void buildMap();

    void findNextUnassignedFace();
    
    void getComponent(unsigned int face_idx);
public:
        
    ConnectedComponentsComputation();
    
//     std::vector<Component> 
    int getComponents(float* vertices_raw, unsigned int n_verts, unsigned int* faces_raw, unsigned int n_faces);



};


//} // CuraConnectedComponents
#endif // CONNECTED_COMPONENTS_COMPUTATION_H
