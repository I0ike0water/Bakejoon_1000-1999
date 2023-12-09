// 백준 1065 한수.cpp

#include <iostream>

int main()
{
    int num = 0;
    std::cin >> num;

    int hansu = 0;
    int num_list[4]{};

    if (num < 100) {
        std::cout << num;
        return 0;
    }
    else {
        hansu = 99;
        for (int i = 110; i <= num; i++) {

            int idx = 0;
            int temp = i;
            bool ishansu = true;

            while (temp > 0) {
                num_list[idx++] = temp % 10;
                temp /= 10;
            }
            int dif = num_list[1] - num_list[0];

            for (int j = 1; j < idx; j++) {
                if (dif != (num_list[j] - num_list[j - 1])) {
                    ishansu = false;
                    break;
                }
            }

            if (ishansu) hansu++;
        }
        std::cout << hansu;
        return 0;
    }
}
