// 백준 1072 게임

#include <iostream>

long long binary_serach(int t_winRate, double t_game, 
    double w_game, double start, double end) {

    long long mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        double new_t_game = t_game + mid;
        double new_w_game = w_game + mid;
        int new_winRate = (new_w_game / new_t_game) * 100;

        if (new_winRate < t_winRate) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return start;
}



int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    double t_game = 0; double w_game = 0;
    std::cin >> t_game >> w_game;

    double winRate = 100 * w_game / t_game;

    if (winRate >= 99) {
        std::cout << -1;
        return 0;
    }

    int t_winRate = winRate + 1;

    long long result = 
        binary_serach(t_winRate, t_game, w_game, 0, t_game);

    std::cout << result;

    return 0;
}


/*
50 29
-> 2

10000 9999
-> -1

1 1
-> -1

*/