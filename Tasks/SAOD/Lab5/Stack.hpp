#pragma once

#include <iostream>

namespace SAOD { namespace FifthLab { namespace First {

    template <typename Type>
    class Deque {
    public:
        struct Element {
            Type data;
            Element* next = nullptr;
            Element* previous = nullptr;
            
            Element(void) = default;
            Element(const Type& newData) : data(newData) {}
        };
    public:
        Deque(void) = default;
        Deque(std::initializer_list<Type> list) { for (auto& el : list) push(el); }
        Deque(const Deque& deq) {
            Element* elem = deq.m_Front;
            while (elem) {
                push(elem->data);
                elem = elem->next;
            }
        }
        ~Deque(void) { clear(); }
        
        void push(const Type& elem) {
            if (m_Front) {
                Element* newElement = new Element(elem);
                m_Back->next = newElement;
                newElement->previous = m_Back;
                m_Back = newElement;
            } else {
                m_Front = new Element(elem);
                m_Back = m_Front;
            }
            m_Size++;
        }
        
        void pop(void) {
            if (m_Front) {
                auto popElement = m_Front;
                m_Front = m_Front->next;
                delete popElement;
                m_Size--;
            }
        }
    
        inline Type front(void) const {
            if (!empty())
                return m_Front->data;
            else
                return Type();
        }
        
        inline size_t size(void) const { return m_Size; }
        inline bool empty(void) const { return m_Size == 0; }
        inline void clear(void) { while(!empty()) pop(); }
    private:
        size_t m_Size = 0;
        Element* m_Front = nullptr;
        Element* m_Back = nullptr;
        
    };
    
} } }
