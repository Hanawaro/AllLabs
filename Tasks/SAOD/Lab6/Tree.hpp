#pragma once

#include "List.hpp"

namespace SAOD { namespace SixthLab { namespace First {
    
    template<typename Type>
    class Tree {
    public:
        struct Node {
            friend class Tree;
        public:
            operator Type() { return this->value; }
            inline const Type& get(void) const { return value; }
            inline const List<Node*>& getMembers(void) const { return members; }
        private:
            Type value;
            List<Node*> members;
        };
    public:
        Tree(void) = default;
        Tree(const Tree& tree) {}
        Tree(Tree&& tree) {}
        ~Tree(void) { Clear(); }
        
        Tree& operator=(const Tree& tree);
        Tree& operator=(Tree&& tree);
        
        template <typename ...Args>
        void AddNode(const Type& value, Args... args) {
            Type path[] { args... };
            List<Node*>* currentList = &m_Head;
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        currentList = &(currentList->begin() + localeCursor)->members;
                    }
                }
                if(!isTruePath) {
                    throw "Incorrect path";
                    return;
                }
            }
            
            for (auto it = currentList->begin(); it != currentList->end(); it++) {
                if (it->value == value) {
                    throw "Element is not unique";
                    return;
                }
            }
            
            Node* result = new Node;
            result->value = value;
            currentList->push_back(result);
        }
        
        template <typename ...Args>
        void AddNode(std::initializer_list<Type> list, Args... args) {
            Type path[] { args... };
            List<Node*>* currentList = &m_Head;
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        currentList = &(currentList->begin() + localeCursor)->members;
                    }
                }
                if(!isTruePath) {
                    throw "Incorrect path";
                    return;
                }
            }
            
            for (auto it = currentList->begin(); it != currentList->end(); it++) {
                for (auto elem : list) {
                    if (it->value == elem) {
                        throw "Element is not unique";
                        return;
                    }
                }
            }

            for (auto elem : list) {
                Node* result = new Node;
                result->value = elem;
                currentList->push_back(result);
            }
        }
        
        template <typename ...Args>
        void AddNode(const Type& value, uint32_t index, Args... args) {
            Type path[] { args... };
            List<Node*>* currentList = &m_Head;
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        currentList = &(currentList->begin() + localeCursor)->members;
                        break;
                    }
                }
                if(!isTruePath) {
                    throw "Incorrect path";
                    return;
                }
            }
            
            for (auto it = currentList->begin(); it != currentList->end(); it++) {
                if (it->value == value) {
                    throw "Element is not unique";
                    return;
                }
            }
            
            Node* result = new Node;
            result->value = value;
            currentList->insert(currentList->begin() + index, result);
        }

        template <typename ...Args>
        void SetNode(const Type& value, Args... args) {
            Type path[] { args... };
            
            Type* changeValue = nullptr;
            List<Node*>* currentList = &m_Head;
            
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        changeValue = &(currentList->begin() + localeCursor)->value;
                        currentList = &(currentList->begin() + localeCursor)->members;
                        break;
                    }
                }
                if(!isTruePath) {
                    throw "Incorrect path";
                    return;
                }
            }
            
            for (auto it = currentList->begin(); it != currentList->end(); it++) {
                if (it->value == value) {
                    throw "Element is not unique";
                    return;
                }
            }
            
            *changeValue = value;
        }

        template <typename ...Args>
        void RemoveNode(Args... args) {
            Type path[] { args... };
            
            Node* deletedNode = nullptr;
            List<Node*>* listWithDeletedNode = nullptr;
            List<Node*>* currentList = &m_Head;
            
            uint32_t indexOfDeletedNode = 0;
            
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        
                        listWithDeletedNode = currentList;
                        indexOfDeletedNode = localeCursor;
                        
                        deletedNode = *(currentList->begin() + localeCursor);
                        currentList = &(currentList->begin() + localeCursor)->members;
                        break;
                    }
                }
                if(!isTruePath) {
                    throw "Incorrect path";
                    return;
                }
            }
            
            if (deletedNode) {
                removeNode(deletedNode);
                if (listWithDeletedNode) {
                    listWithDeletedNode->erase(listWithDeletedNode->begin() + indexOfDeletedNode, listWithDeletedNode->begin() + indexOfDeletedNode + 1);
                }
            } else {
                Clear();
            }
        }

        template <typename ...Args>
        const List<Node*>& Get(Args... args) {
            Type path[] { args... };
            List<Node*>* currentList = &m_Head;
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        currentList = &(currentList->begin() + localeCursor)->members;
                    }
                }
                if(!isTruePath) {
                    throw "Incorrect path";
                }
            }
            
            return *currentList;
            
        }
        
        template <typename ...Args>
        bool Fine(Args... args) {
            Type path[] { args... };
            List<Node*>* currentList = &m_Head;
            for (int deepCursor = 0; deepCursor < sizeof...(Args); deepCursor++) {
                bool isTruePath = false;
                for (int localeCursor = 0; localeCursor < currentList->size(); localeCursor++) {
                    if (path[deepCursor] == (currentList->begin() + localeCursor)->value) {
                        isTruePath = true;
                        currentList = &(currentList->begin() + localeCursor)->members;
                    }
                }
                if(!isTruePath) {
                    return false;
                }
            }
            return true;
        }
        
        void Clear(void) {
            for (auto it = m_Head.begin(); it != m_Head.end(); it++)
                removeNode(*it);
            m_Head.clear();
        }
        
        inline bool IsEmpty(void) {
            return m_Head.empty();
        }
    private:
        void removeNode(Node* node) {
            for (auto it = node->members.begin(); it != node->members.end(); it++) {
                removeNode(*it);
            }
            delete node;
        }
    private:
        List<Node*> m_Head;
    };
    
} } }
