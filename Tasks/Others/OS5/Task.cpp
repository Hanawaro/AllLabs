#include "Task.hpp"

namespace OS5 {
    
    void Task::SetData(size_t count, Task::InputType inputType) {
        switch (inputType) {
            case InputType::HandWrite:
                ProcessManager::ReadUserData(m_Processes, count);
                break;
            case InputType::Random:
                ProcessManager::SetRandomData(m_Processes, count);
                break;
            default:
                throw std::runtime_error("unknown type");
                break;
        }
    }
    
}
