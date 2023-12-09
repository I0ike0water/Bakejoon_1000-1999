// 백준 1699 제곱수의 합

#define A 1

#if A
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    std::cout << dp[n];
    return 0;
}
#else
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> dp(n + 1, 0);

    for (int i = 2; i * i <= n; i++) {
        for (int j = 1; j * i * i <= n; j++) {
            if (dp[j * i * i] == 0) dp[j * i * i] = j;
            else {
                if (dp[j * i * i] > j) dp[j * i * i] = j;
            }
        }
    }

    dp[1] = 1;
    int maxidx = 1;

    for (int i = 2; i <= n; i++) {
        if (dp[i] == 0) {
            dp[i] = std::min(dp[i - 1] + 1, dp[i - maxidx] + 1);
        }
        else if (dp[i] == 1) {
            maxidx = i;
        }
        else {
            dp[i] = std::min(dp[i - 1] + 1, dp[i]);
            dp[i] = std::min(dp[i - maxidx] + 1, dp[i]);
        }
        std::cout << i << ' ' << dp[i] << "\n";
    }
    std::cout << dp[n];
    return 0;
}
#endif





/*
753
-> 4

18
-> 2

4
-> 1

11
-> 3

13
-> 2
*/