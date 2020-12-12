#pragma once

#include <iostream>
#include <deque>
#include <array>
#include <functional>

namespace Programming { namespace SixthLab { namespace Second {
    
    struct Book {
        std::string author;
        std::string name;
        std::string genre;
        unsigned int pages;
        
        friend std::ostream& operator<<(std::ostream& out, const Book& book);
    };
    
    class RandomBookManager {
    public:
        Book GetBook(void) {
            Book book;
            book.author = Authors[rand()%Authors.size()];
            book.name = Names[rand()%Names.size()];
            book.genre = Genres[rand()%Genres.size()];
            book.pages = rand()%(MaxPages - MinPages) + MinPages;
            return book;
        }
    public:
        static const int s_AmountAuthor = 4;
        static const int s_AmountNames = 4;
        static const int s_AmountGenre = 4;
        
        const unsigned MinPages = 144;
        const unsigned MaxPages = 520;
        
        const std::array<std::string, s_AmountAuthor> Authors = {
            "First  author",
            "Second author",
            "Third  author",
            "Fourth author"
        };
        std::array<std::string, s_AmountNames> Names = {
            "First  name",
            "Second name",
            "Third  name",
            "Fourth name"
        };
        std::array<std::string, s_AmountAuthor> Genres = {
            "First  genre",
            "Second genre",
            "Third  genre",
            "Fourth genre"
        };
    };
    
    class Task {
    public:
        void DoExample(std::deque<Book>& first, std::deque<Book>& second, size_t indexOfLimitElement, unsigned count, std::function<bool(Book& left, Book& right)> func) {
            
            RandomBookManager rdBook;
            
            std::cout << std::endl << " До операций" << std::endl;
            
            print(first, "  Первый контейнер:");
            print(second, "  Второй контейнер:");
            
            first.erase(first.begin() + indexOfLimitElement, first.begin() + indexOfLimitElement + count);
            first.insert(first.end(), second.begin(), second.end());
            
            std::cout << std::endl << " После удаления и объединения" << std::endl;
            print(first, "  Первый контейнер:");
            print(second, "  Второй контейнер:");
            
            std::sort(first.begin(), first.end(), func);
            std::sort(second.begin(), second.end(), func);
            
            std::cout << std::endl << " После сортировки" << std::endl;
            
            print(first, "  Первый контейнер:");
            print(second, "  Второй контейнер:");
            
            std::cout << std::endl << " После объединения" << std::endl;
            
            std::deque<Book> third;
            third.insert(third.end(), first.begin(), first.end());
            third.insert(third.end(), second.begin(), second.end());
            print(third, "  Третий контейнер:");
            
            int specialCount = 0;
            for (auto it = third.begin(); it != third.end(); it++)
                if (it->genre == rdBook.Genres[0])
                    specialCount++;
            
            std::cout << " Количество книг: " << specialCount << std::endl;
        }
    private:
        void print(std::deque<Book>& deque, const std::string& message) {
            std::cout << message << std::endl;
            for (auto it = deque.begin(); it != deque.end(); it++)
                std::cout << "   " << *it << std::endl;;
            std::cout << std::endl;
        }
    };

} } }
