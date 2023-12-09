// 백준 1789 수들의 합
#include <iostream>

int main()
{
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	long long result;
	std::cin >> result;

	result *= 2;

	long long num = 1;
	while (true) {
		if ((num * (num - 1)) > result) break;
		num++;
	}
	std::cout << num-2;
	return 0;
}