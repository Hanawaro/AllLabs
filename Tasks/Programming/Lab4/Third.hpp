#pragma once

#include <iostream>
#include <fstream>

namespace Programming { namespace FourthLab { namespace Third {
    
    class Task {
    public:
        bool LookFile(const std::string& path);
        void Replace(const std::string& line, const std::string& substring);
        void Remove(void);
    private:
        std::string m_Data;
    };
    
} } }
