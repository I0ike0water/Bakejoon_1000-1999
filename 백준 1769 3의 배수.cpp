// 백준 1769 3의 배수
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string number;
    int count = 0, result = 0;
    std::cin >> number;

    if (number.length() > 1) {
        while (number.length() > 1) {
            count++;
            result = 0;
            for (int i = 0; i < number.length(); i++) {
                result += (number[i] - '0');
            }

            if (result >= 10) {
                number = "";
                int i = 0;
                while (result > 0) {
                    number += (result % 10 + '0');
                    result /= 10;
                    i++;
                }
            }
            else break;
        }
    }
    else {
        result = ((number[0]-'0') % 10);
    }
    std::cout << count << "\n";
    if (result % 3 == 0) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}


/*
99
-> 2 YES

999999998
-> 2 NO
*/
