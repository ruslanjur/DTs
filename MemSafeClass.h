#include "MemCheck.h"

unsigned int CYODT::MemCheck<class MemSafeClass>::dynCount = 0;
CYODT::MemCheck<class MemSafeClass>::Alert CYODT::MemCheck<class MemSafeClass>::_a;

class MEMCHECK(MemSafeClass)
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
