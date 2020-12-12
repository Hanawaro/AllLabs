#pragma once

#include <iostream>
#include <vector>

namespace SAOD { namespace Seventh { namespace First {
    
    template<typename Type>
    class Tree {
        struct Cell {
            Cell(void) = default;
            Cell(const Type& value) : value(value) {}
            Type value;
            std::pair<Cell*, Cell*> children = { nullptr, nullptr};
        };
    public:
        struct Element {
            Type value;
            int index;
        };
    public:
        Tree(void) = default;
        Tree(const Type& value) { m_Head = new Cell(value); }
        
        Tree(const Tree& tree) { Copy(tree.m_Head); }
        Tree(Tree&& tree) { m_Head = tree.m_Head; tree.m_Head = nullptr; }
        
        Tree& operator=(const Tree& tree) { Copy(tree.m_Head); }
        Tree& operator=(Tree&& tree) { m_Head = tree.m_Head; tree.m_Head = nullptr; }
        
        ~Tree(void) { Clear(); }
        
        inline void Add(const Type& value) {
            if (!m_Head) {
                m_Head = new Cell(value);
            } else {
                DeepAdd(value, m_Head);
            }
        }

        inline void Remove(const Type& value) { DeepRemove(value, m_Head); }
        inline bool Serch(const Type& value) const { return DeepSerch(value, m_Head); }
        
        inline void TreeWalk(std::function<void(const Type& value)> func) { DeepTreeWalk(m_Head, func); }
        
        size_t GetDeep(void) { m_Deeping = 0; if (m_Head) DeepGetDepp(m_Head, 1); return m_Deeping; }
        
        std::vector<Element> GetElements(size_t deep) {
            std::vector<Element> result;
            int index = 0;
            PushDeepElements(index, m_Head, 1, deep, result);
            return result;
        }
        
        inline void Clear(void) { DeepClear(m_Head); m_Head = nullptr; }
        inline bool IsEmpty(void) const { return !m_Head; }
    private:
        void PushDeepElements(int& index, Cell* cell, size_t localeDeep, size_t deep, std::vector<Element>& vec) {
            if (cell == nullptr && localeDeep == deep) {
                index++;
                return;
            } else if (cell == nullptr) {
                int offset = 1;
                for (int i = 0; i < deep - localeDeep; i++)
                    offset *= 2;
                index += offset;
                return;
            }
            
            if (localeDeep == deep) {
                vec.push_back({cell->value, index});
                index++;
            } else {
                PushDeepElements(index, cell->children.first, localeDeep + 1, deep, vec);
                PushDeepElements(index, cell->children.second, localeDeep + 1, deep, vec);
            }
        }
        
        void DeepAdd(const Type& value, Cell* cell) {
            if (value <= cell->value) {
                if (cell->children.first)
                    DeepAdd(value, cell->children.first);
                else
                    cell->children.first = new Cell(value);
            } else {
                if (cell->children.second)
                    DeepAdd(value, cell->children.second);
                else
                    cell->children.second = new Cell(value);
            }
        }
        
        void DeepRemove(const Type& value, Cell*& cell) {
            if (!cell) return;
            if (cell->value == value && cell->children == std::pair<Cell*, Cell*>(nullptr, nullptr)) {
                delete cell;
                cell = nullptr;
            } else {
                DeepRemove(value, value <= cell->value ? cell->children.first : cell->children.second);
            }
        }
        
        bool DeepSerch(const Type& value, Cell* cell) const {
            if (cell == nullptr)
                return false;
            if (cell->value == value)
                return true;
            return DeepSerch(value, value <= cell->value ? cell->children.first : cell->children.second);
        }
        
        void DeepTreeWalk(Cell* cell, std::function<void(const Type& value)> func) {
            if (cell == nullptr) return;
            if (cell->children == std::pair<Cell*, Cell*>(nullptr, nullptr)) {
                func(cell->value);
            } else {
                if (cell->children.first)
                    DeepTreeWalk(cell->children.first, func);
                if (cell->children.second)
                    DeepTreeWalk(cell->children.second, func);
                func(cell->value);
            }
        }
        
        void DeepClear(Cell* cell) {
            if (!cell) return;
            if (cell->children == std::pair<Cell*, Cell*>(nullptr, nullptr)) {
                delete cell;
            } else {
                if (cell->children.first)
                    DeepClear(cell->children.first);
                if (cell->children.second)
                    DeepClear(cell->children.second);
            }
        }
        
        void Copy(Cell* cell) {
            if (cell)
                Add(cell->value);
            if (cell->children.first)
                Copy(cell->children.first);
            if (cell->children.second)
                Copy(cell->children.second);
        }
        
        void DeepGetDepp(Cell* cell, int deeping) {
            if (deeping > m_Deeping)
                m_Deeping = deeping;
            if (cell->children.first)
                DeepGetDepp(cell->children.first, deeping + 1);
            if (cell->children.second)
                DeepGetDepp(cell->children.second, deeping + 1);
        }
    private:
        Cell* m_Head = nullptr;
        size_t m_Deeping = 0;
    };
    
} } }
