// 백준 1010 다리 놓기

#include <iostream>

int main()
{
    int test = 0;
    std::cin >> test;

    while (test--) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        int west = 0, east = 0;
        std::cin >> west >> east;

        long long result = 1;

        if (west > east - west) west = east - west;

        for (int i = 1; i <= west; i++) {
            result *= (east - west + i);
            result /= i;
        }

        printf("%lld\n", result);
    }
    return 0;
}
