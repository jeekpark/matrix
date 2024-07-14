#include "Vector.h"
#include "Matrix.h"
#include <type_traits>

using T = tk3::f32;
constexpr auto TTYPE = ("float");

int main()
{
    std::cout << "\n||||| Test for Vector |||||\n" << std::endl;

    {
        // 1. POD 구현 여부
        std::cout << "--------------------------\n";
        std::cout << std::boolalpha;
        std::cout << "1. Vector 구조체 POD 여부\n";
        std::cout << "std::is_pod<tk3::Vector<T, 3>>::value -> ";
        std::cout << std::is_pod<tk3::Vector<T, 3>>::value << "\n";
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 2. Vector 생성
        std::cout << "--------------------------\n";
        std::cout << "2. Vector 생성\n";
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

        // 3. Add 누산 함수
        std::cout << "--------------------------\n";
        std::cout << "3. Add 누산 함수\n";
        std::cout << "A.Add(B);\n\n";
        A.Add(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 4. Sub 누산 함수
        std::cout << "--------------------------\n";
        std::cout << "4. Sub 누산 함수\n";
        std::cout << "A.Sub(B);\n\n";
        A.Sub(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";


        // 5. Scl 누산 함수
        std::cout << "--------------------------\n";
        std::cout << "5. Scl 누산 함수\n";
        std::cout << "A.Scl(3.14f);\n\n";
        A.Scl(3.14f);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 6. Add 순수 함수 (+연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "6. Add 순수 함수 (+연산자 오버로드)\n";
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

        // 7. Sub 순수 함수 (-연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "7. Sub 순수 함수 (-연산자 오버로드)\n";
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

        // 8. Scl 순수 함수 (*연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "8. Scl 순수 함수 (*연산자 오버로드)\n";
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

        // 9. Scl 순수 함수 2 (*연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "9. Scl 순수 함수 2 (*연산자 오버로드)\n";
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
        // 1. POD 구현 여부
        std::cout << "--------------------------\n";
        std::cout << std::boolalpha;
        std::cout << "1. Matrix 구조체 POD 여부\n";
        std::cout << "std::is_pod<tk3::Vector<T, 3, 3>>::value -> ";
        std::cout << std::is_pod<tk3::Matrix<T, 3, 3>>::value << "\n";
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 2. Matrix 생성
        std::cout << "--------------------------\n";
        std::cout << "2. Matrix 생성\n";
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

        // 3. Add 누산 함수
        std::cout << "--------------------------\n";
        std::cout << "3. Add 누산 함수\n";
        std::cout << "A.Add(B);\n\n";
        A.Add(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 4. Sub 누산 함수
        std::cout << "--------------------------\n";
        std::cout << "4. Sub 누산 함수\n";
        std::cout << "A.Sub(B);\n\n";
        A.Sub(B);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << '\n';
        std::cout << "B Layout: \n";
        B.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";


        // 5. Scl 누산 함수
        std::cout << "--------------------------\n";
        std::cout << "5. Scl 누산 함수\n";
        std::cout << "A.Scl(3.14f);\n\n";
        A.Scl(3.14f);
        std::cout << "A Layout: \n";
        A.PrintLayout();
        std::cout << "--------------------------\n";
        std::cout << "\n\n\n";

        // 6. Add 순수 함수 (+연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "6. Add 순수 함수 (+연산자 오버로드)\n";
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

        // 7. Sub 순수 함수 (-연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "7. Sub 순수 함수 (-연산자 오버로드)\n";
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

        // 8. Scl 순수 함수 (*연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "8. Scl 순수 함수 (*연산자 오버로드)\n";
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

        // 9. Scl 순수 함수 2 (*연산자 오버로드)
        std::cout << "--------------------------\n";
        std::cout << "9. Scl 순수 함수 2 (*연산자 오버로드)\n";
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
