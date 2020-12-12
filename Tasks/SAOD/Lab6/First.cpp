#include "First.hpp"

namespace SAOD { namespace SixthLab { namespace First {
    
    static void Example(void) {
        Tree<std::string> tree;
        tree.AddNode({"beginLeft", "beginCenter", "beginRight"}); // добавить в начало строки beginLeft, beginCenter, beginRight
        tree.AddNode({"left", "center", "right"}, "beginLeft"); // добавить в узел begin строки left, center, right
        tree.AddNode("deepLeft", "beginLeft", "left"); // добавить в узел beginLeft-left строку deepLeft
        
        tree.SetNode("change", "beginLeft", "left", "deepLeft"); // поменять строку beginLeft-left-deepLeft на beginLeft-left-change
        
        tree.RemoveNode("beginLeft"); // удалить всю ветвь beginLeft
        
        auto upLayer = tree.Get(); // Получить верхний слой
        
        std::cout << " In up layer \"beginLeft\"   = "   << tree.Fine("beginLeft") << std::endl;
        std::cout << " In up layer \"beginCenter\" = " << tree.Fine("beginCenter") << std::endl;
        
        std::cout << std::endl << " Up layer:" << std::endl;
        
        for (auto it = upLayer.begin(); it != upLayer.end(); it++) {
            std::cout << "  " << it->get() << std::endl; // вывести каждый элемент слоя
        }
    }
    
    void Task::FillCourses(void) {
        m_Courses.AddNode({"первый курс", "второй курс"});
        
        // первый курс
        m_Courses.AddNode({"дисциплина 2", "дисциплина 4"}, "первый курс");
        m_Courses.AddNode({"тема 1", "тема 2"}, "первый курс", "дисциплина 4");
        m_Courses.AddNode({"тема 1", "тема 2"}, "первый курс", "дисциплина 2");
        // второй курс
        m_Courses.AddNode({"дисциплина 1", "дисциплина 2", "дисциплина 3"}, "второй курс");
        m_Courses.AddNode({"тема 1", "тема 2"}, "второй курс", "дисциплина 1");
        m_Courses.AddNode({"тема 1", "тема 2", "тема 3"}, "второй курс", "дисциплина 2");
    }
    
    void Task::DoExample(void) {
        FillCourses();
        auto& courses = m_Courses.Get();
        
        const std::string begin = "[";
        
        for (auto itOut = courses.begin(); itOut != courses.end(); itOut++) {
            for (auto itIn = itOut + 1; itIn != courses.end(); itIn++) {
                CheckNodes(itOut->getMembers(), begin + itOut->get(), itIn->getMembers(), begin + itIn->get());
                CheckNodes(itIn->getMembers(), begin + itIn->get(), itOut->getMembers(), begin + itOut->get());
            }
        }
    }
    
    void Task::CheckNodes(const listNode& listLeft, const std::string& pathLeft, const listNode& listRight, const std::string& pathRight) {
        for (auto itOut = listLeft.begin(); itOut != listLeft.end(); itOut++) {
            bool isHave = false;
            listNode::Iterator itIn = listRight.begin();
            for (itIn = listRight.begin(); itIn != listRight.end(); itIn++) {
                if (itOut->get() == itIn->get()) {
                    isHave = true;
                    break;
                }
            }
            if (!isHave) {
                std::cout << "  "
                    << pathLeft << "]-[" << itOut->get() << "]\n  "
                    << pathRight << "]-[...]\n" << std::endl;
            } else {
                CheckNodes(itOut->getMembers(), pathLeft + "]-[" + itOut->get(), itIn->getMembers(), pathRight + "]-[" + itIn->get());
            }
        }
    }
    
} } }
