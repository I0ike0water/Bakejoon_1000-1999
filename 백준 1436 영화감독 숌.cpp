// 백준 1436 영화감독 숌.cpp

#include <iostream>

int main()
{
    long num = 665;
    int movie_num = 0;
    int sss_num = 0;

    std::cin >> movie_num;

    while (true) {
        long num_idx[100]{};
        long temp = num;

        for (int i = 0; temp > 0; i++) {
            num_idx[i] = temp % 10;
            temp /= 10;
            if (i > 1 && num_idx[i] == 6 && num_idx[i - 1] == 6 && num_idx[i - 2] == 6) {
                sss_num++;
                break;
            }
        }

        if (sss_num == movie_num) break;
        num++;
    }
    std::cout << num;
}
