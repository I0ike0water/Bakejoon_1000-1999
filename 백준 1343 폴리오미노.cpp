// 백준 1343 폴리오미노

#include <iostream>

int main()
{
    int count = 0;

    std::string chess;
    std::cin >> chess;

    const int size = chess.length();

    for (int i = 0; i < size; i++) {
        if (chess[i] == 'X') count++;
        else if (count != 0) {
            if (count % 2 != 0) {
                std::cout << -1;
                return 0;
            }
            while (count > 3) {
                for (int j = 0; j < 4; j++) chess[i - count + j] = 'A';
                count -= 4;
            }
            while (count > 0) {
                chess[i - count] = 'B';
                count--;
            }
            count = 0;
        }
    }

    if (count % 2 != 0) {
        std::cout << -1;
        return 0;
    }
    while (count > 3) {
        for (int j = 0; j < 4; j++) chess[size - count + j] = 'A';
        count -= 4;
    }
    while (count > 0) {
        chess[size - count] = 'B';
        count--;
    }

    std::cout << chess;
    return 0;
}
