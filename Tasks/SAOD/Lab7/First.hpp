#pragma once

#include "Tree.hpp"
#include <thread>

namespace SAOD { namespace Seventh { namespace First {
    
    class Task {
    public:
        void DoExample(void);
    private:
        enum class Status {
            Nothing = 0,
            Add     = static_cast<int>('a'),
            Remove  = static_cast<int>('r'),
            Clear   = static_cast<int>('c'),
            Exit    = static_cast<int>('e')
        };
        struct PairSize {
            int left  = 1;
            int right = 1;
        };
        
        struct SpacePair {
            int between = 1;
            PairSize size;
        };
    private:
        void ShowTree(void);
        void SetCountSpaceChildrens(std::vector<SpacePair>& vec, const std::vector<Tree<int>::Element>& elements);
        
        inline float GetHalf(int value) { return value / 2.0; }
        
        inline int GetCount(int deep) {
            int result = 1;
            for (int i = 0; i < deep; i++)
                result *= 2;
            return result;
        }
        
        inline int GetSize(int number) {
            int count = 1;
            while (number/=10)
                count++;
            return count;
        }
        
        
    private:
        bool m_IsRunning = true;
        Tree<int> m_Tree;
        
        const std::string emptyTreeElement = ".";
    };
    
} } }
