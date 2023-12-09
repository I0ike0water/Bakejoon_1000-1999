// 백준 1049 기타줄.cpp

#include <iostream>

int main()
{
    int line = 0; int store = 0;
    int min_x = 1000; int min_6 = 1000;
    std::cin >> line >> store;

    int x = line % 6;

    for (int i = 0; i < store; i++) {
        int six = 0; int one = 0;
        std::cin >> six >> one;
        if (min_6 > six) min_6 = six;
        if (min_6 > one * 6) min_6 = one * 6;
        if (min_x > one * x) min_x = one * x;
    }
    int divide = line / 6;

    if (min_6 < min_x) std::cout << (divide + 1) * min_6;
    else {
        std::cout << divide * min_6 + min_x;
    }
    return 0;
}
