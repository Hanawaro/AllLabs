#pragma once

#include <fstream>
#include <iostream>


namespace SAOD { namespace SecondLab { namespace First {
    
    class Task {
    public:
        void DoWork(const std::string& inPath, const std::string& outPath, const std::wstring& limiter);
    };
    
} } }
