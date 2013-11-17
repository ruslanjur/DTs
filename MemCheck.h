#ifndef __MEMCHK_H
#define __MEMCHK_H
#include <iostream>

namespace CYODT
{
    class MemCheck
    {
    private:
        static unsigned int dynCount;
        class Alert
        {
        public:
            ~Alert();
        };
        static Alert _a;
    protected:
    public:
        MemCheck();
        ~MemCheck();
    };
}
#endif