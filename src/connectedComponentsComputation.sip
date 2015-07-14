
// Define the SIP wrapper to the connectedComponentsComputation library.

%Module connectedComponentsComputation



class ConnectedComponentsComputation 
{
%TypeHeaderCode
#include "connectedComponentsComputation.h"
%End
   
public:
        
    ConnectedComponentsComputation();
    
    int getComponents(char* vertices_raw, int n_verts, char* faces_raw, int n_faces);


};


