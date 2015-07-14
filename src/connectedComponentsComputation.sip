
// Define the SIP wrapper to the connectedComponentsComputation library.

%Module connectedComponentsComputation

class ComponentRaw /NoDefaultCtors/
{
%TypeHeaderCode
#include "connectedComponentsComputation.h"
%End

public:

    const char* verts;
    const int n_verts;
    const char* faces;
    const int n_faces;
    
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
    
    void* re();
};


