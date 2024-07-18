#pragma once

#include <cassert>
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>

#include "types.h"
#include "utils.h"
// Decl
namespace tk3
{
    template <class K, u64 N>
    struct Vector
    {
        K data[N];

        // API general
        K& operator[](u64);
        const K& operator[](u64) const;

        // API ex00
        void Add(const Vector&);
        void Sub(const Vector&);
        void Scl(const K&);

        // API ex01
        static Vector LinearCombination(const std::vector<Vector>&, const std::vector<K>&);

        // API ex02
        static Vector LinearInterpolation(const Vector&, const Vector&, f32);

        // API ex03
        static K DotProduct(const Vector&, const Vector&);

        // API ex04
        static f32 NormManhattan(const Vector&);
        static f32 NormEuclidean(const Vector&);
        static f32 NormSupremum(const Vector&);

        // API ex05
        static f32 CosineTheta(const Vector&, const Vector&);

        // API ex06
        static Vector<K, 3> CrossProduct(const Vector<K, 3>&, const Vector<K, 3>&);
    };

    // API general
    template<class K, u64 N>
    void printLayout(const Vector<K, N>&);

    // API ex00
    template <class K, u64 N>
    Vector<K, N> operator+(const Vector<K, N>&, const Vector<K, N>&);
    template <class K, u64 N>
    Vector<K, N> operator-(const Vector<K, N>&, const Vector<K, N>&);
    template <class K, u64 N>
    Vector<K, N> operator*(const Vector<K, N>&, const K&);
    template <class K, u64 N>
    Vector<K, N> operator*(const K&, const Vector<K, N>&);

    
} // namespace tk3 | Decl

// Impl general
namespace tk3
{
    template <class K, u64 N>
    K& Vector<K, N>::operator[](u64 index)
    {
        return data[index];
    }

    template <class K, u64 N>
    const K& Vector<K, N>::operator[](u64 index) const
    {
        return data[index];
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

    template<class K, u64 N>
    Vector<K, N> operator+(const Vector<K, N>& left, const Vector<K, N>& right)
    {
        Vector<K, N> res(left);
        res.Add(right);
        return res;
    }

    template<class K, u64 N>
    Vector<K, N> operator-(const Vector<K, N>& left, const Vector<K, N>& right)
    {
        Vector<K, N> res(left);
        res.Sub(right);
        return res;
    }

    template<class K, u64 N>
    Vector<K, N> operator*(const Vector<K, N>& left, const K& scalar)
    {
        Vector<K, N> res(left);
        res.Scl(scalar);
        return res;
    }

    template<class K, u64 N>
    Vector<K, N> operator*(const K& scalar, const Vector<K, N>& right)
    {
        Vector<K, N> res(right);
        res.Scl(scalar);
        return res;
    }
} // namespace tk3 | Impl ex00

// Impl ex01
namespace tk3
{
    template<class K, u64 N>
    Vector<K, N> Vector<K, N>::LinearCombination(const std::vector<Vector>& vectors, const std::vector<K>& scalars)
    {
        assert(vectors.size() == scalars.size());
        Vector<K, N> res = {};

        for (u64 i = 0; i < vectors.size(); ++i)
        {
            res.Add(vectors[i] * scalars[i]);
        }
        return res;
    }
} // namespace tk3 | Impl ex01

// Impl ex02
namespace tk3
{
    template<class K, u64 N>
    Vector<K, N> Vector<K, N>::LinearInterpolation(const Vector& u, const Vector& v, f32 time)
    {
        return u + (v - u) * time;
    }
} // namespace tk3 | Impl ex02

// Impl ex03
namespace tk3
{
    template<class K, u64 N>
    K  Vector<K, N>::DotProduct(const Vector& u, const Vector& v)
    {
        K res = K();
        for (u64 i = 0; i < N; ++i)
        {
            res = res + (u.data[i] * v.data[i]);
        }
        return res;
    }
} // namespace tk3 | Impl ex03

// Impl ex04
namespace tk3
{
    template<class K, u64 N>
    f32 Vector<K, N>::NormManhattan(const Vector& vector)
    {
        f32 res = f32();
        for (int i = 0; i < N; ++i)
        {
            res = res + (vector[i] < 0 ? -vector[i] : vector[i]);
        }
        return res;
    }

    template<class K, u64 N>
    f32 Vector<K, N>::NormEuclidean(const Vector& vector)
    {
        f32 res = f32();
        for (int i = 0; i < N; ++i)
        {
            res = res + (vector[i] * vector[i]);
        }
        return tk3::sqrtf(res);
    }

    template<class K, u64 N>
    f32 Vector<K, N>::NormSupremum(const Vector& vector)
    {
        f32 res = f32();
        for (int i = 0; i < N; ++i)
        {
            res = (tk3::abs(vector[i]) > res) ? tk3::abs(vector[i]) : res;
        }
        return res;
    }
} // namespace tk3 | Impl ex04

// Impl ex05
namespace tk3
{
    template<class K, u64 N>
    f32 Vector<K, N>::CosineTheta(const Vector& lhs, const Vector& rhs)
    {
        return Vector<K, N>::DotProduct(lhs, rhs) /
            (Vector<K, N>::NormEuclidean(lhs) * Vector<K, N>::NormEuclidean(rhs));
    }
} // namespace tk3 | Impl ex05

// Impl ex06
namespace tk3
{
    template<class K, u64 N>
    Vector<K, 3> Vector<K, N>::CrossProduct(const Vector<K, 3>& lhs, const Vector<K, 3>& rhs)
    {
        return {
            lhs[1] * rhs[2] - lhs[2] * rhs[1],
            lhs[2] * rhs[0] - lhs[0] * rhs[2],
            lhs[0] * rhs[1] - lhs[1] * rhs[0],
        };
    }
} // namespace tk3 | Impl ex06
