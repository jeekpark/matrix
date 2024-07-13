#include "Vector.h"
#include "Matrix.h"
#include <type_traits>

using T = tk3::f32;
constexpr auto TTYPE = ("float");

int main()
{
    std::cout << "\n||||| Test for Vector |||||\n" << std::endl;

    std::cout << std::boolalpha;
    std::cout << "Is Vector<K, N> POD?: " << std::is_pod<tk3::Vector<T, 3>>::value << "\n\n";

    tk3::Vector<T, 3> A = { 1.f, 2.f, 3.f };
    tk3::Vector<T, 3> B = { .5f, .5f, .5f };
    std::cout << "Vector<" << TTYPE << ", 3> A = { 1.f, 2.f, 3.f };\n";
    std::cout << "Vector<" << TTYPE << ", 3> B = { .5f, .5f, .5f };\n\n";
    std::cout << "A Layout: \n";
    A.PrintLayout();
    std::cout << '\n';
    std::cout << "B Layout: \n";
    B.PrintLayout();
    std::cout << "\n\n";

    A.Add(B);
    A.PrintLayout();
    
    A.Sub(B);
    A.PrintLayout();

    A.Scl(10);
    A.PrintLayout();

    std::cout << "A[0]: " << A[0] << std::endl;
    std::cout << "A[1]: " << A[1] << std::endl;
    std::cout << "A[2]: " << A[2] << std::endl;
    
    tk3::Vector<T, 3> C = A + B;
    C.PrintLayout();


    C = A - B;
    C.PrintLayout();

    C = A * 10.f;
    C.PrintLayout();

    C = 10.f * C;
    C.PrintLayout();

    std::cout << "\n||||| End             |||||\n" << std::endl;

    std::cout << "\n||||| Test for Matrix |||||" << std::endl;
    tk3::Matrix<T, 3, 3> matrixA = {
        1.f, 2.f, 3.f,
        4.f, 5.f, 6.f,
        7.f, 8.f, 9.f
    };

    tk3::Matrix<T, 3, 3> matrixB = {
        1.f, 2.f, 3.f,
        4.f, 5.f, 6.f,
        7.f, 8.f, 9.f
    };
    
    std::cout << "\nmatrixA:" << std::endl;
    matrixA.ConsolePrint();

    std::cout << "\nmatrixB:" << std::endl;
    matrixB.ConsolePrint();

    std::cout << "\nmatrixA.Add(matrixB): " << std::endl;
    matrixA.Add(matrixB);
    matrixA.ConsolePrint();

    std::cout << "\nmatrixA.Sub(matrixB): " << std::endl;
    matrixA.Sub(matrixB);
    matrixA.ConsolePrint();

    std::cout << "\nmatrixA.Scl(3.14f): " << std::endl;
    matrixA.Scl(3.14f);
    matrixA.ConsolePrint();
    
    
    return 0;
}
