#pragma once

#include <iostream>

namespace SAOD { namespace FourthLab { namespace First {
    
    template <typename Type>
    class List {
        // Cell type
        struct Cell {
            Type data;
            Cell* next = nullptr;
            Cell* previous = nullptr;
            
            Cell(void) = default;
            Cell(const Type& newData) : data(newData) {}
        };
    public:
        // Iterator type
        struct Iterator : public std::iterator<std::random_access_iterator_tag, Type> {
            friend class List;
        public:
            explicit Iterator(Cell* cell = nullptr) : m_Cell(cell) {}
            ~Iterator(void) = default;
            
            const Type& operator*(void) const { return reinterpret_cast<Cell*>(m_Cell)->data; }
            Type& operator*(void) { return reinterpret_cast<Cell*>(m_Cell)->data; }
            
            Type& operator->(void) { return reinterpret_cast<Cell*>(m_Cell)->data; }
            const Type& operator->(void) const { return reinterpret_cast<Cell*>(m_Cell)->data; }
            
            Iterator& operator++(void) { m_Cell = m_Cell->next; return *this; }
            Iterator& operator++(int) { auto& tmp = *this; ++(*this); return tmp; }
            
            Iterator& operator--(void) { m_Cell = m_Cell->previous; return *this; }
            Iterator& operator--(int) { auto& tmp = *this; --(*this); return tmp; }
            
            size_t operator-(Iterator iterator) {
                size_t size = 0;
                while (iterator.m_Cell && iterator.m_Cell != m_Cell) {
                    iterator.m_Cell = iterator.m_Cell->next;
                    size++;
                }
                if (iterator.m_Cell)
                    return size;
                return 0;
            }
            
            Iterator operator-(size_t offset) {
                auto tmp = m_Cell;
                for (size_t i = 0; i < offset; i++) {
                    if (tmp->previous == nullptr)
                        throw std::runtime_error("error");
                    tmp = tmp->previous;
                }
                return Iterator(tmp);
            }
            
            Iterator operator+(size_t offset) {
                auto tmp = m_Cell;
                for (size_t i = 0; i < offset; i++) {
                    if (tmp->next == nullptr)
                        throw std::runtime_error("error");
                    tmp = tmp->next;
                }
                return Iterator(tmp);
            }
            
            Iterator& operator+=(size_t offset) {
                for (size_t i = 0; i < offset; i++) {
                    if (m_Cell->next == nullptr)
                        throw std::runtime_error("error");
                    m_Cell = m_Cell->next;
                }
                return *this;
            }
            
            Iterator& operator-=(size_t offset) {
                for (size_t i = 0; i < offset; i++) {
                    if (m_Cell->previous == nullptr)
                        throw std::runtime_error("error");
                    m_Cell = m_Cell->previous;
                }
                return *this;
            }
            
            bool operator<(Iterator iterator) {
                if (iterator.m_Cell)
                    iterator.m_Cell = iterator.m_Cell->previous;
                while (iterator.m_Cell && iterator.m_Cell != m_Cell) {
                    iterator.m_Cell = iterator.m_Cell->previous;
                }
                if (iterator.m_Cell)
                    return true;
                return false;
            }
            
            bool operator<=(Iterator iterator) {
                while (iterator.m_Cell && iterator.m_Cell != m_Cell) {
                    iterator.m_Cell = iterator.m_Cell->previous;
                }
                if (iterator.m_Cell)
                    return true;
                return false;
            }
            
            bool operator>(Iterator iterator) {
                if (iterator.m_Cell)
                    iterator.m_Cell = iterator.m_Cell->next;
                while (iterator.m_Cell && iterator.m_Cell != m_Cell) {
                    iterator.m_Cell = iterator.m_Cell->next;
                }
                if (iterator.m_Cell)
                    return true;
                return false;
            }
            
            bool operator>=(Iterator iterator) {
                while (iterator.m_Cell && iterator.m_Cell != m_Cell) {
                    iterator.m_Cell = iterator.m_Cell->next;
                }
                if (iterator.m_Cell)
                    return true;
                return false;
            }
            
            bool operator!=(const Iterator& it) { return m_Cell != it.m_Cell; }
            bool operator==(const Iterator& it) { return m_Cell == it.m_Cell; }
        private:
            Cell* m_Cell;
        };
    public:
        List(void) : m_Head(new Cell) { m_Instance = m_Head; }
        List(std::initializer_list<Type> list) : List() { for(auto& elem : list) push_back(elem); }
        List(const List& list) { for(auto elem : list) push_back(elem); }
        ~List(void) {
            clear();
            delete m_Head;
        }
        
        void insert(Iterator pos, const Type& data) {
            Cell* cellNewData = new Cell(data);
            Cell* current = pos.m_Cell;
            
            if (current == m_Head) {
                m_Head = cellNewData;
                m_Head->next = m_Instance;
                m_Instance->previous = m_Head;
            } else {
                cellNewData->next = current;
                cellNewData->previous = current->previous;
                
                current->previous->next = cellNewData;
                current->previous = cellNewData;
            }
            
            m_Size++;
        }
        
        void erase(Iterator first, Iterator last) {
            
            auto tmpFirst = first.m_Cell->previous;
            bool isHead = first.m_Cell == m_Head;
            
            for (auto& it = first; it != last; it++) {
                delete it.m_Cell;
                m_Size--;
            }
            
            if (isHead) {
                m_Head = last.m_Cell;
                m_Head->previous = nullptr;
            } else {
                tmpFirst->next = last.m_Cell;
                last.m_Cell->previous = tmpFirst;
            }
        }
        
        void erase(Iterator pos) {
            erase(pos, pos + 1);
        }
        
        inline void push_back(const Type& data) { insert(end(), data); }
        inline void pop_back(void) { if (m_Size) erase(begin() + (m_Size - 1)); }
        
        void clear(void) {
            while (m_Head != m_Instance) {
                auto head = m_Head->next;
                delete m_Head;
                m_Head = head;
            }
            m_Head = m_Instance = new Cell;
            m_Size = 0;
        }
        
        inline size_t size(void) const { return m_Size; }
        inline bool empty(void) const { return m_Size == 0; }
        
        inline Iterator begin(void) { return Iterator(m_Head); }
        inline Iterator end(void) { return Iterator(m_Instance == m_Head ? m_Head : m_Instance); }
        
        inline const Iterator begin(void) const { return Iterator(m_Head); }
        inline const Iterator end(void) const { return Iterator(m_Instance == m_Head ? m_Head : m_Instance); }
    private:
        size_t m_Size = 0;
        Cell* m_Head = nullptr;
        Cell* m_Instance = nullptr;
    };
    
} } }
