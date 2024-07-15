#include "Vector.h"
#include "utils.h"

int main()
{
    tk3::Vector<float, 3> A = {};
    tk3::Vector<float, 3> B = {};


    A = { 1.f, 0.f, 0.f };
    B = { 1.f, 0.f, 0.f };

    std::cout << "벡터 내적(0도)\n\n"
        << "A = { 1.f, 0.f, 0.f };\n"
        << "B = { 1.f, 0.f, 0.f };\n"
        << "예상: 1\n"
        << "결과: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    A = { 1.f, 0.f, 0.f };
    B = { 0.f, 1.f, 0.f };

    std::cout << "벡터 내적(90도)\n\n"
        << "A = { 1.f, 0.f, 0.f };\n"
        << "B = { 0.f, 1.f, 0.f };\n"
        << "예상: 0\n"
        << "결과: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    A = { 1.f, 0.f, 0.f };
    B = { -1.f, 0.f, 0.f };

    std::cout << "벡터 내적(180도)\n\n"
        << "A = { 1.f, 0.f, 0.f };\n"
        << "B = { -1.f, 0.f, 0.f };\n"
        << "예상: -1\n"
        << "결과: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    A = { 3.f, 0.f, 0.f };
    B = { 7.f, 0.f, 0.f };

    std::cout << "벡터 내적(같은 방향은 두 벡터 크기의 곱)\n\n"
        << "A = { 3.f, 0.f, 0.f };\n"
        << "B = { 7.f, 0.f, 0.f };\n"
        << "예상: 21\n"
        << "결과: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    
    return 0;
}