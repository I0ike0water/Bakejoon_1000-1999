// 백준 1011 Fly me to the Alpha Centauri.cpp

#include <iostream>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int test = 0;
	std::cin >> test;

	while (test--) {
		long long x = 0; long long y = 0;
		std::cin >> x >> y;

		long long distance = y - x;
		long long active = 0;

		if (distance > 2) {
			long long idx = 1;

			while (true) {
				if ((idx * (idx + 1)) <= distance) idx++;
				else break;
			}
			idx--;

			distance -= (idx * (idx + 1));
			active += idx * 2;

			while (true) {
				if (distance / (idx + 1) > 0) {
					active += distance / (idx + 1);
					distance %= (idx + 1);
				}
				else {
					idx--;
					if (idx == -1) break;
				}

				if (distance == 0) break;
			}
			std::cout << active << "\n";
		}
		else {
			active = distance;
			std::cout << active << "\n";
			continue;
		}
	}
	return 0;
}

/*
1
0 17
-> 8

1
0 2147483647
*/