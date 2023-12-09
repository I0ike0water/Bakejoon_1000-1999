// 백준 1654 랜선 자르기.cpp

#include <iostream>

int main()
{
    long long lan_num = 0, cut_lan_num = 0;

    std::cin >> lan_num >> cut_lan_num;

    int* lan_list = new int[lan_num];
    long long min = 1000000, max = 0, sum = 0;

    for (int i = 0; i < lan_num; i++) {
        std::cin >> lan_list[i];
        if (min > lan_list[i]) min = lan_list[i];
        if (max < lan_list[i]) max = lan_list[i];
        sum += lan_list[i];
    }

    long long left = 0, right = sum/cut_lan_num;
    int answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (mid == 0) mid = 1;
        int temp_line = 0;
        for (int i = 0; i < lan_num; i++) {
            temp_line += lan_list[i] / mid;
        }

        if (temp_line >= cut_lan_num) {
            left = mid + 1;
            answer = mid;
        }
        else right = mid - 1;
    }
    printf("%d", answer);
    delete[] lan_list;
    return 0;
}

/*
#include <iostream>

int main()
{
    int lan_num = 0, cut_lan_num = 0;

    std::cin >> lan_num >> cut_lan_num;

    int* lan_list = new int[lan_num];
    int min = 1000000;
    long sum = 0;
    bool is_big = true;

    for (int i = 0; i < lan_num; i++) {
        std::cin >> lan_list[i];
        if (min < lan_list[i]) min = lan_list[i];
        sum += lan_list[i];
    }

    if (sum / min > cut_lan_num) is_big = false;
    int length = min;

    while (true) {
        int temp_line = 0;
        for (int i = 0; i < lan_num; i++) {
            temp_line += lan_list[i] / length;
        }

        if (is_big == false) {
            if (temp_line >= cut_lan_num) length++;
            else if(temp_line < cut_lan_num) {
                length--;
                break;
            }
        }
        else {
            if (temp_line < cut_lan_num) length--;
            else if (temp_line == cut_lan_num) break;
        }
    }
    printf("%d", length);
    delete[] lan_list;
    return 0;
}
*/