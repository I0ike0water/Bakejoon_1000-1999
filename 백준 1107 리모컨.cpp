// 백준 1107 리모컨.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    bool broken[10]{};
    std::string target;
    int broken_num;
    std::cin >> target >> broken_num;

    int min = 9; int max = 0;
    for (int i = 0; i < broken_num; i++) {
        int temp;
        std::cin >> temp;
        broken[temp] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (broken[i] == false) {
            if (max < i) max = i;
            if (min > i) min = i;
        }
    }

    int min_num = 0; int max_num = 0; int size = target.size();
    for (int i = 0; i < size-1; i++) {
        min_num += min * pow(10, i);
    }

    for (int i = 0; i < size; i++) {
        max_num += max * pow(10, i);
    }
    max_num += (target[0] - '0' + 1) * pow(10, size);
    if (max_num > 1000000) max_num = 1000000;

    int current_channel = 100;
    int min_press = abs(current_channel - std::stoi(target));

    for (int channel = min_num; channel <= max_num; channel++) {
        std::string channel_str = std::to_string(channel);
        bool valid = true;

        for (char digit : channel_str) {
            if (broken[digit - '0']) {
                valid = false;
                break;
            }
        }

        if (valid) {
            int press = abs(channel - std::stoi(target)) + channel_str.length();
            min_press = std::min(min_press, press);
        }
    }

    std::cout << min_press;

    return 0;
}

/*
#include <iostream>
#include <math.h>
#include <string>

struct Able {
    int low = -1;
    int high = -1;
};

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    bool broken[10]{};
    std::string target = "";
    int broken_num = 0;
    std::cin >> target >> broken_num;

    if (target == "100") {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < broken_num; i++) {
        int temp = 0;
        std::cin >> temp;
        broken[temp] = true;
    }

    int max = 0; int min = 9;
    for (int i = 0; i < 10; i++) {
        if (broken[i] == false) {
            if (max < i) max = i;
            if (min > i) min = i;
        }
    }

    int size = target.size();
    bool *broken_check = new bool[size]{};
    Able able[8]{};
    int count = 0;

    for (int i = 0; i < size; i++) {
        int check = target[i] - '0';
        if (broken[check] == true) {
            broken_check[i] = true;
            for (int j = check - 1; j >= min; j--) {
                if (broken[j] == false) {
                    able[i].low = j;
                    break;
                }
            }
            for (int j = check + 1; j <= max; j++) {
                if (broken[j] == false) {
                    able[i].high = j;
                    break;
                }
            }

        }
        else {
            continue;
        }
    }

    int highlow = 0;
    std::string temp1 = target;
    for (int i = 0; i < size; i++) {

        if (broken_check[i] == true && highlow == 0) {
            if (able[i].high == -1) {
                temp1[i] = able[i].low + '0';
                continue;
            }
            temp1[i] = able[i].high + '0';
            highlow++;
        }
        else if (broken_check[i] == true) {
            if (able[i].low == -1) {
                temp1[i] = able[i].high + '0';
            }
            else {
                temp1[i] = able[i].low + '0';
            }
        }
    }

    highlow = 0;
    std::string temp2 = target;
    for (int i = 0; i < size; i++) {
        if (broken_check[i] == true && highlow == 0) {
            if (able[i].low == -1) {
                temp2[i] = able[i].high + '0';
                continue;
            }
            temp2[i] = able[i].low + '0';
            highlow++;
        }
        else if(broken_check[i] == true) {
            if (able[i].high == -1) temp2[i] = able[i].low + '0';
            else temp2[i] = able[i].high + '0';
        }
    }

    std::string temp3 = target;
    for (int i = 1; i < size; i++) {
        temp3[0] = '0';
        if (broken_check[i] == true) temp3[i] = max + '0';
    }

    std::string temp4 = target;
    for (int i = 0; i < size; i++) {
        if (broken_check[i] == true) {
            if (able[i].low != -1) temp4[i] = able[i].low + '0';
            else temp4[i] = able[i].high + '0';
        }
    }

    std::string temp5 = target;
    for (int i = 0; i < size; i++) {
        if (broken_check[i] == true) {
            if (able[i].high != -1) temp5[i] = able[i].high + '0';
            else temp5[i] = able[i].low + '0';
        }
    }

    int tar_num = 0;
    int temp1_num = 0; int temp2_num = 0; int temp3_num = 0; int temp4_num = 0; int temp5_num = 0; int temp6_num = 0;

    tar_num = std::stoi(target);
    temp1_num = std::stoi(temp1);
    temp2_num = std::stoi(temp2);

    temp3_num = std::stoi(temp3);
    temp4_num = std::stoi(temp4);
    temp5_num = std::stoi(temp5);

    temp1_num = std::abs(temp1_num - tar_num) + size;
    temp2_num = std::abs(temp2_num - tar_num) + size;
    temp3_num = std::abs(temp3_num - tar_num) + size - 1;
    temp4_num = std::abs(temp4_num - tar_num) + size;
    temp5_num = std::abs(temp5_num - tar_num) + size;
    temp6_num = std::abs(tar_num - 100);


    std::cout << temp1_num << " " << temp2_num << " " << temp3_num << " " << temp4_num << " " << temp5_num << " " << temp6_num << "\n";

}
*/