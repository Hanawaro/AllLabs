#pragma once

#include <iostream>

namespace OS5 {
    
    class Process {
        friend std::ostream& operator<<(std::ostream& out, const Process& process);
    public:
        enum class Priority {
            Critical,
            High,
            Medium,
            Low,
            Count
        };
        
        enum class State {
            Waiting,
            Making,
            Done,
            Count
        };
        
        struct Quants {
            unsigned int StartFrom;
            unsigned int Count;
            unsigned int Leftover;
            
            Quants(unsigned startFrom = 0, unsigned count = 0)
                : StartFrom(startFrom), Count(count), Leftover(Count) {}
        };
    public:
        Process(const std::string& name = "EmptyProcess", const Quants& quants = Quants(), Priority priority = Priority::Low, State state = State::Waiting)
            : m_DebugName(name), m_Quants(quants), m_Priority(priority), m_State(state) {}
        ~Process(void) = default;
        
        Process& operator++(void) { m_AliveQuants++; return *this; }
        Process& operator++(int) { auto& tmp = *this; ++(*this); return tmp; }
        
        inline const std::string& GetDebugName(void) const { return m_DebugName; }
        inline void SetDebugName(const std::string& name) { m_DebugName = name; }
        
        inline Quants& QuantsInfo(void) { return m_Quants; }
        inline const Quants& QuantsInfo(void) const { return m_Quants; }
        
        inline unsigned int GetAliveQuants(void) const { return m_AliveQuants; }
        inline void SetAliveQuants(unsigned int count) { m_AliveQuants = count; }
        
        inline Priority GetPriority(void) const { return m_Priority; }
        inline void SetPriority(Priority priority) { m_Priority = priority; }
        
        inline State GetState(void) const { return m_State; }
        inline void SetState(State state) { m_State = state; }
        
        static inline std::string PriorityToString(Priority priority);
        static inline std::string StateToString(State state);
    private:
        std::string m_DebugName;
        Quants m_Quants;
        unsigned int m_AliveQuants = 0;
        Priority m_Priority;
        State m_State;
    };
    
}
