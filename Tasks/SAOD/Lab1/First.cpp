#include "First.hpp"

namespace SAOD { namespace FirstLab { namespace First {

    void Task::DoWork(QuickData& data) {
        Sort(data);
        Print(data);
    }
    
    void Task::DoWork(SlowData& data) {
        Sort(data);
        Print(data);
    }

    void Task::Sort(QuickData& data) {
        // n log n
        std::sort(data.get_vec().begin(), data.get_vec().end(), [](double f, double s) { return f < s; });
    }
    
    void Task::Sort(SlowData& data) {
        // n
        vec result;
        for (const auto& element : data.get_first())
            result.push_back(element);
        for (const auto& element : data.get_second())
            result.push_back(element);
        for (const auto& element : data.get_third())
            result.push_back(element);
        
        std::sort(result.begin(), result.end(), [](double f, double s) { return f < s; }); // n log n
        
        // n
        for (int id = 0; id < result.size(); id++) {
            if (id < data.get_first().size())
                data.get_first()[id] = result[id];
            else if (id >= data.get_first().size() && id < data.get_second().size() + data.get_first().size())
                data.get_second()[id - data.get_first().size()] = result[id];
            else if (id >= data.get_first().size() + data.get_second().size() && id < data.get_first().size() + data.get_second().size() + data.get_third().size())
                data.get_third()[id - data.get_first().size() - data.get_second().size()] = result[id];
        }
    }
    
    void Task::Print(const QuickData& data) {
        std::cout << " Результат:" << std::endl;
        std::cout << "  ";
        for (auto it = data.get_vec().begin(); it != data.get_vec().begin() + data.get_size().first; it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl << "  ";
        for (auto it = data.get_vec().begin() + data.get_size().first; it != data.get_vec().begin() + data.get_size().first + data.get_size().second; it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl << "  ";
        for (auto it = data.get_vec().begin() + data.get_size().first + data.get_size().second; it != data.get_vec().begin() + data.get_size().first + data.get_size().second + data.get_size().third; it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    
    void Task::Print(const SlowData& data) {
        std::cout << " Результат:" << std::endl;
        std::cout << "  ";
        for (const auto& element : data.get_first()) {
            std::cout << element << " ";
        }
        std::cout << std::endl << "  ";
        for (const auto& element : data.get_second()) {
            std::cout << element << " ";
        }
        std::cout << std::endl << "  ";
        for (const auto& element : data.get_third()) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    
} } }
