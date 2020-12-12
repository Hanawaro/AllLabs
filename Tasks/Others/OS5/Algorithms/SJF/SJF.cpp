#include "SJF.hpp"

namespace OS5 {

    static inline void Log(const std::string& title, const std::vector<Process>& processes) {
        std::cout << title << std::endl;
        for (const auto& process : processes)
            std::cout << "  " << process << std::endl;
        std::cout << std::endl;
    }
    
    void SJF::DoAlgorigth(std::vector<Process>& processes) {
        using namespace std::chrono;
        std::sort(processes.begin(), processes.end(), [](Process& f, Process& s) { return f.QuantsInfo().Count < s.QuantsInfo().Count; });
        
        Log(" Начальные процессы:", processes);
        
        auto start = high_resolution_clock::now();
        
        unsigned int ticks = 0;
        while (!ProcessManager::IsDone(processes.begin(), processes.end())) {
            auto it = ProcessManager::GetReadyFirst(processes.begin(), processes.end(), ticks);
            if (it != processes.end()) {
                it->SetState(Process::State::Making);
                for (unsigned int quant = 0; quant < it->QuantsInfo().Count; quant++) {
                    Tick(processes);
                    Log(" Процессы после тика:", processes);
                    ticks++;
                }
                it->SetState(Process::State::Done);
            } else {
                Tick(processes);
                Log(" Процессы после тика:", processes);
                ticks++;
            }
        }
        auto end = high_resolution_clock::now();
        
        Log(" Результат:", processes);
        
        Conclusion(processes, duration_cast<milliseconds>(end - start).count());
    }
    
    inline void SJF::Conclusion(const std::vector<Process>& processes, long long time) {
        std::cout << " Подведение итогов:" << std::endl;
        std::cout << "  Время на выполнение процессов = " << time / 1000.0f << "s"<< std::endl;
        for (const auto& process : processes) 
            ProcessManager::Info(process);
    }
    
    inline void SJF::Tick(std::vector<Process>& processes) {
        for (auto& process : processes)
            if (process.GetState() != Process::State::Done)
                process++;
    }
    
}
