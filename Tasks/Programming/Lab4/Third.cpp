#include "Third.hpp"

namespace Programming { namespace FourthLab { namespace Third {
    
    bool Task::LookFile(const std::string& path) {
        std::ifstream in(path);
        if (in.is_open()) {
            in.seekg(0, std::ios::end);
            m_Data.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&m_Data[0], m_Data.size());
            in.close();
        } else {
            std::cout << "  Не удалось открыть файл" << std::endl;
            throw "Read file error";
            return false;
        }
        return true;
    }
    
    void Task::Replace(const std::string& line, const std::string& subline) {
        std::cout << "\n  Текст до: " << std::endl << m_Data << std::endl;
        size_t position = 0;
        while ((position = m_Data.find(line, position)) != std::string::npos) {
            m_Data.replace(position, line.size(), subline);
            position+=subline.size();
        }
        std::cout << "\n  Текст после:" << std::endl << m_Data << std::endl << std::endl;
    }
    
    void Task::Remove(void) {
        std::cout << "\n  Текст до: " << std::endl << m_Data << std::endl;
        
        int count = 0;
        m_Data.erase(
            std::remove_if(m_Data.begin(), m_Data.end(),
                [&](char ch) {
                    bool res = ch >= '0' && ch <= '9';
                    if (res) count++;
                    return res;
            }), m_Data.end()
        );
        
        std::cout << "\n  Текст после:" << std::endl << m_Data << std::endl << std::endl;
        std::cout << "  Количество цифр = " << count << std::endl;
    }
    
    
} } }
