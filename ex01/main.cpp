#include "Vector.h"
#include "utils.h"

int main()
{
    std::vector<tk3::Vector<float, 2>> arrV;
    arrV.push_back(tk3::Vector<float, 2>({ 1, 2 }));
    arrV.push_back(tk3::Vector<float, 2>({ 3, 4 }));
    std::vector<float> arrS;
    arrS.push_back(2);
    arrS.push_back(3);
    arrS.push_back(4);

    tk3::Vector<float, 2> res = tk3::Vector<float, 2>::LinearCombination(arrV, arrS);

    printLayout(res);
    return 0;
}
