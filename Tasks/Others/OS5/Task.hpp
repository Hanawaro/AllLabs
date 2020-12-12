#pragma once

#include "ProcessManager/ProcessManager.hpp"
#include "Algorithms/FB/FB.hpp"
#include "Algorithms/SJF/SJF.hpp"

namespace OS5 {
    
    class Task {
    public:
        enum class InputType {
            HandWrite = 0,
            Random,
            Count
        };
        
        enum class AlgorithmType {
            FB = 0,
            SJF,
            Count
        };
    public:
        void SetData(size_t count, InputType inputType = InputType::Random);
        
        // algorithms
        inline void DoFB(void) { FB::DoAlgorigth(m_Processes); }
        inline void DoSJF(void) { SJF::DoAlgorigth(m_Processes); }
    private:
        std::vector<Process> m_Processes;
    };
    
}
