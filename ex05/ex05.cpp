#include "Vector.h"

int main()
{
    {
        tk3::Vector<float, 2> A = {};
        tk3::Vector<float, 2> B = {};

        A = { 1.f, 0.f };
        B = { 1.f, 0.f };

        std::cout << "코사인 각\n\n"
            << "A = { 1.f, 0.f };\n"
            << "B = { 1.f, 0.f };\n"
            << "예상: 1.0\n"
            << "결과: " << tk3::Vector<float, 2>::CosineTheta(A, B)
            << "\n\n\n";

        A = { 1.f, 0.f };
        B = { 0.f, 1.f };

        std::cout << "코사인 각\n\n"
            << "A = { 1.f, 0.f };\n"
            << "B = { 0.f, 1.f };\n"
            << "예상: 0.0\n"
            << "결과: " << tk3::Vector<float, 2>::CosineTheta(A, B)
            << "\n\n\n";

        A = { -1.f, 1.f };
        B = { 1.f, -1.f };

        std::cout << "코사인 각\n\n"
            << "A = { -1.f, 1.f };\n"
            << "B = { 1.f, -1.f };\n"
            << "예상: -1.0\n"
            << "결과: " << tk3::Vector<float, 2>::CosineTheta(A, B)
            << "\n\n\n";

        A = { 2.f, 1.f };
        B = { 4.f, 2.f };

        std::cout << "코사인 각\n\n"
            << "A = { 2.f, 1.f };\n"
            << "B = { 4.f, 2.f };\n"
            << "예상: 1.0\n"
            << "결과: " << tk3::Vector<float, 2>::CosineTheta(A, B)
            << "\n\n\n";
    }

    {
        tk3::Vector<float, 3> A = {};
        tk3::Vector<float, 3> B = {};

        A = { 1.f, 2.f, 3.f };
        B = { 4.f, 5.f, 6.f };

        std::cout << "코사인 각\n\n"
            << "A = { 1.f, 2.f, 3.f };\n"
            << "A = { 1.f, 2.f, 3.f };\n"
            << "예상: 0.974631846\n"
            << "결과: " << tk3::Vector<float, 3>::CosineTheta(A, B)
            << "\n\n\n";

        
    }

    return 0;
}
