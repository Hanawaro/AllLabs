#pragma once

#include "../../ProcessManager/ProcessManager.hpp"

namespace OS5 {
    
    class ProcessContainer {
    private:
        ProcessContainer(void) = delete;
    public:
        ProcessContainer(const ProcessContainer&) = delete;
        ProcessContainer& operator=(const ProcessContainer&) = delete;
        
        static inline void SetData(std::vector<Process>* processes, std::vector<Process>::iterator* dequeLimiter) {
            s_Processes = processes;
            s_DequeLimiter = dequeLimiter;
        }
        
        static void Log(const std::string& title) {
            std::cout << title << std::endl;
            std::cout << "  Приоритетная очередь: " << std::endl;
            for (auto it = s_Processes->begin(); it != *s_DequeLimiter; it++)
                std::cout << "   " << *it << std::endl;
            std::cout << "  Бэк очередь: " << std::endl;
            for (auto it = *s_DequeLimiter; it != s_Processes->end(); it++)
                std::cout << "   " << *it << std::endl;
            std::cout << std::endl;
        }
        
        static inline std::vector<Process>* GetProcesses(void) { return s_Processes; }
        static inline std::vector<Process>::iterator* GetDequeLimiter(void) { return s_DequeLimiter; }
    private:
        static std::vector<Process>* s_Processes;
        static std::vector<Process>::iterator* s_DequeLimiter;
    };
    
}
