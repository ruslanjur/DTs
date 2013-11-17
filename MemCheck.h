#include <iostream>

#define MEMCHECK(className) className : public CYODT::MemCheck<className>

namespace CYODT
{
    template<class T>
    class MemCheck
    {
    private:
        static unsigned int dynCount;
        class Alert
        {
        public:
            ~Alert()
            {
                if(dynCount != 0) 
                {            
                    std::cout<<"Something went wrong. A total of "<<dynCount<<" objects was not deallocated. Do something, fast.";
                    //Breakpoint goes here
                    int input;            
                    std::cin>>input;
                }
            }
        };
        static Alert _a;
    protected:
    public:
        MemCheck() { dynCount++; }
        ~MemCheck() { dynCount--; }
    };
}