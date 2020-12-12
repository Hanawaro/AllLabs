#include "Process.hpp"

#define PRINT(stream, size, orientation, data) { stream.width(size); stream << orientation << data; }

#define PRINT_PROCESS_RIGHT(size, data) PRINT(out, size, std::right, data)
#define PRINT_PROCESS_LEFT(size, data) PRINT(out, size, std::left, data)

namespace OS5 {
    
    std::string Process::PriorityToString(Process::Priority priority) {
        switch (priority) {
            case Priority::Critical:
                return "critical";
            case Priority::High:
                return "high";
            case Priority::Low:
                return "low";
            case Priority::Medium:
                return "medium";
            default:
                throw std::runtime_error("unknown priority type");
                return "count priority type";
        }
    }
    
    std::string Process::StateToString(Process::State state) {
        switch (state) {
            case State::Done:
                return "done";
            case State::Making:
                return "making";
            case State::Waiting:
                return "waiting";
            default:
                throw std::runtime_error("unknown state type");
                return "count state type";
        }
    }
    
    std::ostream& operator<<(std::ostream& out, const Process& process) {
        
        PRINT_PROCESS_LEFT(12, process.m_DebugName << ": on ");
        std::string limiter = "";
        switch (process.GetState()) {
            case Process::State::Done:
                limiter = " == ";
                break;
            case Process::State::Waiting:
                limiter = " .. ";
                break;
            default:
                limiter = " -> ";
                break;
        }
        PRINT_PROCESS_LEFT(3, std::to_string(process.QuantsInfo().StartFrom) << "| need ");
        PRINT_PROCESS_LEFT(3, std::to_string(process.QuantsInfo().Leftover) << "from");
        PRINT_PROCESS_RIGHT(3, std::to_string(process.QuantsInfo().Count) << limiter);
        PRINT_PROCESS_LEFT(4, std::to_string(process.GetAliveQuants()) << "[ ");
        PRINT_PROCESS_LEFT(9, Process::PriorityToString(process.GetPriority()));
        PRINT_PROCESS_RIGHT(8, Process::StateToString(process.GetState()) << " ]");
        return out;
    }
    
}
