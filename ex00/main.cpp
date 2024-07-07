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

    return 0;
}