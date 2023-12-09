// 백준 1244 스위치 켜고 끄기.cpp

#include <iostream>

int main()
{
	int lamp = 0;
	std::cin >> lamp;

	bool* lamp_list = new bool[lamp+1] {};

	for (int i = 1; i <= lamp; i++) {
		std::cin >> lamp_list[i];
	}

	int time = 0;
	std::cin >> time;

	int age = 0; int num = 0;
	while(time--){
		std::cin >> age >> num;

		if (age == 1) {
			for (int j = num; j <= lamp; j += num) {
				lamp_list[j] = !lamp_list[j];
			}
		}
		else {
			int x = num;
			int start = num;
			int end = num;
			while (start > 1 && end < lamp) {
				start--;
				end++;
				if (lamp_list[start] != lamp_list[end]) {
					start++;
					end--;
					break;
				}
			}
			
			for (int j = start; j <= end; j++) {
				lamp_list[j] = !lamp_list[j];
			}

		}
	}

	for (int i = 1; i <= lamp; i++) {
		if (i % 20 == 1 && i > 20) std::cout << "\n";
		std::cout << lamp_list[i] << ' ';
		
	}

	delete[] lamp_list;
	return 0;
}
