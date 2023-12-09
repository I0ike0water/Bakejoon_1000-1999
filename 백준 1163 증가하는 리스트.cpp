// 백준 1163 증가하는 리스트.cpp
#include <iostream>
#include <string.h>

int main()
{
    std::string increase_list;
    std::cin >> increase_list;

    int list[50]{};

    for (int i = 0; i < increase_list.length(); i++) {
        if (increase_list[i] == '?') {

        }
        else if (increase_list[i] <= 89 && increase_list[i] >= 80) {
            if (i == 0) {
                std::cout << -1;
                return;
            }
            else {
                if (increase_list[i - 1] != '?') {
                    std::cout << -1;
                    return;
                }
            }



        }
        else if (increase_list[i] == ',') {

        }
    }
}
