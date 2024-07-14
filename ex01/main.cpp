#include <iostream>
#include <chrono>

template <class K, std::size_t N, std::size_t M>
struct Matrix1
{
    K data[N * M];

    K& operator()(std::size_t y, std::size_t x)
    {
        return data[y * M + x];
    }

    const K& operator()(std::size_t y, std::size_t x) const
    {
        return data[y * M + x];
    }
};

#include <cstddef>

template <class K, std::size_t N, std::size_t M>
struct Matrix2
{
    K data[N * M];

    struct RowProxy
    {
        K* row;
        K& operator[](std::size_t x)
        {
            return row[x];
        }

        const K& operator[](std::size_t x) const
        {
            return row[x];
        }
    };

    RowProxy operator[](std::size_t y)
    {
        return RowProxy{ data + y * M };
    }

    const RowProxy operator[](std::size_t y) const
    {
        return RowProxy{ data + y * M };
    }
};

int main()
{
    const std::size_t iterations = 10000000;
    Matrix1<int, 100, 100> mat1;
    Matrix2<int, 100, 100> mat2;

    auto start = std::chrono::high_resolution_clock::now();
    for (std::size_t i = 0; i < iterations; ++i)
    {
        mat1(i % 100, (i / 100) % 100) = i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end - start;
    std::cout << "operator() duration: " << duration1.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    for (std::size_t i = 0; i < iterations; ++i)
    {
        mat2[i % 100][(i / 100) % 100] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end - start;
    std::cout << "operator[] duration: " << duration2.count() << " seconds\n";

    return 0;
}
