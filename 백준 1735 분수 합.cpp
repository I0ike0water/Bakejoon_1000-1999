// 백준 1735 분수 합.cpp

#include <iostream>

int main()
{
    int top1 = 0; int bot1 = 0;
    int top2 = 0; int bot2 = 0;
    std::cin >> top1 >> bot1 >> top2 >> bot2;

    int result_top = top1 * bot2 + top2 * bot1;
    int result_bot = bot1 * bot2;

    for (int i = 2; i <= result_bot && i <= result_top; i++) {
        while (result_bot % i == 0 && result_top % i == 0) {
            result_bot /= i; result_top /= i;
        }
    }

    std::cout << result_top << ' ' << result_bot;
    return 0;
}


/*
2 3
4 6
->
4 3

2 4
1 3
->
5 6

3 3
3 3
-> 2 1

2 1
4 2
-> 4 1

1 20
1 5
-> 1 4
*/