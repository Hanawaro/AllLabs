#include "First.hpp"

namespace SAOD { namespace FourthLab { namespace First {
    
    void Task::DoWork(void) {
        List<int> list = { 1, 2, 3, 4, 5 };
        
        List<int>::Iterator p, q, r;
        
        p = First(list);
        while ( p != End(list) ) {
            q = p;
            while ( q != End(list) ) {
                q = Next(q);
                r = First(list);
                while ( r != q )
                    r = Next(r);
            }
            p = Next(p);
        }
        
        std::cout << " First = " << info.first << std::endl <<
                     " Next =  " << info.next << std::endl <<
                     " End =   " << info.end << std::endl;
    };
    
} } }
