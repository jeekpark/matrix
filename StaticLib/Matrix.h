#pragma once

#include <initializer_list>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "types.h"

// Public API
namespace tk3
{
    template <class K, u64 N, u64 M>
    struct Matrix
    {
        K data[N * M];

        // API general
        K* operator[](u64);
        const K* operator[](u64) const;
        void ConsolePrint() const;

        // API ex00
        void Add(const Matrix&);
        void Sub(const Matrix&);
        void Scl(const K&);
    };

    // API ex00
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator+(const Matrix<K, N, M>&, const Matrix<K, N, M>&);
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator-(const Matrix<K, N, M>&, const Matrix<K, N, M>&);
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator*(const Matrix<K, N, M>&, const K&);
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator*(const K&, const Matrix<K, N, M>&);

} // namespace tk3 | Public API

// Impl general
namespace tk3
{
    template<class K, u64 N, u64 M>
    K* Matrix<K, N, M>::operator[](u64 row)
    {
        return &data[M * row];
    }

    template<class K, u64 N, u64 M>
    const K* Matrix<K, N, M>::operator[](u64 row) const
    {
        return &data[M * row];
    }

    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::ConsolePrint() const
    {
        for (u64 n = 0; n < N; ++n)
        {
            for (u64 m = 0; m < M; ++m)
            {
                std::cout
                    << "["
                    << std::setw(5)
                    << (*this)[n][m]
                    << "]";
            }
            std::cout << std::endl;
        }
    }
} // namespace tk3 | Impl general

namespace tk3
{
    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::Add(const Matrix& rhs)
    {
        for (u64 n = 0; n < N; ++n)
        {
            for (u64 m = 0; m < M; ++m)
            {
                (*this)[n][m] += rhs[n][m];
            }
        }
    }

    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::Sub(const Matrix& rhs)
    {
        for (u64 n = 0; n < N; ++n)
        {
            for (u64 m = 0; m < M; ++m)
            {
                (*this)[n][m] -= rhs[n][m];
            }
        }
    }

    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::Scl(const K& scalar)
    {
        for (u64 n = 0; n < N; ++n)
        {
            for (u64 m = 0; m < M; ++m)
            {
                (*this)[n][m] *= scalar;
            }
        }
    }
} // namespace tk3 | Impl ex00