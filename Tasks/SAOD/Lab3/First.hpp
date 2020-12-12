#pragma once

#include "List.hpp"

namespace SAOD { namespace ThirdLab { namespace First {
    
    template <typename Type>
    class Vector {
    public:
        Vector(void) = default;
        Vector(std::initializer_list<Type> list) : m_DataList(list) {}
        
        void push_back(const Type& data) { m_DataList.push_back(data); }
        void pop_back(void) { m_DataList.pop_back(); }
        
        void clear(void) { m_DataList.clear(); }
        
        Type& operator[](size_t index) { return *(m_DataList.begin() + (unsigned int) index); }
        const Type& operator[](size_t index) const { return *(m_DataList.begin() + index); }
        
        typename List<Type>::Iterator begin(void) { return m_DataList.begin(); }
        typename List<Type>::Iterator end(void) { return m_DataList.end(); }
    private:
        List<Type> m_DataList;
    };
    
    class Task {
    public:
        void DoExample(void);
    };
    
} } }
