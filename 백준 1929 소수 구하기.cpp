// 백준 1929 소수 구하기.cpp

#include <iostream>

int main()
{
    int fir_num = 0, sec_num = 0;
    std::cin >> fir_num >> sec_num;

    bool* prime_arr = new bool[sec_num + 1]{};
    
    for (int i = 2; i < sec_num+1; i++) {
        prime_arr[i] = true;
    }

    for (int i = 2; i*i < sec_num + 1; i++) {
        if (prime_arr[i]) {
            for (int j = i * i; j < sec_num + 1; j += i) {
                prime_arr[j] = false;
            }
        }
    }

    for (int i = fir_num; i < sec_num + 1; i++) {
        if (prime_arr[i]) std::cout << i << "\n";
    }

    delete[] prime_arr;
}

/*
int main()
{
    int fir_num = 0, sec_num = 0;
    std::cin >> fir_num >> sec_num;

    for (int i = fir_num; i < sec_num + 1; i++) {
        if (i == 1) continue;
        bool is_prime = true;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) std::cout << i << "\n";
    }
}
*/