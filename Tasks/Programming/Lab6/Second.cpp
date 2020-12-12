#include "Second.hpp"

namespace Programming { namespace SixthLab { namespace Second {

    std::ostream& operator<<(std::ostream& out, const Book& book) {
        out << book.name << " [ " << book.author << " ] : " << book.genre << ", " << book.pages;
        return out;
    }

} } }
