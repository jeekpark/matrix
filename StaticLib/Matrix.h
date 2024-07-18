#pragma once

#include <iostream>
#include <iomanip>

#include "types.h"

// Decl
namespace tk3
{
    template <class K, u64 N, u64 M>
    struct Matrix
    {
        K data[N][M];

        // API general
        K(&operator[](u64))[M];
        const K(&operator[](u64) const)[M];

        // API ex00
        void Add(const Matrix&);
        void Sub(const Matrix&);
        void Scl(const K&);

        // API ex02
        static Matrix LinearInterpolation(const Matrix&, const Matrix&, f32);

        // API ex07
        template<u64 P>
        static Matrix<K, N, P> Multiplication(const Matrix<K, N, M>&, const Matrix<K, M, P>&);
    };
    
    // API general
    template<class K, u64 N, u64 M>
    void printLayout(const Matrix<K, N, M>& matrix);

    // API ex00
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator+(const Matrix<K, N, M>&, const Matrix<K, N, M>&);
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator-(const Matrix<K, N, M>&, const Matrix<K, N, M>&);
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator*(const Matrix<K, N, M>&, const K&);
    template <class K, u64 N, u64 M>
    Matrix<K, N, M> operator*(const K&, const Matrix<K, N, M>&);

} // namespace tk3 | Decl

// Impl general
namespace tk3
{
    template<class K, u64 N, u64 M>
    K(&Matrix<K, N, M>::operator[](u64 row))[M]
    {
        return reinterpret_cast<K(&)[M]>(data[row]);
    }

    template<class K, u64 N, u64 M>
    const K(&Matrix<K, N, M>::operator[](u64 row) const)[M]
    {
        return reinterpret_cast<const K(&)[M]>(data[row]);
    }

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

// Impl ex02
namespace tk3
{
    template<class K, u64 N, u64 M>
    Matrix<K, N, M> Matrix<K, N, M>::LinearInterpolation(const Matrix& a, const Matrix& b, f32 time)
    {
        return a + (b - a) * time;
    }
} // namespace tk3 | Impl ex02

// Impl ex07
namespace tk3
{
    template<class K, u64 N, u64 M>
    template<u64 P>
    Matrix<K, N, P> Matrix<K, N, M>::Multiplication(const Matrix<K, N, M>& a, const Matrix<K, M, P>& b)
    {
        Matrix<K, N, P> res;
        for (u64 i = 0; i < N; ++i)
        {
            for (u64 j = 0; j < P; ++j)
            {
                res[i][j] = K();
                for (u64 k = 0; k < M; ++k)
                {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
}