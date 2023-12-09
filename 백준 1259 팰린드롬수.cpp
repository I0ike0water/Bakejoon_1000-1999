// 백준 1259 팰린드롬수.cpp

#include <iostream>

int main()
{
    std::string line;
    while (true) {
        std::cin >> line;
        if (line[0] == '0') break;

        bool palindrome = true;
        int size = line.size();
        for (int i = 0; i < (size / 2) + 1; i++) {
            if (line[i] != line[size - 1 - i]) {
                palindrome = false;
                break;
            }
        }
        printf(palindrome ? "yes\n" : "no\n");
    }
    return 0;
}