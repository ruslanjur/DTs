#include "MemCheck.h"

unsigned int CYODT::MemCheck::dynCount = 0;
CYODT::MemCheck::Alert CYODT::MemCheck::_a;

namespace CYODT
{
    MemCheck::Alert::~Alert()
    {        
        if(dynCount != 0) 
        {            
            std::cout<<"Something went wrong. "<<dynCount<<"objects were not deallocated. Do something, fast.";
            int input;            
            std::cin>>input;
        }
    }

    MemCheck::MemCheck()
    {
        //std::cout<<"MemCheck::dynCount: "<<MemCheck::dynCount<<"++"<<std::endl;
        MemCheck::dynCount++;
    }

    MemCheck::~MemCheck()
    {
        //std::cout<<"MemCheck::dynCount: "<<MemCheck::dynCount<<"--"<<std::endl;
        MemCheck::dynCount--;
    }
}
