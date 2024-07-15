#include "Vector.h"
#include "utils.h"

int main()
{
    std::vector<tk3::Vector<float, 2>> arrV = {
        tk3::Vector<float, 2>({ 1, 2 }),
        tk3::Vector<float, 2>({ 3, 4 })
    };

    std::vector<float> arrS = { 2, 3 };
    
    tk3::Vector<float, 2> res = tk3::Vector<float, 2>::LinearCombination(arrV, arrS);

    std::cout << "선형결합\n예상: [   11][   16]\n결과: ";

    printLayout(res);
    return 0;
}
