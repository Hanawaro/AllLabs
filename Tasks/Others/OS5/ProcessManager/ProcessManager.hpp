#pragma once

#include <vector>
#include "../Process/Process.hpp"
#include "../../../../Reader.hpp"

namespace OS5 {
    
    class ProcessManager {
    private:
        using vec = std::vector<Process>;
        ProcessManager(void) = default;
    public:
        ProcessManager(const ProcessManager&) = delete;
        ProcessManager& operator=(const ProcessManager&) = delete;
        
        static void SetRandomData(vec& processes, vec::size_type count);
        static void ReadUserData(vec& processes, vec::size_type count);
        
        static void Info(const Process& process);
        static bool IsDone(const vec::iterator& start, const vec::iterator& last);
        static vec::iterator GetReadyFirst(const vec::iterator& start, const vec::iterator& lest, unsigned ticks);
    private:
        static const size_t s_MinimalCount = 1;
        static const size_t s_MaximalCount = 10;
        
        static const size_t s_MinimalStartCount = 0;
        static const size_t s_MaximalStartCount = 5;
    };
    
}
