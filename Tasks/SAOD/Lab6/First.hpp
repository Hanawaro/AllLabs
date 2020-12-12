#pragma once

#include "Tree.hpp"
#include <iostream>

namespace SAOD { namespace SixthLab { namespace First {
    
    class Task {
        using listNode = List<Tree<std::string>::Node*>;
    public:
        void DoExample(void);
    private:
        void FillCourses(void);
        void CheckNodes(const listNode& listLeft, const std::string& pathLeft, const listNode& listRight, const std::string& rightPath);
    private:
        Tree<std::string> m_Courses;
    };
    
} } }
