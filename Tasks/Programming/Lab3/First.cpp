#include "First.hpp"

#include <stdexcept>

namespace Programming { namespace ThirdLab { namespace First {
    
    unsigned int MatrixVector::s_Amount = 0;
    
    Matrix::Matrix(double value) {
        for (int i = 0; i < 9; i++)
            m_Data[i] = i%4 ? 0 : value;
    }
    
    Matrix::Matrix(const Matrix& matrix) {
        for (int i = 0; i < 9; i++)
            m_Data[i] = matrix[i];
    }
    
    Matrix::Matrix(std::initializer_list<double> list) {
        if (list.size() != 9)
            throw std::out_of_range("matrix error");
        int i = 0;
        for (const auto& member : list)
            m_Data[i++] = member;
    }
    
    double& Matrix::operator[](int id) {
        if (id < 0 || id > 8)
            throw std::out_of_range("matrix error");
        return m_Data[id];
    }
    
    double Matrix::operator[](int id) const {
        if (id < 0 || id > 8)
            throw std::out_of_range("matrix error");
        return m_Data[id];
    }
    
    const Matrix Matrix::operator+(const Matrix& matrix) const {
        Matrix tmpMat;
        for (int i = 0; i < 9; i++)
            tmpMat[i] = m_Data[i] + matrix[i];
        return tmpMat;
    }
    
    const Matrix Matrix::operator+(double number) const {
        Matrix tmpMat;
        for (int i = 0; i < 9; i++)
            tmpMat[i] = m_Data[i] + (i%4 ? 1.0 : number);
        return tmpMat;
    }
    
    const Matrix Matrix::operator-(const Matrix& matrix) const {
        Matrix tmpMat;
        for (int i = 0; i < 9; i++)
            tmpMat[i] = m_Data[i] - matrix[i];
        return tmpMat;
    }
    
    const Matrix Matrix::operator-(double number) const {
        Matrix tmpMat;
        for (int i = 0; i < 9; i++)
            tmpMat[i] = m_Data[i] - (i%4 ? 1.0 : number);
        return tmpMat;
    }
    
    const Matrix Matrix::operator*(const Matrix& matrix) const {
        Matrix tmpMat;
        
        return tmpMat;
    }
    
    const Matrix Matrix::operator*(double number) const {
        Matrix tmpMat;
        for (int i = 0; i < 9; i++)
            tmpMat[i] = m_Data[i] * (i%4 ? 1.0 : number);
        return tmpMat;
    }
    
    const Matrix& Matrix::operator+=(const Matrix& matrix) {
        for (int i = 0; i < 9; i++)
            m_Data[i] += matrix[i];
        return *this;
    }
    
    const Matrix& Matrix::operator+=(double number) {
        for (int i = 0; i < 9; i++)
            m_Data[i] += i%4 ? 0.0 : number;
        return *this;
    }
    
    const Matrix& Matrix::operator-=(const Matrix& matrix) {
        for (int i = 0; i < 9; i++)
            m_Data[i] -= matrix[i];
        return *this;
    }
    
    const Matrix& Matrix::operator-=(double number) {
        for (int i = 0; i < 9; i++)
            m_Data[i] -= i%4 ? 0.0 : number;
        return *this;
    }
    
    const Matrix& Matrix::operator*=(const Matrix& matrix) {
        return *this;
    }
    
    const Matrix& Matrix::operator*=(double number) {
        return *this;
    }
    
    const Matrix& Matrix::operator=(const Matrix& matrix) {
        for (int i = 0; i < 9; i++)
            m_Data[i] = matrix[i];
        return *this;
    }
    
    const Matrix& Matrix::operator=(double number) {
        for (int i = 0; i < 9; i++)
            m_Data[i] = i%4 ? 0 : number;
        return *this;
    }
    
    double Matrix::GetSumDiag(void) const {
        double resultSum = 0;
        for (int i = 0; i < 9; i += 4)
            resultSum += m_Data[i];
        return resultSum;
    }
    
    
    
    Matrix& MatrixVector::operator[] (int id) {
        if (id < 0 || id > m_Data.size())
            throw std::out_of_range("matrix vector error");
        return m_Data[id];
    }
    
    const Matrix& MatrixVector::operator[] (int id) const {
        if (id < 0 || id > m_Data.size())
            throw std::out_of_range("matrix vector error");
        return m_Data[id];
    }
    
    MatrixVector MatrixVector::operator+(const MatrixVector& vector) const {
        MatrixVector resultVector;
        
        if (vector.GetSize() != this->GetSize()) {
            throw std::out_of_range("matrix vector error");
            return resultVector;
        }
        
        for (int i = 0; i < vector.GetSize(); i++)
            resultVector.push(m_Data[i] - vector[i]);
        
        return resultVector;
    }
    
    MatrixVector MatrixVector::operator-(const MatrixVector& vector) const {
        MatrixVector resultVector;
        
        if (vector.GetSize() != this->GetSize()) {
            throw std::out_of_range("matrix vector error");
            return resultVector;
        }
        
        for (int i = 0; i < vector.GetSize(); i++)
            resultVector.push(m_Data[i] + vector[i]);
        
        return resultVector;
    }
    
    const MatrixVector& MatrixVector::operator+=(const MatrixVector& vector) {
        if (vector.GetSize() != this->GetSize()) {
            throw std::out_of_range("matrix vector error");
            return *this;
        }
        
        for (int i = 0; i < vector.GetSize(); i++)
            m_Data[i] += vector[i];
        
        return *this;
    }
    
    const MatrixVector& MatrixVector::operator-=(const MatrixVector& vector) {
        if (vector.GetSize() != this->GetSize()) {
            throw std::out_of_range("matrix vector error");
            return *this;
        }
        
        for (int i = 0; i < vector.GetSize(); i++)
            m_Data[i] -= vector[i];
        
        return *this;
    }
    
    const MatrixVector& MatrixVector::operator=(const MatrixVector& vector) {
        m_Data.clear();
        
        for (const auto& matrix : vector)
            m_Data.push_back(matrix);
        
        return *this;
    }
    
    bool MatrixVector::operator>(const MatrixVector& vector) {
        bool isMore = false;
        if (m_Data.size() != vector.m_Data.size())
            throw std::out_of_range("matrix vector error");
        
        for (int i = 0; i < m_Data.size(); i++)
            if (!(isMore = m_Data[i].GetSumDiag() > vector[i].GetSumDiag()))
                return isMore;
                
        return isMore;
    }
    
    bool MatrixVector::operator<(const MatrixVector& vector) {
        bool isMore = false;
        if (m_Data.size() != vector.m_Data.size())
            throw std::out_of_range("matrix vector error");
        
        for (int i = 0; i < m_Data.size(); i++)
            if (!(isMore = m_Data[i].GetSumDiag() < vector[i].GetSumDiag()))
                return isMore;
                
        return isMore;
    }
    
    bool MatrixVector::operator>=(const MatrixVector& vector) {
        bool isMore = false;
        if (m_Data.size() != vector.m_Data.size())
            throw std::out_of_range("matrix vector error");
        
        for (int i = 0; i < m_Data.size(); i++)
            if (!(isMore = m_Data[i].GetSumDiag() >= vector[i].GetSumDiag()))
                return isMore;
                
        return isMore;
    }
    
    bool MatrixVector::operator<=(const MatrixVector& vector) {
        bool isMore = false;
        if (m_Data.size() != vector.m_Data.size())
            throw std::out_of_range("matrix vector error");
        
        for (int i = 0; i < m_Data.size(); i++)
            if (!(isMore = m_Data[i].GetSumDiag() >= vector[i].GetSumDiag()))
                return isMore;
                
        return isMore;
    }
    
    bool MatrixVector::operator==(const MatrixVector& vector) {
        bool isMore = false;
        if (m_Data.size() != vector.m_Data.size())
            throw std::out_of_range("matrix vector error");
        
        for (int i = 0; i < m_Data.size(); i++)
            if (!(isMore = m_Data[i].GetSumDiag() == vector[i].GetSumDiag()))
                return isMore;
                
        return isMore;
    }
    
    void Task::DoExample(void) {
        MatrixVector first;
        MatrixVector second;
        for (int i = 0; i < 5; i ++)
            first.push(Matrix(i));
        for (int i = 5; i < 10; i ++)
            second.push(Matrix(i));
        
        std::cout << "  Should be false = " << (first > second ? "true" : "false") << std::endl;
        std::cout << "  Should be true  = " << (second > first ? "true" : "false") << std::endl;
    }
    
} } }
