// 백준 1731 추론 (C언어).cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int test = 0;
    bool arithmetic = true;
    scanf("%d", &test);

    int* num = new int[test];
    int subtract = 0;
    for (int i = 0; i < test; i++) {
        scanf("%d", &num[i]);
        if (i == 1) {
            subtract = num[1] - num[0];
        }
        if (i > 1) {
            if (subtract != (num[i] - num[i - 1])) {
                arithmetic = false;
            }
        }
    }
    if (arithmetic) {
        printf("%d", num[test - 1] + subtract);
    }
    else {
        int geometric = num[1] / num[0];
        printf("%d", num[test - 1] * geometric);
    }
    return 0;
}