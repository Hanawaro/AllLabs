#include "First.hpp"

#include <fstream>

namespace Programming { namespace FirstLab { namespace First {

    void Task::DoRand(uint32_t size, int left, int right) {
        m_File.open(m_Path);
        m_Size = size;
        m_DynamicArray = new int[m_Size];
        
        std::cout << std::endl;
        m_File << "Оригинальный массив: " << std::endl;
        for (int i = 0; i < m_Size; i++) {
            std::cout << "  dynamicArary[" << i << "] = " << (m_DynamicArray[i] = rand()%(right - left) + left) << std::endl;
            m_File << " dynamicArary[" << i << "] = " << (m_DynamicArray[i] = rand()%(right - left) + left) << std::endl;
        }
        
        DoSort();
        DoTask();
        FinishTask();
    }
    
    void Task::DoHand(void) {
        m_File.open(m_Path);
        int size = 0;
        readData<int>(size, "  Введите размер массива: ", "   Неверный размер массива", [](int data) { return data > 0; } );
        
        m_Size = size;
        
        m_DynamicArray = new int[m_Size];
        
        for (int i = 0; i < m_Size; i++) {
            std::cout << "  dynamicArray[" << i << "] = ";
            std::cin >> m_DynamicArray[i];
            m_File << " dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
        }
        
        DoSort();
        DoTask();
        FinishTask();
    }
    
    void Task::DoFile(const std::string& name) {
        m_File.open(m_Path);
        std::ifstream file(name);
        
        if (file.is_open()) {
            int size = 0;
            file >> size;
            
            if (size <= 0) {
                std::cout << "  Некорректные размеры массива" << std::endl;
                std::cout << size << std::endl;
                return;
            }
            
            m_Size = size;
            
            m_DynamicArray = new int[m_Size];
            for (int i = 0; i < m_Size; i++) {
                file >> m_DynamicArray[i];
                std::cout << "  dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
                m_File << " dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
            }
            
            DoSort();
            DoTask();
            FinishTask();
            
            m_File.close();
        } else {
            std::cout << " Не удалось открыть файл" << std::endl;
        }
    }
    
    void Task::DoSort(void) {
        for (uint32_t i = 0; i < m_Size - 1; i++) {
            int smallest = i;
            for (int j = i + 1; j < m_Size; j++) {
                if (m_DynamicArray[j] < m_DynamicArray[smallest])
                    smallest = j;
            }
            std::swap(m_DynamicArray[i], m_DynamicArray[smallest]);
        }
        
        std::cout << "\n Отсортированный массив: " << std::endl;
        m_File << "\nОтсортированный массив: " << std::endl;
        
        for (int i = 0; i < m_Size; i++) {
            std::cout << "  dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
            m_File << " dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
        }
    }
    
    void Task::DoTask(void) {
        int* tmpArray = new int[m_Size];
        int tmpSize = 0;
        for (int i = 0; i < m_Size; i++) {
            if (m_DynamicArray[i] >= 0)
                tmpArray[tmpSize++] = m_DynamicArray[i];
        }
        delete[] m_DynamicArray;
        m_DynamicArray = tmpArray;
        m_Size = tmpSize;
        
        std::cout << "\n Отредактированный массив: " << std::endl;
        m_File << "\nОтредактированный массив: " << std::endl;
        
        for (int i = 0; i < m_Size; i++) {
            std::cout << "  dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
            m_File << " dynamicArray[" << i << "] = " << m_DynamicArray[i] << std::endl;
        }
    }
    
    void Task::FinishTask(void) {
        m_File.close();
        delete[] m_DynamicArray;
    }

} } }
