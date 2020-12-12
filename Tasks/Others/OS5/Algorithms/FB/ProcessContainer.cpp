#include "ProcessContainer.hpp"

namespace OS5 {
    
    std::vector<Process>* ProcessContainer::s_Processes = nullptr;
    std::vector<Process>::iterator* ProcessContainer::s_DequeLimiter = nullptr;
    
}
