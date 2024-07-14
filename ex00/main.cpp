#include "Vector.h"
#include "Matrix.h"
#include <type_traits>

using T = tk3::f32;
constexpr auto TTYPE = ("float");

int main()
{
    std::cout << "\n||||| Test for Vector |||||\n" << std::endl;

    {
        // 1. POD ���� ����
        std::cout << "--------------------------\n";
        std::cout << std::boolalpha;
        std::cout << "1. Vector ����ü POD ����\n";
        std::cout << "std::is_pod<tk3::Vector<T, 3>>::value -> ";
        std::cout << std::is_pod<tk3::Vector<T, 3>>::value << "\n";
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 2. Vector ����
        std::cout << "--------------------------\n";
        std::cout << "2. Vector ����\n";
        tk3::Vector<T, 3> A = { 1.f, 2.f, 3.f };
        tk3::Vector<T, 3> B = { .5f, .5f, .5f };
        std::cout << "Vector<" << TTYPE << ", 3> A = { 1.f, 2.f, 3.f };\n";
        std::cout << "Vector<" << TTYPE << ", 3> B = { .5f, .5f, .5f };\n\n";
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 3. Add ���� �Լ�
        std::cout << "--------------------------\n";
        std::cout << "3. Add ���� �Լ�\n";
        std::cout << "A.Add(B);\n\n";
        A.Add(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 4. Sub ���� �Լ�
        std::cout << "--------------------------\n";
        std::cout << "4. Sub ���� �Լ�\n";
        std::cout << "A.Sub(B);\n\n";
        A.Sub(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";


        // 5. Scl ���� �Լ�
        std::cout << "--------------------------\n";
        std::cout << "5. Scl ���� �Լ�\n";
        std::cout << "A.Scl(3.14f);\n\n";
        A.Scl(3.14f);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 6. Add ���� �Լ� (+������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "6. Add ���� �Լ� (+������ �����ε�)\n";
        tk3::Vector<T, 3> C = A + B;
        std::cout << "C = A + B;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 7. Sub ���� �Լ� (-������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "7. Sub ���� �Լ� (-������ �����ε�)\n";
        C = A - B;
        std::cout << "C = A - B;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 8. Scl ���� �Լ� (*������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "8. Scl ���� �Լ� (*������ �����ε�)\n";
        C = A * 100.f;
        std::cout << "C = A * 100.f;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 9. Scl ���� �Լ� 2 (*������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "9. Scl ���� �Լ� 2 (*������ �����ε�)\n";
        C = 100.f * A;
        std::cout << "C = 100.f * A;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
    }
    std::cout << "\n||||| Test for Vector End |||||\n\n\n" << std::endl;

    std::cout << "\n||||| Test for Matrix |||||" << std::endl;
    {
        // 1. POD ���� ����
        std::cout << "--------------------------\n";
        std::cout << std::boolalpha;
        std::cout << "1. Matrix ����ü POD ����\n";
        std::cout << "std::is_pod<tk3::Vector<T, 3, 3>>::value -> ";
        std::cout << std::is_pod<tk3::Matrix<T, 3, 3>>::value << "\n";
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 2. Matrix ����
        std::cout << "--------------------------\n";
        std::cout << "2. Matrix ����\n";
        tk3::Matrix<T, 3, 3> A = {
            1.f, 2.f, 3.f,
            4.f, 5.f, 6.f,
            7.f, 8.f, 9.f
        };
        tk3::Matrix<T, 3, 3> B = {
            .5f, .5f, .5f,
            .5f, .5f, .5f,
            .5f, .5f, .5f
};
        std::cout << "Matrix<" << TTYPE << ", 3, 3> A = {\n"
            << "    1.f, 2.f, 3.f,\n"
            << "    4.f, 5.f, 6.f,\n"
            << "    7.f, 8.f, 9.f\n"
            << "};\n";
        std::cout << "Matrix<" << TTYPE << ", 3, 3> B = {\n"
            << "    .5f, .5f, .5f,\n"
            << "    .5f, .5f, .5f,\n"
            << "    .5f, .5f, .5f\n"
            << "};\n";
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 3. Add ���� �Լ�
        std::cout << "--------------------------\n";
        std::cout << "3. Add ���� �Լ�\n";
        std::cout << "A.Add(B);\n\n";
        A.Add(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 4. Sub ���� �Լ�
        std::cout << "--------------------------\n";
        std::cout << "4. Sub ���� �Լ�\n";
        std::cout << "A.Sub(B);\n\n";
        A.Sub(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";


        // 5. Scl ���� �Լ�
        std::cout << "--------------------------\n";
        std::cout << "5. Scl ���� �Լ�\n";
        std::cout << "A.Scl(3.14f);\n\n";
        A.Scl(3.14f);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 6. Add ���� �Լ� (+������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "6. Add ���� �Լ� (+������ �����ε�)\n";
        tk3::Matrix<T, 3, 3> C = A + B;
        std::cout << "C = A + B;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 7. Sub ���� �Լ� (-������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "7. Sub ���� �Լ� (-������ �����ε�)\n";
        C = A - B;
        std::cout << "C = A - B;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 8. Scl ���� �Լ� (*������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "8. Scl ���� �Լ� (*������ �����ε�)\n";
        C = A * 100.f;
        std::cout << "C = A * 100.f;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 9. Scl ���� �Լ� 2 (*������ �����ε�)
        std::cout << "--------------------------\n";
        std::cout << "9. Scl ���� �Լ� 2 (*������ �����ε�)\n";
        C = 100.f * A;
        std::cout << "C = 100.f * A;\n\n";
        std::cout << "C Layout: \n";
        C.PrintLayout();
        std::cout << '\n';
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n";
    }
    std::cout << "\n||||| Test for Matrix End |||||\n\n\n" << std::endl;
    
    return 0;
}
