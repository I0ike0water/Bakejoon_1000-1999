// 백준 1422 숫자의 신 (C언어).cpp

#define _CRT_SECURE_NO_WARNINGS
#define SWAP(a,b,tmp) {tmp = a; a = b; b = tmp;}
#include <iostream>
#include <algorithm>

int main()
{
    int num = 0, length = 0;
    scanf("%d %d", &num, &length);

    int* list = new int[num];
    int* temp_list = new int[num];
    int* use = new int[num];
    int max = 0;

    for (int i = 0; i < num; i++) {
        scanf("%d", &list[i]);
        temp_list[i] = list[i];
        while (temp_list[i] % 10 == 0) {
            temp_list[i] /= 10;
        }
        if (max < list[i]) max = list[i];
    }

    for (int i = num; i > 0; i--) {
        for (int j = 0; j < i-1; j++) {
            if (temp_list[j] == temp_list[j + 1]) {
                if (list[j] > list[j + 1]) {
                    int temp = 0;
                    SWAP(list[j], list[j + 1], temp);
                    SWAP(temp_list[j], temp_list[j + 1], temp);
                }
            }
            else {
                if (list[j] < list[j + 1]) {
                    int temp = 0;
                    SWAP(list[j], list[j + 1], temp);
                    SWAP(temp_list[j], temp_list[j + 1], temp);
                }
            }
        }
    }

    for (int i = 0; i < num; i++) {
        printf("%d", list[i]);
    }
    for (int i = 0; i < length - num; i++) {
        printf("%d", max);
    }
    delete[] list;
    delete[] temp_list;
    return 0;
}
