#pragma once

#include <iostream>
#include <vector>

namespace Programming { namespace FifthLab { namespace First {
    
    class Book {
    public:
        Book(void) = default;
        Book(unsigned int pages) : m_Pages(pages) {}
        virtual ~Book(void) = default;
        
        inline void SetPages(unsigned int pages) { m_Pages = pages; }
        inline unsigned int GetPages(void) const { return m_Pages; }
        
        virtual unsigned int GetPrice(unsigned int count) const = 0;
    protected:
        unsigned int m_Pages = 0;
    };
    
    class HardCover : public Book {
    public:
        HardCover(void) = default;
        HardCover(unsigned int pages) : Book(pages) {}
        
        virtual inline unsigned int GetPrice(unsigned int count = 1) const override { return 10 * m_Pages + 200; }
    };
    
    class SoftCover : public Book {
    public:
        SoftCover(void) = default;
        SoftCover(unsigned int pages) : Book(pages) {}
        
        virtual inline unsigned int GetPrice(unsigned int count = 1) const override { return 8 * m_Pages + 50; }
    };
    
    class Magazine : public Book {
    public:
        Magazine(void) = default;
        Magazine(unsigned int pages) : Book(pages) {}
        
        virtual inline unsigned int GetPrice(unsigned int count = 1) const override { return 12 * m_Pages + 125; }
    };
    
    class Brochure : public Book {
    public:
        Brochure(void) = default;
        Brochure(unsigned int pages) : Book(pages) {}
        
        virtual inline unsigned int GetPrice(unsigned int count = 1) const override { return 5 * m_Pages + 17; }
    };
    
    
    class Task {
    public:
        enum class Type {
            HardCover,
            SoftCover,
            Magazine,
            Brochure,
            Amount
        };
    public:
        void DoExample(void);
        inline void push_back(Book* book) { m_Books.push_back(book); }
    private:
        std::vector<Book*> m_Books;
    };
    
} } }
