#pragma once

#include <vector>
#include <iostream>

namespace Programming { namespace ThirdLab { namespace First {
    
    struct Matrix {
    public:
        Matrix(double value = 0);
        Matrix(const Matrix& matrix);
        Matrix(std::initializer_list<double> list);
        ~Matrix(void) = default;
        
        double operator[](int id) const;
        double& operator[](int id);
        
        const Matrix operator+(const Matrix& matrix) const;
        const Matrix operator+(double number) const;
        const Matrix operator-(const Matrix& matrix) const;
        const Matrix operator-(double number) const;
        const Matrix operator*(const Matrix& matrix) const;
        const Matrix operator*(double number) const;
        
        const Matrix& operator+=(const Matrix& matrix);
        const Matrix& operator+=(double number);
        const Matrix& operator-=(const Matrix& matrix);
        const Matrix& operator-=(double number);
        const Matrix& operator*=(const Matrix& matrix);
        const Matrix& operator*=(double number);
        
        const Matrix& operator=(const Matrix& matrix);
        const Matrix& operator=(double number);
        
        double GetSumDiag(void) const;
    private:
        double m_Data[9];
    };
    
    class MatrixVector {
    public:
        MatrixVector(void) { s_Amount++; }
        ~MatrixVector(void) { s_Amount--; }
        
        Matrix& operator[] (int id);
        const Matrix& operator[] (int id) const;
        
        MatrixVector operator+(const MatrixVector& vector) const;
        MatrixVector operator-(const MatrixVector& vector) const;
        
        const MatrixVector& operator+=(const MatrixVector& vector);
        const MatrixVector& operator-=(const MatrixVector& vector);
        
        const MatrixVector& operator=(const MatrixVector& vector);
        
        bool operator>(const MatrixVector& vector);
        bool operator<(const MatrixVector& vector);
        
        bool operator>=(const MatrixVector& vector);
        bool operator<=(const MatrixVector& vector);
        
        bool operator==(const MatrixVector& vector);
        
        inline void push(const Matrix& matrix) { m_Data.push_back(matrix); }
        inline void pop(void) { return m_Data.pop_back(); }
        
        inline std::vector<Matrix>::size_type GetSize(void) const { return m_Data.size(); }
        static inline unsigned int GetCount(void) { return s_Amount; }
        
        inline std::vector<Matrix>::iterator begin(void) { return m_Data.begin(); }
        inline std::vector<Matrix>::iterator end(void) { return m_Data.end(); }
        inline std::vector<Matrix>::const_iterator begin(void) const { return m_Data.begin(); }
        inline std::vector<Matrix>::const_iterator end(void) const { return m_Data.end(); }
    private:
        std::vector<Matrix> m_Data;
        static unsigned int s_Amount;
    };
    
    class Task {
    public:
        void DoExample(void);
    };
    
} } }
