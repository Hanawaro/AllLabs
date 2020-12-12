#pragma once

#include <iostream>
#include <vector>

namespace Programming { namespace SixthLab { namespace First {
    
    template <typename Type>
    class DeepVector {
    public:
        DeepVector(void) = default;
        DeepVector(std::initializer_list<std::vector<Type>> data) : m_Data(data) {}
        DeepVector(const std::vector<std::vector<Type>>& data) : m_Data(data) {}
        ~DeepVector(void) = default;
        
        std::vector<Type>& operator[](int lineIndex) { return m_Data[lineIndex]; }
        const std::vector<Type>& operator[](int lineIndex) const { return m_Data[lineIndex]; }
        
        inline void push_line_back(std::initializer_list<Type> line) { m_Data.push_back(line); }
        inline void push_line_back(const std::vector<Type> line) { m_Data.push_back(line); }
        
        inline void pop_line_back(std::initializer_list<Type> line) { m_Data.pop_back(); }
        inline void pop_line_back(const std::vector<Type> line) { m_Data.pop_back(); }
        
        inline const std::vector<Type>& get_line(int lineIndex) const { return m_Data[lineIndex]; }
        
        inline void push_element_back(const Type& element, int index) { m_Data[index].push_back(element); }
        
        inline const Type& get_element(int lineIndex, int elementIndex) const { return m_Data[lineIndex][elementIndex]; }
        
        inline typename std::vector<std::vector<Type>>::iterator begin(void) { return m_Data.begin(); }
        inline typename std::vector<std::vector<Type>>::const_iterator begin(void) const { return m_Data.begin(); }

        inline typename std::vector<std::vector<Type>>::iterator end(void) { return m_Data.end(); }
        inline typename std::vector<std::vector<Type>>::const_iterator end(void) const { return m_Data.end(); }
        
        std::pair<unsigned, unsigned> find_max_index(void) const {
            if (!m_Data.size()) {
                throw "out of range";
                return {-1, -1};
            }
            int index = -1;
            for (int i = 0; i < m_Data.size(); i++)
                if (m_Data[i].size()) {
                    index = i;
                    break;
                }
            if (index == -1) {
                throw "out of range";
                return {-1, -1};
            }
            Type maximal = m_Data[index][0];
            std::pair<unsigned, unsigned> resultIndex = {0, 0};
            std::pair<unsigned, unsigned> realIndex = {0 ,0};
            for (const auto& line : m_Data) {
                for (const auto& element : line) {
                    if (element > maximal) {
                        resultIndex = realIndex;
                        maximal = element;
                    }
                    realIndex.second++;
                }
                realIndex.first++;
                realIndex.second = 0;
            }
            return resultIndex;
        }
        
        Type find_max(void) const {
            if (!m_Data.size())
                throw "out of range";
            int index = -1;
            for (int i = 0; i < m_Data.size(); i++)
                if (m_Data[i].size()) {
                    index = i;
                    break;
                }
            if (index == -1)
                throw "out of range";
                    
            Type maximal = m_Data[index][0];
            for (const auto& line : m_Data)
                for (const auto& element : line)
                    if (element > maximal)
                        maximal = element;
            return maximal;
        }
        
        void align(void) {
            size_t maximal = 0;
            for (const auto& line : m_Data)
                if (line.size() > maximal)
                    maximal = line.size();
            for (auto& line : m_Data)
                if (line.size() < maximal)
                    for (size_t i = line.size(); i < maximal; i++)
                        line.push_back(0);
        }
    private:
        std::vector<std::vector<Type>> m_Data;
    };
    
    template<typename Type>
    class Task {
    public:
        void DoExample(DeepVector<Type>& vec) {
            std::cout << " До: " << std::endl;
            print(vec);
            
            vec.align();
            
            std::cout << " После: " << std::endl;
            print(vec);
            
            auto index = vec.find_max_index();
            std::cout << " Максимальный элемент = "  << vec.find_max() << " [" << index.first << "][" << index.second << "]"<< std::endl;
            
        }
        
    private:
        void print(const DeepVector<Type>& vec) const {
            for (const auto& line : vec) {
                std::cout << "  ";
                for (const auto& element : line)
                    std::cout << element << " ";
                std::cout << std::endl;
            }
        }
    };
    
} } }
