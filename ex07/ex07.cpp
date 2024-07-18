#include "Matrix.h"

using namespace tk3;

int main()
{
    Matrix<float, 2, 2> A;
    Matrix<float, 2, 2> B;
    Matrix<float, 2, 2> C;

    A = {
        1.f, 0.f,
        0.f, 1.f
    };

    B = {
        1.f, 0.f,
        0.f, 1.f
    };

    C = Matrix<float, 2, 2>::Multiplication(A, B);

    printLayout(C);

    std::cout << "\n\n";
    A = {
        1.f, 0.f,
        0.f, 1.f
    };

    B = {
        2.f, 1.f,
        4.f, 2.f
    };

    C = Matrix<float, 2, 2>::Multiplication(A, B);

    printLayout(C);

    std::cout << "\n\n";
    A = {
        3.f, -5.f,
        6.f, 8.f
    };

    B = {
        2.f, 1.f,
        4.f, 2.f
    };

    C = Matrix<float, 2, 2>::Multiplication(A, B);

    printLayout(C);
}