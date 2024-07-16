#include "Vector.h"

int main()
{
    tk3::Vector<float, 3> A = {};

    A = { 1.f, 2.f, 3.f };

    std::cout << "������ �븧(L1 ����ź)\n\n"
        << "A = { 1.f, 2.f, 3.f }\n"
        << "����: 6\n"
        << "�ᱫ: " << tk3::Vector<float, 3>::NormManhattan(A)
        << "\n\n\n";

    std::cout << "������ �븧(L2 ��Ŭ����)\n\n"
        << "A = { 1.f, 2.f, 3.f }\n"
        << "����: 3.74165738\n"
        << "�ᱫ: " << tk3::Vector<float, 3>::NormEuclidean(A)
        << "\n\n\n";

    std::cout << "������ �븧(L_inf �ִ�)\n\n"
        << "A = { 1.f, 2.f, 3.f }\n"
        << "����: 3\n"
        << "�ᱫ: " << tk3::Vector<float, 3>::NormSupremum(A)
        << "\n\n\n";
    return 0;
}
