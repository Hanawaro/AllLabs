#pragma once

#include "ProcessContainer.hpp"
#include "../../ProcessManager/ProcessManager.hpp"
#include <vector>
#include <chrono>

namespace OS5 {
    
    class FB {
    private:
        FB(void) = default;
    public:
        FB(const FB&) = delete;
        FB& operator=(const FB&) = delete;
        
        static void DoAlgorigth(std::vector<Process>& precesses);
    private:
        static void SetProcessTicks(Process& process, unsigned int ticks, unsigned int& totalTicks);
        static inline void Conclusion(const std::vector<Process>& processes, long long time);
        static inline void Tick(void);
    };
    
}
