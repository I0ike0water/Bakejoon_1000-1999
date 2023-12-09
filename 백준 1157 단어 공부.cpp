// 백준 1157 단어 공부
#include <iostream>
#include <cstring>

int main()
{
    int alpha[26] = {0, };
    std::string word;
    std::cin >> word;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] > 96) alpha[word[i] - 97]++;
        else alpha[word[i] - 65]++;
    }

    int max = 0;
    char result;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) {
            result = i + 65;
            max = alpha[i];
        }
        else if (alpha[i] == max) result = '?';
    }
    std::cout << result;
    return 0;
}
