#pragma once

#include "List.hpp"
#include "Stack.hpp"

namespace SAOD { namespace FifthLab { namespace First {
    
    struct Cathedra {
        std::string Name;
        Cathedra(const std::string& name = "") : Name(name) {}
    };
    
    struct Faculty {
        std::string Name;
        Deque<Cathedra> deque;
        Faculty(const std::string& name = "", std::initializer_list<Cathedra> list = {}) : Name(name), deque(list) {}
    };
    
    class Task {
    public:
        void DoExample(void);
    private:
        static const size_t s_Count = 4;
        std::string m_FacultyNames[s_Count] = {
            "First_F",
            "Second_F",
            "Third_F",
            "Fourth_F"
        };
        
        std::string m_CathedraNames[s_Count] {
            "First_C",
            "Second_C",
            "Third_C",
            "Fourth_C"
        };
    };
    
} } }
