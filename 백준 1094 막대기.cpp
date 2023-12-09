// 백준 1094 막대기.cpp

#include <iostream>

int main()
{
    int length = 0, need = 0;
    std::cin >> length;

    while (length > 0) {
        if (length >= 64) length -= 64;
        if (length >= 32) length -= 32;
        else if (length >= 16) length -= 16;
        else if (length >= 8) length -= 8;
        else if (length >= 4) length -= 4;
        else if (length >= 2) length -= 2;
        else length -= 1;
        need++;
    }
    printf("%d", need);
    return 0;
}