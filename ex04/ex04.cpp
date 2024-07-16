#include "Vector.h"

int main()
{
    tk3::Vector<float, 3> A = {};

    A = { 1.f, 2.f, 3.f };

    std::cout << "º¤ÅÍÀÇ ³ë¸§(L1 ¸ÇÇÏÅº)\n\n"
        << "A = { 1.f, 2.f, 3.f }\n"
        << "¿¹»ó: 6\n"
        << "°á±«: " << tk3::Vector<float, 3>::NormManhattan(A)
        << "\n\n\n";

    std::cout << "º¤ÅÍÀÇ ³ë¸§(L2 À¯Å¬¶óµð¾È)\n\n"
        << "A = { 1.f, 2.f, 3.f }\n"
        << "¿¹»ó: 3.74165738\n"
        << "°á±«: " << tk3::Vector<float, 3>::NormEuclidean(A)
        << "\n\n\n";

    std::cout << "º¤ÅÍÀÇ ³ë¸§(L_inf ÃÖ´ë)\n\n"
        << "A = { 1.f, 2.f, 3.f }\n"
        << "¿¹»ó: 3\n"
        << "°á±«: " << tk3::Vector<float, 3>::NormSupremum(A)
        << "\n\n\n";
    return 0;
}
