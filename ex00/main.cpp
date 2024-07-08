#include "Vector.h"

typedef f32 T;

int main()
{
    
    tk3::Vector<T, 3> A = { 1.1f, 2.2f, 3.3f };
    tk3::Vector<T, 3> B = { 1.1f, 2.2f, 3.3f };
    A.Print();
    
    A.Add(B);
    A.Print();
    
    A.Sub(B);
    A.Print();

    A.Scl(10);
    A.Print();

    std::cout << "A[0]: " << A[0] << std::endl;
    std::cout << "A[1]: " << A[1] << std::endl;
    std::cout << "A[2]: " << A[2] << std::endl;
    
    tk3::Vector<T, 3> C = A + B;
    C.Print();


    C = A - B;
    C.Print();

    C = A * 10.f;
    C.Print();

    C = 10.f * C;
    C.Print();
    return 0;
}