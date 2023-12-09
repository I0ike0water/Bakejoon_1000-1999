// 백준 1744 수 묶기.cpp

#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& container, int low, int high) {
	int pivot = container[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (container[j] < pivot) {
			i++;
			std::swap(container[i], container[j]);
		}
	}
	std::swap(container[i + 1], container[high]);
	return i + 1;
}

void quicksort(std::vector<int>& container, int left, int right) {
	if (left < right) {
		int q = partition(container, left, right);
		quicksort(container, left, q - 1);
		quicksort(container, q + 1, right);
	}
}

int main()
{
	int length = 0;
	std::cin >> length;

	std::vector<int> container(length, 0);
	std::vector<bool> visit(length, false);

	for (int i = 0; i < length; i++) {
		std::cin >> container[i];
	}

	quicksort(container, 0, length - 1);

	int result = 0;

	for (int i = length - 1; container[i] > 0; i--) {
		if (i > 0 && container[i - 1] > 1 && container[i] > 1) {
			result += container[i] * container[i - 1];
			visit[i] = true; visit[i - 1] = true;
			i--;
		}
		else {
			break;
		}
	}

	for (int i = 0; container[i] < 0; i++) {
		if (i < length - 1 && container[i + 1] < 0) {
			result += container[i] * container[i + 1];
			visit[i] = true; visit[i + 1] = true;
			i++;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < length; i++) {
		if (visit[i] == false) {	
			if ((i + 1) < length && container[i] < 0 && container[i + 1] == 0) {
				visit[i] = true; visit[i + 1] = true;
			}
			else {
				result += container[i];
			}
		}
	}

	std::cout << result;
	return 0;
}


