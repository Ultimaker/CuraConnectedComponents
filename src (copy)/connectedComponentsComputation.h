#ifndef CONNECTED_COMPONENTS_COMPUTATION_H
#define CONNECTED_COMPONENTS_COMPUTATION_H

#include <vector>
#include <unordered_map>
#include <sip.h> // remove this?

#include <iostream> // debug
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
    int32_t* faces_raw;
    unsigned int idx;
    int32_t vertex_idx(uint8_t offset) const { return *(faces_raw + idx*3+offset); }
    FaceRaw(int32_t* face_part_idx, unsigned int idx) 
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
    int32_t p0, p1, p2;
    Face(int32_t p0, int32_t p1, int32_t p2) : p0(p0), p1(p1), p2(p2) { }
};

class ArrayRaw
{
public:
    const char* data;
    const int length;
    ArrayRaw() : data(nullptr), length(0) { }
    ArrayRaw(const char* data, const int length) : data(data), length(length) { }
//     ArrayRaw& operator =(const ArrayRaw& other) { ArrayRaw ret(other.data, other.length); return ret; }
};

class ComponentRaw
{
public:
    ArrayRaw verts;
    ArrayRaw faces;
    ComponentRaw() : verts(), faces() { }
    ComponentRaw(char* verts, int n_verts, char* faces, int n_faces) : verts(verts, n_verts), faces(faces, n_faces) { }
};

struct Component
{
    std::vector<Vertex>* verts;
    std::vector<Face>* faces;
    Component() 
    {
        verts = new std::vector<Vertex>;
        faces = new std::vector<Face>;
    }
    ComponentRaw toComponentRaw()
    {
        ComponentRaw ret(reinterpret_cast<char*>(&((*verts)[0])), verts->size(), reinterpret_cast<char*>(&((*faces)[0])), faces->size());
        return ret;
    }
};




class ConnectedComponentsComputation 
{
    
    float* vertices_raw;
    unsigned int n_verts;
    
    int32_t* faces_raw;
    unsigned int n_faces;
    
    int* vert_part_idx; // index '-1' is [yet unassigned vert]
    int* face_part_idx; // index '-1' is [yet unassigned face]

    
    std::unordered_multimap<VertexRaw, FaceRaw, VertexRaw_Hasher> vertex2faces;

    std::vector<Component> result;
    
    unsigned int lastUnassignedFace;
    unsigned int lastComponentId;

    void buildMap();

    void findNextUnassignedFace();
    
    void computeComponent(unsigned int face_idx);
    
    int computeComponents(float* vertices_raw, unsigned int n_verts, int32_t* faces_raw, unsigned int n_faces);
public:
        
    ConnectedComponentsComputation();
    
//     std::vector<Component> 
    int compute(char* vertices_raw, int n_verts, char* faces_raw, int n_faces);

    ComponentRaw getComponent(int id);

};


//} // CuraConnectedComponents
#endif // CONNECTED_COMPONENTS_COMPUTATION_H
