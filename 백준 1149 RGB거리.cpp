// 백준 1149 RGB거리.cpp

#include <iostream>

struct RGB {
    int red;
    int green;
    int blue;
};

int main()
{
    int house = 0;
    std::cin >> house;

    RGB* rgb = new RGB[house]{};
    int dp[1001][3]{};

    for (int i = 0; i < house; i++) {
        std::cin >> rgb[i].red >> rgb[i].green >> rgb[i].blue;
    }

    int now = 1;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;

    while (now <= house) {
        dp[now][0] = std::min(dp[now - 1][1], dp[now - 1][2]) + rgb[now-1].red;
        //지금이 빨강일때 이전의 색은 초록이나 파랑이어야 함
        dp[now][1] = std::min(dp[now - 1][0], dp[now - 1][2]) + rgb[now-1].green;
        dp[now][2] = std::min(dp[now - 1][0], dp[now - 1][1]) + rgb[now-1].blue;
        now++;
    }

    int result = std::min(std::min(dp[house][0], dp[house][1]), dp[house][2]);
    std::cout << result;
    delete[] rgb;
    return 0;
}

