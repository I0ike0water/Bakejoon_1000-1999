// 백준 1037 약수.cpp
#include <iostream>

int main()
{
    int divisor_num;
    std::cin >> divisor_num;

    int* divisor = new int[divisor_num];
    for (int i = 0; i < divisor_num; i++) {
        std::cin >> divisor[i];
    }

    int result = 0;
    int temp_num = 0;
    for (int i = divisor_num; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            if (divisor[j-1] < divisor[j]) {
                temp_num = divisor[j];
                divisor[j] = divisor[j - 1];
                divisor[j - 1] = temp_num;
            }
        }
    }
    if (divisor_num == 1) {
        result = divisor[0] * divisor[0];
    }
    else{
        result = divisor[divisor_num - 1] * divisor[0];
    }

    delete[] divisor;
    std::cout << result;
}

