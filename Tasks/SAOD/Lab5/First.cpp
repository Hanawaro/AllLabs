#include "First.hpp"

namespace SAOD { namespace FifthLab { namespace First {
    
    void Task::DoExample(void) {
        List<Faculty> list;
        for(int i = 0; i < s_Count; i++) {
            Faculty faculty(m_FacultyNames[i]);
            for (int j = 0; j < s_Count; j++)
                faculty.deque.push(Cathedra(m_CathedraNames[j]));
            list.push_back(faculty);
        }
        
        auto it = list.begin();
        while (!list.empty()) {
            if (!(*it).deque.empty()) {
                std::cout << " Выдан факультету " << (*it).Name << ",\t кафедре " << (*it).deque.front().Name << std::endl;
                (*it).deque.pop();
            }
            if ((*it).deque.empty()) {
                std::cout << "  !!! Факультет " << (*it).Name << " полностью всё получил !!!" << std::endl;
                list.erase(it);
            }
            if (++it == list.end()) {
                it = list.begin();
                std::cout << std::endl;
            }
            
        }        
        std::cout << " Все факультеты получили компьютеры" << std::endl;
    }
    
} } }
