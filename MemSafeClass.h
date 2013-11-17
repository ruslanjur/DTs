#include "MemCheck.h"

unsigned int CYODT::MemCheck<class MemSafeDemoClass>::dynCount = 0;
CYODT::MemCheck<class MemSafeDemoClass>::Alert CYODT::MemCheck<class MemSafeDemoClass>::_a;

class MEMCHECK(MemSafeDemoClass)
{
private:
    char* str;
protected:
public:
    MemSafeDemoClass(char* str);
    ~MemSafeDemoClass();

    void setStr(char*);
    char* getStr() const;

};

std::ostream& operator<<(std::ostream& os, MemSafeDemoClass& str);
std::istream& operator>>(std::istream& is, MemSafeDemoClass& str);
