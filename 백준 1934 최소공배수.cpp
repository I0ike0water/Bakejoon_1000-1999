// 백준 1934 최소공배수.cpp

#include <iostream>

int main()
{
    int test = 0;
    std::cin >> test;

    while (test--) {
        int num1 = 0; int num2 = 0;
        std::cin >> num1 >> num2;

        int result = num1 * num2;
        int num = 0;

        if (num1 > num2) num = num2;
        else num = num1;

        for (int i = 2; i <= num; i++) {
            if (i > num1 || i > num2) break;
            while (num1 % i == 0 && num2 % i == 0) {
                result /= i;
                num1 /= i;
                num2 /= i;
            }
        }
        std::cout << result << "\n";
    }
}
