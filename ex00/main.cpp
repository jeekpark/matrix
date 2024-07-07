#include "Vector.h"

typedef f32 T;

int main()
{
    
    tk3::Vector<T, 3> A = { 1.f, 2.f, 3.f };
    tk3::Vector<T, 3> B = { 1.f, 2.f, 3.f };
    A.PrintLog();
    
    A.Add(B);
    A.PrintLog();
    
    A.Sub(B);
    A.PrintLog();

    A.Scl(10);
    A.PrintLog();

    std::cout << "A[0]: " << A[0] << std::endl;
    std::cout << "A[1]: " << A[1] << std::endl;
    std::cout << "A[2]: " << A[2] << std::endl;
    
    tk3::Vector<T, 3> C = (A + B);
    C.PrintLog();

    C = A - B;
    C.PrintLog();
    return 0;
}