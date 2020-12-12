#include "First.hpp"

namespace Programming { namespace FifthLab { namespace First {
    
    template<typename Type>
    static bool TryPrint(Book* book) {
        auto realBook = dynamic_cast<Type*>(book);
        if (realBook) {
            std::cout << "  Для " << realBook->GetPages() << " страниц, цена = " << realBook->GetPrice();
            return true;
        }
        return false;
    }
    
    static void Print(Book* book) {
        if (TryPrint<HardCover>(book)) std::cout << "\t : Твердая обложка" << std::endl;
        if (TryPrint<SoftCover>(book)) std::cout << "\t : Мягкая обложка" << std::endl;
        if (TryPrint<Magazine>(book)) std::cout << "\t : Журнал" << std::endl;
        if (TryPrint<Brochure>(book)) std::cout << "\t : Брошюра" << std::endl;
    }
    
    void Task::DoExample(void) {
        for (auto& book : m_Books)
            Print(book);
    }
    
} } }
