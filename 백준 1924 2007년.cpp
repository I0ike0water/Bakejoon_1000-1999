// 백준 1924 2007년.cpp

/*
#include <iostream>

int main(){
    int month, date;
    std::cin >> month >> date;

    switch (month) {
    case(2):
        date += 31;
        break;
    case(3):
        date += 28 + 31;
        break;
    case(4):
        date += 28 + 31 + 31;
        break;
    case(5):
        date += 28 + 31 +31 + 30;
        break;
    case(6):
        date += 28 + 31 + 31 + 30 + 31;
        break;
    case(7):
        date += 28 + 31 + 31 + 30 + 31 + 30;
        break;
    case(8):
        date += 28 + 31 + 31 + 30 + 31 + 30 + 31;
        break;
    case(9):
        date += 28 + 31 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
    case(10):
        date += 28 + 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
    case(11):
        date += 28 + 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
    case(12):
        date += 28 + 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    }
    switch (date % 7) {
        case(1):
            std::cout << "MON";
            break;
        case(2):
            std::cout << "TUE";
            break;
        case(3):
            std::cout << "WED";
            break;
        case(4):
            std::cout << "THU";
            break;
        case(5):
            std::cout << "FRI";
            break;
        case(6):
            std::cout << "SAT";
            break;
        case(0):
            std::cout << "SUN";
            break;
    }
    return 0;
}
*/

#include <iostream>

int main() {
    int month, date;
    std::cin >> month >> date;

    int month_list[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    const char* day_of_week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI","SAT" };

    if (month > 1) {
        for (int i = 0; i < month - 1; i++) date += month_list[i];
    }
    std::cout << day_of_week[date % 7];
    return 0;
}
