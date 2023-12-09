// 백준 1251 단어 나누기.cpp

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string line;
    std::cin >> line;

    int size = line.length();

    std::string result(50, 'z');

    for (int i = 1; i < size - 1; i++) {
        std::string temp1;
        std::string temp2;
        std::string temp3;

        temp1 = line.substr(0, i);
        std::reverse(temp1.begin(), temp1.end());

        std::string substr_line;
        substr_line = line.substr(i, size - i);

        for (int j = 1; j < substr_line.length(); j++) {
            std::string sum = "";
            temp2 = substr_line.substr(0, j);
            temp3 = substr_line.substr(j, substr_line.length() - j);
            std::reverse(temp2.begin(), temp2.end());
            std::reverse(temp3.begin(), temp3.end());
            sum = temp1 + temp2 + temp3;
            if (sum < result) {
                result = sum;
            }
        }
    }
    std::cout << result;
}

/*
                std::cout << result << "\n";
                std::cout << "temp1 : " << temp1 << "\n";
                std::cout << "temp2 : " << temp2 << "\n";
                std::cout << "temp3 : " << temp3 << "\n";
*/