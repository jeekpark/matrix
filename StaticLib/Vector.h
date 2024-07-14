#pragma once

#include <initializer_list>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "types.h"

// Public API
namespace tk3
{
    template <class K, u64 N>
    struct Vector
    {
        K data[N];

        // API general
        K& operator[](u64);
        K operator[](u64) const;
        void PrintLayout() const;

        // API ex00
        void Add(const Vector&);
        void Sub(const Vector&);
        void Scl(const K&);
    };

    // API ex00
    template <class K, u64 N>
    Vector<K, N> operator+(const Vector<K, N>&, const Vector<K, N>&);
    template <class K, u64 N>
    Vector<K, N> operator-(const Vector<K, N>&, const Vector<K, N>&);
    template <class K, u64 N>
    Vector<K, N> operator*(const Vector<K, N>&, const K&);
    template <class K, u64 N>
    Vector<K, N> operator*(const K&, const Vector<K, N>&);

} // namespace tk3 | Public API

// Impl general
namespace tk3
{
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
    void Vector<K, N>::PrintLayout() const
    {
        for (u64 n = 0; n < N; ++n)
        {

            std::cout
                << "["
                << std::setw(5)
                << (*this)[n]
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