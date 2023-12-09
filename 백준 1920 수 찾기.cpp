// 백준 1920 수 찾기.cpp

#include <iostream>
#include <algorithm>

bool binary_search(int list[], int number, int left, int right) {
    int mid = 0;
    while (left <= right) {
        mid = ((left + right) / 2);
        if (list[mid] == number) return true;

        if (list[mid] > number) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main()
{

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int ex_number = 0;
    std::cin >> ex_number;
    int* ex_list = new int[ex_number];

    for (int i = 0; i < ex_number; i++) std::cin >> ex_list[i];

    std::sort(ex_list, ex_list + ex_number);

    int ch_number = 0, number = 0;
    std::cin >> ch_number;
    
    for (int i = 0; i < ch_number; i++) {
        std::cin >> number;
        std::cout << binary_search(ex_list, number, 0, ex_number - 1) << "\n";
    }
    delete[] ex_list;
    return 0;
}

