// 백준 1546 평균 (오류 없음).cpp됩니다.
#include <iostream>

int main() {
    int sub_num;
    std::cin >> sub_num;
    int* sub = new int[sub_num];
    int prime_num = 0;
    double result = 0.0;
    int num = 0;
    double all_num = 0.0;

    for (int i = 0; i < sub_num; i++) {
        std::cin >> num;
        sub[i] = num;
        if (prime_num < num) prime_num = num;
        all_num += sub[i];
    }
    result = ((all_num / prime_num)/sub_num) * 100;
    std::cout << result;
}



