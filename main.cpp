#include "MemCheck.h"
#include <iostream>
//#include <stdio.h>


int strlen(char* str)
{
    int cnt = 0;
    while (str[cnt] != 0)
    {
        cnt++;
    }
    return cnt;
}


void strcpy(char* dest, char* src)
{
    for (int i = 0; i <= strlen(src); i++)
    {
        dest[i] = src[i];
    }
}



class MemSafeClass : public CYODT::MemCheck
{
private:
    char* str;
protected:
public:
    MemSafeClass(char* str);
    ~MemSafeClass();

    void setStr(char*);
    char* getStr() const;

};

std::ostream& operator<<(std::ostream& os, MemSafeClass& str);
std::istream& operator>>(std::istream& is, MemSafeClass& str);

int main()
{
#define STEP(n) std::cout<<"\n\t\tSTEP "<<n<<":"<<std::endl
    int step = 0;

    STEP(++step);
    MemSafeClass str("test1");

    STEP(++step);
    std::cout<<str<<std::endl;

    STEP(++step);
    std::cout<<"enter something: ";
    std::cin>>str;

    STEP(++step);
    std::cout<<str<<std::endl;

    STEP(++step);
    str = *(new MemSafeClass("extra"));

    STEP(++step);
    std::cout<<str<<std::endl;

    STEP("FINAL");
    return 0;
}

MemSafeClass::MemSafeClass(char* str)
{
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);

    std::cout<<"MemSafeClass("<<this->str<<")"<<std::endl;
}

MemSafeClass::~MemSafeClass()
{
    if (str) delete [] str;
    std::cout<<"~MemSafeClass()"<<std::endl;
}

void MemSafeClass::setStr(char* str)
{
    if (str)
    {
        if (this->str)
            delete [] this->str;
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
}

char* MemSafeClass::getStr() const
{
    return this->str;
}

std::ostream& operator<<(std::ostream& os, MemSafeClass& str)
{
    os<<str.getStr();
    return os;
}

std::istream& operator>>(std::istream& is, MemSafeClass& str)
{
    char tmp[100];
    is>>tmp;
    str.setStr(tmp);
    return is;
}

