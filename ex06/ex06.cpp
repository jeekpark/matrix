#include "Vector.h"

int main()
{
    {
        tk3::Vector<float, 3> A = {};
        tk3::Vector<float, 3> B = {};
        tk3::Vector<float, 3> C = {};

        A = { 0.f, 0.f, 1.f };
        B = { 1.f, 0.f, 0.f };

        std::cout << "3차원 벡터의 외적\n\n"
            << "A = { 0.f, 0.f. 1.f };\n"
            << "B = { 1.f, 0.f, 0.f };\n"
            << "예상: [    0][    1][    0]\n"
            << "결과: ";
        C = tk3::Vector<float, 3>::CrossProduct(A, B);
        printLayout(C);
        std::cout << "\n\n\n";

        A = { 1.f, 2.f, 3.f };
        B = { 4.f, 5.f, 6.f };

        std::cout << "3차원 벡터의 외적\n\n"
            << "A = { 1.f, 2.f, 3.f };\n"
            << "B = { 4.f, 5.f, 6.f };\n"
            << "예상: [   -3][    6][   -3]\n"
            << "결과: ";
        C = tk3::Vector<float, 3>::CrossProduct(A, B);
        printLayout(C);
        std::cout << "\n\n\n";

        A = { 4.f, 2.f, -3.f };
        B = { -2.f, -5.f, 16.f };

        std::cout << "3차원 벡터의 외적\n\n"
            << "A = { 4.f, 2.f, -3.f };\n"
            << "B = { -2.f, -5.f, 16.f };\n"
            << "예상: [   17][  -58][  -16]\n"
            << "결과: ";
        C = tk3::Vector<float, 3>::CrossProduct(A, B);
        printLayout(C);
        std::cout << "\n\n\n";
    }

    return 0;
}
