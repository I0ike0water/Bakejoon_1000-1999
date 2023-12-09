// 백준 1120 문자열.cpp

#include <iostream>
#include <string>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    std::string a; std::string b;
    std::cin >> a >> b;

    int min = a.size();
    int trial = b.size() - a.size();
    for (int i = 0; i <= trial; i++) {
        int dif = 0;
        for (int j = i; j < i + a.size(); j++) {
            if (a[j - i] != b[j]) dif++;
        }
        if (min > dif) min = dif;

        if (min == 0) break;
    }

    std::cout << min;
    return 0;
}
