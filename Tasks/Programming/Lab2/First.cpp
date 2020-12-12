#include "First.hpp"

namespace Programming { namespace SecondLab { namespace First {
    
    void DataManager::AddDataLine(const Data& line) {
        m_Data.push_back(line);
    }
    
    std::vector<Data> DataManager::GetRandomData(unsigned int count) const {
        std::vector<Data> data;
        for (int i = 0; i < count; i++) {
            unsigned int date = rand()%(m_CurrentDate - m_EarlyDate) + m_EarlyDate;
            unsigned int pages = rand()%(m_MaxPages - m_MinPages) + m_MinPages;
            std::string name = m_Names[rand()%m_Names.size()];
            std::string author = m_Authors[rand()%m_Authors.size()];
            
            data.push_back(Data(name, author, date, pages));
        }
        
        return data;
    }
    
    void Task::SetBooksLibrary(const std::vector<Data>& books) {
        m_Books = books;
    }
    
    
    void Task::DoWork(std::function<bool(const Data& data)> func) {
        bool have = false;
        for (const auto& book : m_Books) {
            if (func(book)) {
                std::cout << "  " << book.Name
                          << "\tby " << book.Author << ", "
                          << book.Date << " year, "
                          << book.Pages << " pages" << std::endl;
                have = true;
            }
        }
        if (!have)
            std::cout << "  Таких книг нет" << std::endl;
    }

} } }
