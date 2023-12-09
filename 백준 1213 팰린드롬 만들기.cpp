// 백준 1213 팰린드롬 만들기

#include <iostream>
#include <queue>
#include <stack>

int main()
{
    std::string line;
    std::cin >> line;

    int size = line.length();
    bool odd = false;
    if (size % 2 == 1) odd = true;

    int alphabet[26]{};

    for (int i = 0; i < size; i++) {
        alphabet[line[i] - 'A']++;
    }

    int oddNum = 0; char centAlpha = ' ';

    std::queue<char> q;
    std::stack<char> s;

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 == 1) {
            oddNum++;
            centAlpha = i + 'A';
            alphabet[i]--;
        }

        if ((odd == false && oddNum > 0) || (odd == true && oddNum > 1)) {
            std::cout << "I'm Sorry Hansoo";
            return 0;
        }

        while (alphabet[i]) {
            s.push(i + 'A');
            q.push(i + 'A');
            alphabet[i] -= 2;
        }
    }

    while (q.empty() == false) {
        std::cout << q.front();
        q.pop();
    }

    if (odd == true) std::cout << char(centAlpha);

    while (s.empty() == false) {
        std::cout << s.top();
        s.pop();
    }

    return 0;
}