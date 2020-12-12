#include "ProcessManager.hpp"

namespace OS5 {
    
    void ProcessManager::SetRandomData(std::vector<Process>& processes, std::vector<Process>::size_type count) {
        
        const std::string prefixDebugName = "Process_";
        
        std::string debugName = "";
        unsigned int countQuants = 0;
        unsigned int startFromQuants = 0;
        Process::Priority priority = Process::Priority::Low;
        
        for (size_t i = 0; i < count; i++) {
            debugName = prefixDebugName + std::to_string(i + 1);
            countQuants = rand()%(s_MaximalCount - s_MinimalCount) + s_MinimalCount;
            startFromQuants = rand()%(s_MaximalStartCount - s_MinimalStartCount) + s_MinimalStartCount;
            priority = static_cast<Process::Priority>(rand()%static_cast<int>(Process::Priority::Count));
            
            processes.push_back(Process(debugName, Process::Quants(startFromQuants, countQuants), priority));
        }
    }
    
    void ProcessManager::ReadUserData(std::vector<Process>& processes, std::vector<Process>::size_type count) {
        for (size_t i = 0; i < count; i++) {
            // TO DO
        }
    }
    
    void ProcessManager::Info(const Process& process) {
        std::cout << " " << process.GetDebugName() << std::endl;
        std::cout << "  Время прибывания = " << process.GetAliveQuants() << std::endl;
        std::cout << "  Потерянное время = " << process.GetAliveQuants() - process.QuantsInfo().Count << std::endl;
        std::cout << "  Отношение реактивности = " << (float) process.QuantsInfo().Count / process.GetAliveQuants() << std::endl;
        std::cout << "  Штрафное отношение = " << (float) process.GetAliveQuants() / process.QuantsInfo().Count << std::endl;
    }
    
    bool ProcessManager::IsDone(const vec::iterator& start, const vec::iterator& last) {
        for (auto it = start; it != last; it++) {
            if (it->GetState() != Process::State::Done)
                return false;
        }
        return true;
    }
    
    ProcessManager::vec::iterator ProcessManager::GetReadyFirst(const vec::iterator& start, const vec::iterator& last, unsigned ticks) {
        for (auto it = start; it < last; it++) {
            if (it->GetState() != Process::State::Done) {
                if (ticks >= it->QuantsInfo().StartFrom) {
                    return it;
                } else {
                    return last;
                }
            }
        }
        return last;
    }
    
}
