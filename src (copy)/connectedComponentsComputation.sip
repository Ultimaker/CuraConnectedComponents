
// Define the SIP wrapper to the connectedComponentsComputation library.

%Module connectedComponentsComputation


class ArrayRaw
{
%TypeHeaderCode
#include "connectedComponentsComputation.h"
%End
public:
    char* data /Array/;
    int length /ArraySize/;
    ArrayRaw();
    ArrayRaw(char* data, int length);
};


class ComponentRaw /NoDefaultCtors/
{
%TypeHeaderCode
#include "connectedComponentsComputation.h"
%End

public:

    ArrayRaw verts;
    ArrayRaw faces;
    
    ComponentRaw(char* verts, int n_verts, char* faces, int n_faces);
    
    ~ComponentRaw();
};


class ConnectedComponentsComputation 
{
%TypeHeaderCode
#include "connectedComponentsComputation.h"
%End
   
public:
        
    ConnectedComponentsComputation();
    
    int compute(char* vertices_raw, int n_verts, char* faces_raw, int n_faces);

    ComponentRaw getComponent(int id);
};


