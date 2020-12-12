#pragma once

#include "../../../Reader.hpp"

namespace Programming { namespace FirstLab { namespace Third {
    
    class Task {
    public:
        struct Array {
            uint32_t size;
            int left;
            int right;
        };
    public:
        Task(void) = default;
        virtual ~Task(void) = default;
        
        void Start(Array array);
    private:
        void Init(const Array& array);
        void Compare(void) const;
        void GeometricMean(void) const;
    private:
        uint32_t m_Size;
        std::unique_ptr<int[]> m_Array;
    };
    
} } }
