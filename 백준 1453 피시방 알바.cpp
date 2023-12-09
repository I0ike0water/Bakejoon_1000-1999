// 백준 1453 피시방 알바.cpp

#include <iostream>

int main(){
    bool seat_num[100] = {false, };
    int customer, wanted_seat;
    int reject = 0;

    std::cin >> customer;
    for (int i = 0; i < customer; i++) {
        std::cin >> wanted_seat;
        if (!seat_num[wanted_seat - 1]) seat_num[wanted_seat - 1] = true;
        else reject++;
    }
    std::cout << reject;
}
