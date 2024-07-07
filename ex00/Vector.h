#pragma once

#include <iostream>

#include "common.h"

namespace tk3
{
    template <class K, u64 N>
    struct Vector
    {
        K mData[N];
        
        u64 Size()
        {
            return N;
        }

        void Add(const Vector& rhs)
        {
            for (u64 i = 0; i < N; ++i)
            {
                mData[i] += rhs.mData[i];
            }
        }
        
        void PrintLog()
        {
            std::cout << N << "D Vector ( ";
            for (u64 i = 0; i < N - 1; ++i)
            {
                std::cout << mData[i] << ", ";
            }
            std::cout << mData[N - 1] << " )" << std::endl;
        }
    };
}