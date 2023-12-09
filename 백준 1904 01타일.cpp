// 백준 1904 01타일.cpp

#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    int a = 1; int b = 2;

    if (N == 1) {
        std::cout << a;
        return 0;
    }

    if (N == 2) {
        std::cout << b;
        return 0;
    }

    long long result = 0;
    for (int i = 3; i <= N; i++) {
        result = (a + b) % 15746;
        a = (b) % 15746;
        b = result;
    }
    std::cout << result;
}
