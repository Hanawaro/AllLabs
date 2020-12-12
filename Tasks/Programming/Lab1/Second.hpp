#pragma once

#include <vector>
#include <iostream>
#include <fstream>

#include "../../../Reader.hpp"

namespace Programming { namespace FirstLab { namespace Second {
    
    class Task {
    public:
        Task(void) = default;
        virtual ~Task(void) = default;
        
        void DoRand(uint32_t size, int left, int right);
        void DoHand(void);
        void DoFile(const std::string& name);
    private:
        void DoSort(void);
        void DoTask(void);
        inline void FinishTask(void);
    private:
        const std::string m_Path = "Result";
    private:
        std::vector<int> m_Vector;
        std::ofstream m_File;
    };
    
} } }
