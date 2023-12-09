// 백준 1735 분수 합(유클리드 호제법).cpp

#include <iostream>

int gcd(int a, int b) {
    if (b == 0) return a;

    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main()
{
    int top1 = 0; int bot1 = 0;
    int top2 = 0; int bot2 = 0;
    std::cin >> top1 >> bot1 >> top2 >> bot2;

    int result_top = top1 * bot2 + top2 * bot1;
    int result_bot = bot1 * bot2;

    int high = 0; int low = 0;
    if (result_top < result_bot) {
        high = result_bot;
        low = result_top;
    }
    else {
        high = result_top;
        low = result_bot;
    }

    int gcdResult = gcd(high, low);

    std::cout << result_top/ gcdResult << ' ' << result_bot/ gcdResult;
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