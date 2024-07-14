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
        K& operator()(u64, u64);
        const K& operator()(u64, u64) const;
        void PrintLayout() const;

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
    K& Matrix<K, N, M>::operator()(u64 row, u64 col)
    {
        return data[row * N + col];
    }

    template<class K, u64 N, u64 M>
    const K& Matrix<K, N, M>::operator()(u64 row, u64 col) const
    {
        return data[row * N + col];
    }

    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::PrintLayout() const
    {
        for (u64 n = 0; n < N; ++n)
        {
            for (u64 m = 0; m < M; ++m)
            {
                std::cout
                    << "["
                    << std::setw(5)
                    << data[n * M + m]
                    << "]";
            }
            std::cout << std::endl;
        }
    }
} // namespace tk3 | Impl general

// Impl ex00
namespace tk3
{
    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::Add(const Matrix& rhs)
    {
        for (u64 i = 0; i < N * M; ++i)
        {
            data[i] += rhs.data[i];
        }
    }

    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::Sub(const Matrix& rhs)
    {
        for (u64 i = 0; i < N * M; ++i)
        {
            data[i] -= rhs.data[i];
        }
    }

    template<class K, u64 N, u64 M>
    void Matrix<K, N, M>::Scl(const K& scalar)
    {
        for (u64 i = 0; i < N * M; ++i)
        {
            data[i] *= scalar;
        }
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M> operator+(const Matrix<K, N, M>& left, const Matrix<K, N, M>& right)
    {
        Matrix<K, N, M> res(left);
        res.Add(right);
        return res;
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M> operator-(const Matrix<K, N, M>& left, const Matrix<K, N, M>& right)
    {
        Matrix<K, N, M> res(left);
        res.Sub(right);
        return res;
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M> operator*(const Matrix<K, N, M>& left, const K& scalar)
    {
        Matrix<K, N, M> res(left);
        res.Scl(scalar);
        return res;
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M> operator*(const K& scalar, const Matrix<K, N, M>& right)
    {
        Matrix<K, N, M> res(right);
        res.Scl(scalar);
        return res;
    }
} // namespace tk3 | Impl ex00