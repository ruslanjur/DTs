#include "MemSafeClass.h"
#include <iostream>

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


MemSafeDemoClass::MemSafeDemoClass(char* str)
{
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);

    //std::cout<<"MemSafeDemoClass(\""<<this->str<<"\")"<<std::endl;
}

MemSafeDemoClass::~MemSafeDemoClass()
{
    if (str) delete [] str;
    //std::cout<<"~MemSafeDemoClass()"<<std::endl;
}

void MemSafeDemoClass::setStr(char* str)
{
    if (str)
    {
        if (this->str)
            delete [] this->str;
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
}

char* MemSafeDemoClass::getStr() const
{
    return this->str;
}

std::ostream& operator<<(std::ostream& os, MemSafeDemoClass& str)
{
    os<<str.getStr();
    return os;
}

std::istream& operator>>(std::istream& is, MemSafeDemoClass& str)
{
    char tmp[100];
    is>>tmp;
    str.setStr(tmp);
    return is;
}

