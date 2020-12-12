#include "FB.hpp"

namespace OS5 {
    
    void FB::DoAlgorigth(std::vector<Process>& processes) {
        using namespace std::chrono;
        
        const unsigned int processTicks = 5;
        unsigned int totalTicks = 0;
        auto dequeLimiter = processes.end();
        
        ProcessContainer::SetData(&processes, &dequeLimiter);

        ProcessContainer::Log(" Начальные процессы:");
        
        auto start = high_resolution_clock::now();
        
        while (!ProcessManager::IsDone(processes.begin(), processes.end())) {
            for (auto it = processes.begin(); it != dequeLimiter; it++) {
                SetProcessTicks(*it, processTicks, totalTicks);
            }
            if (ProcessManager::IsDone(processes.begin(), dequeLimiter)) {
                for (auto it = dequeLimiter; it != processes.end(); it++) {
                    SetProcessTicks(*it, processTicks, totalTicks);
                }
            }
            for (auto it = processes.begin(); it != dequeLimiter; it++) {
                if (it->GetState() != Process::State::Done) {
                    it->SetState(Process::State::Waiting);
                    std::rotate(it, it + 1, processes.end());
                    dequeLimiter--;
                    it--;
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        
        ProcessContainer::Log(" Результат:");
        
        Conclusion(processes, duration_cast<milliseconds>(end - start).count());
    }
    
    void FB::SetProcessTicks(Process& process, unsigned int ticks, unsigned int& totalTicks) {
        switch (process.GetState()) {
            case Process::State::Waiting:
            {
                for (unsigned int& i = totalTicks; i < process.QuantsInfo().StartFrom && ticks > 0; i++, ticks--) {
                    Tick();
                    ProcessContainer::Log(" Процессы после тика:");
                }
                if (!ticks)
                    return;
            }
            case Process::State::Making:
            {
                process.SetState(Process::State::Making);
                while ( ticks-- > 0 ) {
                    totalTicks++;
                    
                    if ( --process.QuantsInfo().Leftover == 0 ) {
                        process.SetState(Process::State::Done);
                        Tick();
                        ProcessContainer::Log(" Процессы после тика:");
                        return;
                    } else {
                        Tick();
                        ProcessContainer::Log(" Процессы после тика:");
                    }
                }
                process.SetState(Process::State::Waiting);
                break;
            }
            default:
                break;
        }
            
        
    }
    
    inline void FB::Conclusion(const std::vector<Process>& processes, long long time) {
        std::cout << " Подведение итогов:" << std::endl;
        std::cout << "  Время на выполнение процессов = " << time / 1000.0f << "s"<< std::endl;
        for (const auto& process : processes)
            ProcessManager::Info(process);
    }
    
    inline void FB::Tick(void) {
        auto& processes = *ProcessContainer::GetProcesses();
        for (auto it = processes.begin(); it != processes.end(); it++) {
            if (it->GetState() != Process::State::Done)
                (*it)++;
        }
    }
    
}
