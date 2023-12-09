// 백준 1076 저항.cpp

#include <iostream>
#include <math.h>

int main(){
    std::string f_color, s_color, t_color;
    std::string resist[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

    int resist_num = 0;
    long double temp = 0;

    std::cin >> f_color >> s_color >> t_color;
    for (int i = 0; i < 10; i++) {
        if (resist[i] == f_color) resist_num += i * 10;
        if (resist[i] == s_color) resist_num += i;
        if (resist[i] == t_color) resist_num *= pow(10, i);
    }
    std::cout << resist_num;
}