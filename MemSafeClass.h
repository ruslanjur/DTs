#include "MemCheck.h"

MEMCHECKSTATICS(MemSafeDemoClass)

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
