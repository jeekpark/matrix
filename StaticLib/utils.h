#pragma once

#include <iostream>
#include <iomanip>

#include "Matrix.h"
#include "Vector.h"

namespace tk3
{
    template<class K, u64 N, u64 M>
    void printLayout(const Matrix<K, N, M>& matrix)
    {
        for (u64 n = 0; n < N; ++n)
        {
            for (u64 m = 0; m < M; ++m)
            {
                std::cout
                    << "["
                    << std::setw(5)
                    << matrix[n][m]
                    << "]";
            }
            std::cout << std::endl;
        }
    }

    template<class K, u64 N>
    void printLayout(const Vector<K, N>& vector)
    {
        for (u64 n = 0; n < N; ++n)
        {
            std::cout
                << "["
                << std::setw(5)
                << vector[n]
                << "]";

        }
        std::cout << std::endl;
    }
}