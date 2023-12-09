// 백준 1408번 문제

#include <iostream>

int* make_num(char a[]) {
	int* arr = new int[3];
	arr[0] = (a[0] - '0') * 10 + (a[1] - '0');
	arr[1] = (a[3] - '0') * 10 + (a[4] - '0');
	arr[2] = (a[6] - '0') * 10 + (a[7] - '0');
	return arr;
}

int main()
{	
	char st[9];
	char ft[9];
	int* st1;
	int* ft1;
	
	std::cin >> st >> ft;
	st1 = make_num(st);
	ft1 = make_num(ft);

	int hour = ft1[0] - st1[0];
	int minute = ft1[1] - st1[1];
	int second = ft1[2] - st1[2];

	delete[] st1;
	delete[] ft1;

	if (second < 0) {
		second += 60;
		minute--;
	}
	if (minute < 0) {
		minute += 60;
		hour--;
	}
	if (hour < 0) {
		hour += 24;
	}
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << hour << ":";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << minute << ":";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << second << std::endl;
}

