#include "Second.hpp"

namespace Programming { namespace FirstLab { namespace Second {
 
    void Task::DoRand(uint32_t size, int left, int right) {
        m_File.open(m_Path);
        
        m_Vector.resize(size);
        
        std::cout << std::endl;
        m_File << "Оригинальный вектор: " << std::endl;
        for (int i = 0; i < m_Vector.size(); i++) {
            std::cout << "  vector[" << i << "] = " << (m_Vector[i] = rand()%(right - left) + left) << std::endl;
            m_File << " vector[" << i << "] = " << (m_Vector[i] = rand()%(right - left) + left) << std::endl;
        }

        DoSort();
        DoTask();
        FinishTask();
    }

    void Task::DoHand(void) {
        m_File.open(m_Path);
        int size = 0;
        readData<int>(size, "  Введите размер вектора: ", "   Неверный размер вектора", [](int data) { return data > 0; } );
        
        m_Vector.resize(size);
        
        for (int i = 0; i < m_Vector.size(); i++) {
            std::cout << "  vector[" << i << "] = ";
            std::cin >> m_Vector[i];
            m_File << " vector[" << i << "] = " << m_Vector[i] << std::endl;
        }
        
        DoSort();
        Task();
        FinishTask();
    }

    void Task::DoFile(const std::string& name) {
        m_File.open(m_Path);
        std::ifstream file(name);
        
        if (file.is_open()) {
            int size = 0;
            file >> size;

            if (size <= 0) {
                std::cout << "  Некорректные размеры вектора" << std::endl;
                std::cout << size << std::endl;
                return;
            }
            
            m_Vector.resize(size);
            
            for (int i = 0; i < m_Vector.size(); i++) {
                file >> m_Vector[i];
                std::cout << "  vector[" << i << "] = " << m_Vector[i] << std::endl;
                m_File << " vector[" << i << "] = " << m_Vector[i] << std::endl;
            }
            
            DoSort();
            Task();
            FinishTask();
            
        } else {
            std::cout << " Не удалось открыть файл" << std::endl;
            m_File.close();
        }
    }

    void Task::DoSort(void) {
        std::sort(m_Vector.begin(), m_Vector.end());
        
        std::cout << "\n Отсортированный вектор: " << std::endl;
        m_File << "\nОтсортированный вектор: " << std::endl;
        
        for (int i = 0; i < m_Vector.size(); i++) {
            std::cout << "  vector[" << i << "] = " << m_Vector[i] << std::endl;
            m_File << " vector[" << i << "] = " << m_Vector[i] << std::endl;
        }
    }

    void Task::DoTask(void) {
        for (int i = 0; i < m_Vector.size(); i++) {
            if (m_Vector[i] < 0)
                m_Vector.erase(m_Vector.begin() + i--);
        }
        std::cout << "\n Отредактированный вектор: " << std::endl;
        m_File << "\nОтредактированный вектор: " << std::endl;
        
        for (int i = 0; i < m_Vector.size(); i++) {
            std::cout << "  vector[" << i << "] = " << m_Vector[i] << std::endl;
            m_File << " vector[" << i << "] = " << m_Vector[i] << std::endl;
        }
    }

    void Task::FinishTask(void) {
        m_File.close();
    }
    
} } }
