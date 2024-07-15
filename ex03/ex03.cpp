#include "Vector.h"
#include "utils.h"

int main()
{
    tk3::Vector<float, 3> A = {};
    tk3::Vector<float, 3> B = {};


    A = { 1.f, 0.f, 0.f };
    B = { 1.f, 0.f, 0.f };

    std::cout << "���� ����(0��)\n\n"
        << "A = { 1.f, 0.f, 0.f };\n"
        << "B = { 1.f, 0.f, 0.f };\n"
        << "����: 1\n"
        << "���: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    A = { 1.f, 0.f, 0.f };
    B = { 0.f, 1.f, 0.f };

    std::cout << "���� ����(90��)\n\n"
        << "A = { 1.f, 0.f, 0.f };\n"
        << "B = { 0.f, 1.f, 0.f };\n"
        << "����: 0\n"
        << "���: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    A = { 1.f, 0.f, 0.f };
    B = { -1.f, 0.f, 0.f };

    std::cout << "���� ����(180��)\n\n"
        << "A = { 1.f, 0.f, 0.f };\n"
        << "B = { -1.f, 0.f, 0.f };\n"
        << "����: -1\n"
        << "���: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    A = { 3.f, 0.f, 0.f };
    B = { 7.f, 0.f, 0.f };

    std::cout << "���� ����(���� ������ �� ���� ũ���� ��)\n\n"
        << "A = { 3.f, 0.f, 0.f };\n"
        << "B = { 7.f, 0.f, 0.f };\n"
        << "����: 21\n"
        << "���: " << tk3::Vector<float, 3>::DotProduct(A, B) << "\n\n\n";

    
    return 0;
}