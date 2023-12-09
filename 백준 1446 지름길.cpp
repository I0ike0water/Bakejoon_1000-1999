// 백준 1446 지름길

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int road = 0; int dest = 0;
	std::cin >> road >> dest;

	std::vector<std::vector<std::pair<int, int>>> roadList(dest + 1);
	std::vector<int> dp(10001, 10001);

	for (int i = 0; i < road; i++) {
		int s = 0; int d = 0; int c = 0;
		std::cin >> s >> d >> c;
		if (d > dest) continue;
		if (d - s <= c) continue;

		roadList[d].push_back({ s, c });
	}

	int startIdx = 0;

	dp[0] = 0;
	for (int i = 1; i <= dest; i++) {
		if (roadList[i].size() == 0) dp[i] = dp[i - 1] + 1;
		else {
			for (std::pair<int, int>& num : roadList[i]) {
				dp[i] = std::min(dp[i], std::min(dp[i - 1] + 1, dp[num.first] + num.second));
			}
		}
	}

	std::cout << dp[dest];
	return 0;
}
