#pragma once

#include <iostream>
#include <cstdint>

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

namespace tk3
{
    template <class K, u64 N>
    struct Vector
    {
        K data[N];

        u64 Size()
        {
            return N;
        }

        void Add(const Vector& rhs)
        {
            for (u64 i = 0; i < N; ++i)
            {
                data[i] += rhs.data[i];
            }
        }

        void Sub(const Vector& rhs)
        {
            for (u64 i = 0; i < N; ++i)
            {
                data[i] -= rhs.data[i];
            }
        }

        void Scl(const K& scalar)
        {
            for (u64 i = 0; i < N; ++i)
            {
                data[i] *= scalar;
            }
        }

        void PrintLog()
        {
            std::cout << N << "D Vector ( ";
            for (u64 i = 0; i < N - 1; ++i)
            {
                std::cout << data[i] << ", ";
            }
            std::cout << data[N - 1] << " )" << std::endl;
        }
    };
}