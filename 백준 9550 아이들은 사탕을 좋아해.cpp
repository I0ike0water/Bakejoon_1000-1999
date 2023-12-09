// 백준  9550 아이들은 사탕을 좋아해.cpp

#include <iostream>

int main(){
    int test, candy, satisfy;
    std::cin >> test;

    while (test--) {
        std::cin >> candy >> satisfy;
        int kid = 0, num_candy = 0;
        for (int i = 0; i < candy; i++) {
            std::cin >> num_candy;
            kid += num_candy / satisfy;
        }
        std::cout << kid << "\n";
    }
    return 0;
}
