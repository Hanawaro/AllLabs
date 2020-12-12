#pragma once

#include "../../ProcessManager/ProcessManager.hpp"
#include <vector>
#include <chrono>

namespace OS5 {
    
    class SJF {
    private:
        SJF(void) = default;
    public:
        SJF(const SJF&) = delete;
        SJF& operator=(const SJF&) = delete;
        
        static void DoAlgorigth(std::vector<Process>& processes);
    private:
        static inline void Conclusion(const std::vector<Process>& processes, long long time);
        static inline void Tick(std::vector<Process>& processes);
    };
    
}
