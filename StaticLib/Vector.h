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

// API
namespace tk3
{
    template <class K, u64 N>
    struct Vector
    {
        K data[N];

        // API general
        Vector();
        Vector(const Vector&);
        const Vector& operator=(const Vector&);
        Vector(std::initializer_list<K>);
        ~Vector();

        K& operator[](u64);
        K operator[](u64) const;
        void PrintLog() const;

        // API ex00
        void Add(const Vector&);
        void Sub(const Vector&);
        void Scl(const K&);

    };
} // namespace tk3

// Impl general
namespace tk3
{
    template <class K, u64 N>
    Vector<K, N>::Vector()
    {
        std::memset(&data, 0, sizeof(data));
    }

    template <class K, u64 N>
    Vector<K, N>::Vector(const Vector& copy)
        : data(copy.data)
    {}

    template <class K, u64 N>
    const Vector<K, N>& Vector<K, N>::operator=(const Vector& copy)
    {
        if (&copy != this)
        {
            data = copy.data;
        }
        return this;
    }

    template <class K, u64 N>
    Vector<K, N>::Vector(std::initializer_list<K> init)
    {
        std::memset(&data, 0, sizeof(data));
        u64 i = 0;
        for (auto it = init.begin(); it != init.end() && i < N; ++it, ++i)
        {
            data[i] = *it;
        }
    }

    template <class K, u64 N>
    Vector<K, N>::~Vector()
    {}

    template <class K, u64 N>
    K& Vector<K, N>::operator[](u64 index)
    {
        return data[index];
    }

    template <class K, u64 N>
    K Vector<K, N>::operator[](u64 index) const
    {
        return data[index];
    }

    template <class K, u64 N>
    void Vector<K, N>::PrintLog() const
    {
        std::cout << N << "D Vector ( ";
        for (u64 i = 0; i < N - 1; ++i)
        {
            std::cout << data[i] << ", ";
        }
        std::cout << data[N - 1] << " )" << std::endl;
    }
} // namespace tk3 | Impl general

// Impl ex00
namespace tk3
{
    template <class K, u64 N>
    void Vector<K, N>::Add(const Vector& rhs)
    {
        for (u64 i = 0; i < N; ++i)
        {
            data[i] += rhs.data[i];
        }
    }

    template <class K, u64 N>
    void Vector<K, N>::Sub(const Vector& rhs)
    {
        for (u64 i = 0; i < N; ++i)
        {
            data[i] -= rhs.data[i];
        }
    }

    template <class K, u64 N>
    void Vector<K, N>::Scl(const K& scalar)
    {
        for (u64 i = 0; i < N; ++i)
        {
            data[i] *= scalar;
        }
    }
} // namespace tk3 | Impl ex00