#include "First.hpp"

namespace SAOD { namespace ThirdLab { namespace First {
    
    static void Print(Vector<int>& vec) {
        for (auto& elem : vec)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
    
    void Task::DoExample(void) {
//        Vector<int> vec = { 1, 2, 3 };
//        for (int i = 0; i < 10; i++)
//            vec.push_back(i);
//        Print(vec);
//
//        vec.clear();
//        for (int i = 0; i < 5; i++)
//            vec.push_back(i);
//        Print(vec);
//
//        for (int i = 0; i < 3; i++)
//            vec.pop_back();
//        vec[0] = 10;
//        Print(vec);
        
        List<int> list = { 4, 3, 1, 2 };
        std::sort(list.begin(), list.end(), [](int l, int r) { return l < r; });
        for (auto& element : list)
            std::cout << element << " ";
        std::cout << std::endl;
    }
    
} } }
