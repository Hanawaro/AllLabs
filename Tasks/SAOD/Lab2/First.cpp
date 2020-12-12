#include "First.hpp"

namespace SAOD { namespace SecondLab { namespace First {
    
    static inline bool checkLimit(wchar_t ch) {
        switch (ch) {
            case ' ':
            case ',':
            case '.':
            case '!':
            case '?':
            case '\"':
            case ':':
            case '\\':
            case '/':
            case '(':
            case ')':
//            case '-':
            case '\n':
                return true;
            default:
                return false;
        }
    }
    
    void Task::DoWork(const std::string& inPath, const std::string& outPath, const std::wstring& limiter) {
        // files' streams
        std::wifstream in(inPath);
        if (!in.is_open()) {
            std::cout << "  Не удалось открыть файл" << std::endl;
            return;
        }
        
        std::wofstream out(outPath);
        
        // reading and writing
        
        size_t bufferSize = 1 << 20; // 1 mB
        wchar_t* buffer = new wchar_t[bufferSize];
        
        std::wstring wordBuffer;
        
        while (in) {
            in.read(buffer, bufferSize);
            auto count = in.gcount();
        
            if (!count) break;
            size_t index = 0;
            bool isNewWord = true;
            bool flag = false;
            do {
                
                if (checkLimit(buffer[index])) {
                    if (flag == false)
                        isNewWord = true;
                    flag = true;
                } else {
                    flag = false;
                    isNewWord = false;
                    wordBuffer += tolower(std::towlower(buffer[index]));
                }
                
                if (isNewWord) {
                    out << wordBuffer << limiter;
                    wordBuffer.clear();
                    isNewWord = false;
                }
            } while (++index != count);
            
        }
        
        if (wordBuffer.size())
            out << wordBuffer << limiter;
        
        // free memory
        in.close();
        out.close();
        delete[] buffer;
    }
    
} } }
