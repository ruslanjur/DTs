#include "MemSafeClass.h"

int main()
{
#define STEP(n) std::cout<<"\n\t\tSTEP "<<n<<":"<<std::endl
    int step = 0;

    STEP(++step);//1
    MemSafeClass _str("test1");  //Instantiate MemSafeClass _str with "test1" value

    STEP(++step);//2
    std::cout<<_str<<std::endl;  //Output _str on the screen

    STEP(++step);//3
    std::cout<<"enter something: ";
    std::cin>>_str; //Change the value stored in _str

    STEP(++step);//4
    std::cout<<_str<<std::endl; //Output changed _str on the screen

    //BROKEN STEP 1
    STEP(++step);//5
    _str = *(new MemSafeClass("extra"));    //allocate a new MemSafeClass object while forgetting to deallocate the old one

    //BROKEN STEP 2
    STEP(++step);//6
    std::cout<<_str<<std::endl; //Output the new _str on the screen

    STEP("FINAL");
    return 0;   //Main cleans stuff
}
