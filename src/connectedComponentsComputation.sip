
// Define the SIP wrapper to the connectedComponentsComputation library.

%Module connectedComponentsComputation



class ConnectedComponentsComputation 
{
%TypeHeaderCode

%End
   
public:
        
    ConnectedComponentsComputation();
    
    int getComponents(float* vertices_raw, unsigned int n_verts, unsigned int* faces_raw, unsigned int n_faces);


};


