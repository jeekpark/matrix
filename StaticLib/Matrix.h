#pragma once

#include <initializer_list>
#include <iostream>
#include <cstdint>
#include <cstring>

typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef float       f32;
typedef double      f64;

// Public API
namespace tk3
{
    template <class K, u64 N, u64 M>
    struct Matrix
    {
        K data[N * M];

        // API general
        Matrix();
        Matrix(const Matrix&);
        const Matrix& operator=(const Matrix&);
        Matrix(std::initializer_list<K>);
        ~Matrix();

        struct RowProxy
        {
            K* row;
            K& operator[](u64);
            const K& operator[](u64) const;
        };
        RowProxy operator[](u64);
        const RowProxy operator[](u64) const;
        void Print() const;

        // API ex00
        void Add(const Matrix&);
        void Sub(const Matrix&);
        void Scl(const Matrix&);
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
    Matrix<K, N, M>::Matrix()
    {
        std::memset(&data, 0, sizeof(data));
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M>::Matrix(const Matrix& copy)
    {
        std::memcpy(data, copy.data, sizeof(data));
    }

    template<class K, u64 N, u64 M>
    const Matrix<K, N, M>& Matrix<K, N, M>::operator=(const Matrix& copy)
    {
        if (&copy != this)
        {
            std::memcpy(data, copy.data, sizeof(data));
        }
        return *this;
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M>::Matrix(std::initializer_list<K> init)
    {
        std::copy(init.begin(), init.end(), data);
    }

    template<class K, u64 N, u64 M>
    Matrix<K, N, M>::~Matrix()
    {}


} // namespace tk3 | Impl general