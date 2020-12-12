#pragma once

#include <iostream>
#include <vector>

namespace SAOD { namespace FirstLab { namespace First {
    
    class Task {
        using vec = std::vector<double>;
    public:
        struct QuickData {
        public:
            struct Size { unsigned first = 0, second = 0, third = 0; };
        public:
            QuickData(void) = default;
            QuickData(const vec& d, const Size& s) : data(d), size(s) {}
            
            inline void push_first(double value)  { data.emplace(data.begin() + size.first++, value); }
            inline void push_second(double value) { data.emplace(data.begin() + size.second++, value); }
            inline void push_third(double value)  { data.emplace(data.begin() + size.third++, value); }
            
            inline vec& get_vec(void) { return data; }
            inline const vec& get_vec(void) const { return data; }
            
            inline const Size& get_size(void) const { return size; }
        private:
            vec data;
            Size size;
        };
        
        struct SlowData {
        public:
            SlowData(void) = default;
            SlowData(const vec& f, const vec& s, const vec& t) : first(f), second(s), third(t) {}
            
            inline void push_first(double value)  { first.push_back(value); }
            inline void push_second(double value) { second.push_back(value); }
            inline void push_third(double value)  { third.push_back(value); }
            
            inline vec& get_first(void)  { return first; }
            inline vec& get_second(void) { return second; }
            inline vec& get_third(void)  { return third; }
            
            inline const vec& get_first(void) const  { return first; }
            inline const vec& get_second(void) const { return second; }
            inline const vec& get_third(void) const  { return third; }
        private:
            vec first;
            vec second;
            vec third;
        };
    public:
        void DoWork(QuickData& data);
        void DoWork(SlowData& data);
    private:
        void Sort(QuickData& data);
        void Sort(SlowData& data);
        
        void Print(const QuickData& data);
        void Print(const SlowData& data);
    };
    
} } }
