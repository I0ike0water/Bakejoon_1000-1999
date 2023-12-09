// 백준 1476 날짜 계산

#include <iostream>

int main()
{
    std::cout.tie(0);
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int e = 1, s = 1, m = 1, year = 1;
    std::cin >> e >> s >> m;

    while (true) {
        if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0) {
            break;
        }
        year++;
    }
    std::cout << year;
    return 0;
}

/*
#include <iostream>

int main()
{
    std::cout.tie(0);
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int e = 1, s = 1, m = 1, year = 1;
    int E = 0, S = 0, M = 0;
    std::cin >> E >> S >> M;

    while (true) {
        if (E == e && S == s && M == m) break;

        if (e == 15) e = 1;
        else e++;

        if (s == 28) s = 1;
        else s++;

        if (m == 19) m = 1;
        else m++;

        year++;
    }
    std::cout << year;
    return 0;
}
*/