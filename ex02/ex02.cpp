#include "Vector.h"
#include "Matrix.h"
#include "utils.h"

int main()
{
    {
        std::cout << "벡터 선형보간\n";

        tk3::Vector<float, 2> A = { 2, 2 };
        tk3::Vector<float, 2> B = { 4, 4 };
        std::cout << "A:\n";
        printLayout(A);
        std::cout << "\n";

        std::cout << "B:\n";
        printLayout(B);
        std::cout << "\n";



        tk3::Vector<float, 2> res = {};

        std::cout << "LinearInterpolation(A, B, 0.f):\n";
        printLayout(tk3::Vector<float, 2>::LinearInterpolation(A, B, 0.f));
        std::cout << "\n";

        std::cout << "LinearInterpolation(A, B, .5f):\n";
        printLayout(tk3::Vector<float, 2>::LinearInterpolation(A, B, .5f));
        std::cout << "\n";

        std::cout << "LinearInterpolation(A, B, 1.f):\n";
        printLayout(tk3::Vector<float, 2>::LinearInterpolation(A, B, 1.f));
        std::cout << "\n";

        std::cout << "LinearInterpolation(A, B, 2.f):\n";
        printLayout(tk3::Vector<float, 2>::LinearInterpolation(A, B, 2.f));
        std::cout << "\n";
    }
    {
        std::cout << "\n\n\n\n\n행렬 선형보간\n";

        tk3::Matrix<float, 2, 2> A = { 2, 2, 2, 2 };
        tk3::Matrix<float, 2, 2> B = { 4, 4, 4, 4 };
        std::cout << "A:\n";
        printLayout(A);
        std::cout << "\n";

        std::cout << "B:\n";
        printLayout(B);
        std::cout << "\n";



        tk3::Matrix<float, 2, 2> res = {};

        std::cout << "LinearInterpolation(A, B, 0.f):\n";
        printLayout(tk3::Matrix<float, 2, 2>::LinearInterpolation(A, B, 0.f));
        std::cout << "\n";

        std::cout << "LinearInterpolation(A, B, .5f):\n";
        printLayout(tk3::Matrix<float, 2, 2>::LinearInterpolation(A, B, .5f));
        std::cout << "\n";

        std::cout << "LinearInterpolation(A, B, 1.f):\n";
        printLayout(tk3::Matrix<float, 2, 2>::LinearInterpolation(A, B, 1.f));
        std::cout << "\n";

        std::cout << "LinearInterpolation(A, B, 2.f):\n";
        printLayout(tk3::Matrix<float, 2, 2>::LinearInterpolation(A, B, 2.f));
        std::cout << "\n";
    }
}