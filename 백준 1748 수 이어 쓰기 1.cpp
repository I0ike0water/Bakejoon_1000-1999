// 백준 1748 수 이어 쓰기 1.cpp

#include <iostream>
#include <math.h>

int main()
{
	int num = 0;
	std::cin >> num;

	int length = 0;
	
	int temp = num;
	int size = 0;
	while (temp > 0) {
		temp /= 10;
		size++;
	}

	if (size == 1) {
		std::cout << num;
		return 0;
	}
	
	int i = 1;
	for (i = 1; i < size; i++) {
		length += 9 * pow(10, i - 1) * i;
	}

	length += (num - pow(10, i - 1) + 1) * i;
	std::cout << length;
	return 0;
}
