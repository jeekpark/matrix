#include <iostream>
#include "Vector.h"

int main()
{
    std::cout << "hello" << std::endl;

    tk3::Vector<f32, 3> test = { 1.f, 2.f, 3.f };
    tk3::Vector<f32, 3> test2 = { 1.f, 2.f, 3.f };

    test.Add(test2);
    test.PrintLog();


}