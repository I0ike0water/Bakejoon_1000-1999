// 백준 1978 소수 찾기.cpp

#include <iostream>

int main()
{
    int number = 0, num = 0;
    std::cin >> number;
    int count = number;

    while (count--) {
        std::cin >> num;
        if (num == 1) {
            number--;
            continue;
        }
        
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                number--;
                break;
            }
        }
    }
    std::cout << number;
    return 0;
}

/*
#include <iostream>

int main()
{
    int number = 0;
    std::cin >> number;
    bool prime[1001]{};
    bool select_prime[1001]{};

    for (int i = 0; i < 1001; i++) prime[i] = true;

    int max = 0;
    int prime_number = number;

    for (int i = 0; i < number; i++) {
        int temp = 0;
        std::cin >> temp;
        select_prime[temp] = true;
        if (max < temp) max = temp;
        if (temp == 1) prime_number--;
    }

    for (int i = 2; i * i < max + 1; i++) {
        if (prime[i]) {
            for (int j = i * i; j < max + 1; j += i) {
                prime[j] = false;
                if (select_prime[j]) {
                    select_prime[j] = false;
                    prime_number--;
                }
            }
        }
    }
    std::cout << prime_number;
    return 0;
}
*/