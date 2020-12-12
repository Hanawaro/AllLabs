#pragma once

#include "List.hpp"

namespace SAOD { namespace FourthLab { namespace First {
    
    class Task {
    public:
        struct Info {
            unsigned int first;
            unsigned int next;
            unsigned int end;
        } info;
    public:
        void DoWork(void);
    private:
        inline List<int>::Iterator First(List<int>& list) { info.first++; return list.begin(); }
        inline List<int>::Iterator Next(List<int>::Iterator it) { info.next++; return (it + 1); }
        inline List<int>::Iterator End(List<int>& list) { info.end++; return list.end(); }
    };
    
} } }
