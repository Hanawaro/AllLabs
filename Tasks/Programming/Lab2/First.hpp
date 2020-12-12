#pragma once

#include <iostream>
#include <vector>
#include <functional>

namespace Programming { namespace SecondLab { namespace First {

    struct Data {
        std::string Name;
        std::string Author;
        unsigned int Date;
        unsigned int Pages;
        
        Data(const std::string name, const std::string author, unsigned int date, unsigned int pages)
            : Name(name), Author(author), Date(date), Pages(pages) {}
    };
    
    class DataManager {
    public:
        DataManager(void)  = default;
        ~DataManager(void) = default;
        
        void AddDataLine(const Data& line);
        
        std::vector<Data> GetRandomData(unsigned int count) const;
        inline const std::vector<Data>& GetData(void) const { return m_Data; }
    private:
        const unsigned int m_EarlyDate   = 1920;
        const unsigned int m_CurrentDate = 2020;
        
        const unsigned int m_MinPages = 100;
        const unsigned int m_MaxPages = 500;
        
        const std::vector<std::string> m_Names  = {
            "TheBestBook",
            "TheSecondBook",
            "TheThirdBook",
            "TheFourthBook",
            "TheFifthBook"
        };
        
        const std::vector<std::string> m_Authors = {
            "Lex",
            "Cherno",
            "Robin",
            "Jack",
            "Elen"
        };
    private:
        std::vector<Data> m_Data;
    };
    
    class Task {
    public:
        Task(void) = default;
        virtual ~Task(void) = default;
        
        void SetBooksLibrary(const std::vector<Data>& books);
        void DoWork(std::function<bool(const Data& data)> func);
    private:
        std::vector<Data> m_Books;
    };
    
} } }
