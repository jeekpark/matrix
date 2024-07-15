#include "Vector.h"
#include "utils.h"
int main()
{
    tk3::Vector<float, 3> A = { 1.f,2.f,3.f };
    printLayout(A);
}