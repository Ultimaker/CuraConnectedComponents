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
    int32_t faces[24] =
    {
        4,6,7, // 2
        0,1,2, // 1
        5,6,7, // 2
        0,2,3, // 1
        0,1,3, // 1
        1,2,3, // 1
        4,5,7, // 2
        4,5,6  // 2
    };
    
    ConnectedComponentsComputation comp;
    comp.compute(reinterpret_cast<char*>(vertices), 8, reinterpret_cast<char*>(faces), 8);
    
}