// 백준 1475 방 번호

#include <iostream>

int main()
{
    int number_list[10]{};
    int number = 0, max =0;
    bool is_69 = false;
    std::cin >> number;

    while (number > 0) {
        if (number % 10 == 9) number_list[6]++;
        else number_list[number % 10]++;
        number /= 10;
    }

    if (number_list[6] % 2 == 1) number_list[6] = (number_list[6] / 2) + 1;
    else number_list[6] = (number_list[6] / 2);

    for (int i = 0; i < 9; i++) {
        if (max < number_list[i]) max = number_list[i];
    }

    printf("%d", max);
}
