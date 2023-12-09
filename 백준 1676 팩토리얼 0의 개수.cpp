// 백준 1676 팩토리얼 0의 개수.cpp

#include <iostream>

int main(){
    int num;
    std::cin >> num;
    
    int five_num = 0;

    for (int i = 1; i < num + 1; i++) {
        int temp = i;
        while (temp % 5 == 0) {
            five_num++;
            temp /= 5;
        }
    }
    std::cout << five_num;
}