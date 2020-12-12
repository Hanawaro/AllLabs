#include "Third.hpp"

#include <cmath>

namespace Programming { namespace FirstLab { namespace Third {
    
    void Task::Start(Array array) {
        Init(array);
        Compare();
        GeometricMean();
    }

    void Task::Init(const Array& array) {
        m_Size = array.size;
        m_Array.reset(new int[m_Size]);
        std::cout << std::endl;
        for (int i = 0; i < m_Size; i++)
            std::cout << "  array[" << i << "] = " << (m_Array[i] = rand()%(array.right - array.left) + array.left) << std::endl;
        std::cout << std::endl;
    }

    void Task::Compare(void) const {
        int sumEven = 0;
        int sumOdd = 0;
        
        for (int i = 0; i < m_Size; i ++) {
            sumEven += (i % 2 == 0) ? m_Array[i] : 0;
            sumOdd  += (i % 2 != 0) ? m_Array[i] : 0;
        }
        
        std::cout << "  Сумма четный ( |" << abs(sumEven) << "| ) " << (abs(sumEven) > abs(sumOdd) ? "больше" : "меньше")
                  << " суммы нечетных ( |" << abs(sumOdd) << "| )" << std::endl;
    }

    void Task::GeometricMean(void) const {
        double power = 1;
        for (int i = 0; i < m_Size; i++)
            power *= m_Array[i];
        power = pow(abs(power), 1.0/m_Size) * (power < 0 ? -1 : 1);
        std::cout << "  Среднее геоментрическое равно " << power << std::endl;
    }

} } }
