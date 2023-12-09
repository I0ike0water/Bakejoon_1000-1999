// 백준 1912 연속합.cpp

#include <iostream>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int s = 0;
    std::cin >> s;

    int n = 0;

    std::cin >> n;
    int total = n; int max = n;
    
    for (int i = 1; i < s; i++) {
        std::cin >> n;
        if (max < n) max = n;

        total += n;
        if (total < 0) total = 0;
        else if (total > max) max = total;
    }
    std::cout << max;

    return 0;
}