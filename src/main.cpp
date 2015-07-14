/** Copyright (C) 2015 Ultimaker - Released under terms of the AGPLv3 License */

#include "connectedComponentsComputation.h"
#include <iostream>

//using namespace CuraConnectedComponents;

#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

int main(int argc, char **argv)
{
    float vertices[24] = 
    {
        0,0,0,
        1,0,0,
        0,1,0,
        0,0,1,
        10,10,10,
        11,10,10,
        10,11,10,
        10,10,11
    };
    unsigned int faces[24] =
    {
        0,1,2,
        1,2,3,
        0,2,3,
        0,1,3,
        4,5,6,
        5,6,7,
        4,6,7,
        4,5,7
    };
    
    ConnectedComponentsComputation comp;
    comp.getComponents(vertices, 8, faces, 8);
//     std::vector<Component> components = comp.getComponents();
//     for (Component component : components)
//     {
//         std::cerr << " next component " << std::endl;
//         for (Face face : component.faces)
//             std::cerr << face.vertex_idx(0) << ", " << face.vertex_idx(1) << ", " << face.vertex_idx(2) << std::endl;
//     }
}