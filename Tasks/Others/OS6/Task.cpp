#include "Task.hpp"

namespace OS6 {
    
    static bool s_IsRunning = true;
    const unsigned int s_MaximalSize = 5;
    static std::mutex s_Mutex;
    static std::vector<char> s_Data;
    
    inline void PrintVector(void) {
        for (const auto& element : s_Data)
            std::cout << element << " ";
        std::cout << std::endl;
    }

    void consume(long long time) {
        while (s_IsRunning) {
            std::unique_lock<std::mutex> lock(s_Mutex);
            if (!s_Data.empty()) {
                s_Data.pop_back();
                std::cout <<"consumer "<< std::this_thread::get_id() << " :: ";
                PrintVector();
            }
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        };
    }

    void produce(long long time) {
        while (s_IsRunning) {
            std::unique_lock<std::mutex> lock(s_Mutex);
            if (s_Data.size() <= s_MaximalSize) {
                s_Data.push_back('*');
                std::cout << "producer " << std::this_thread::get_id() << " :: ";
                PrintVector();
            }
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }
    };
    
    void Task::DoExample(void) {
        std::thread t1(produce, 100);
        std::thread t2(consume, 200);
        std::thread t3(consume, 100);
        
        if(std::cin.get())
            s_IsRunning = false;
        
        t1.join();
        t2.join();
        t3.join();
    }
    
}
