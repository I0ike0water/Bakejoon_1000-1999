// 백준 1292 쉽게 푸는 문제.cpp
#include <iostream>

int main()
{
    int start;
    int end;
    std::cin >> start >> end;
    int* easy_list = new int[end];
    int count = 0;
    
    for (int i = 1; count < end; i++) {
        for (int j = 0; j < i; j++) {
            easy_list[count] = i;
            count++;
        }
    }

    int num = 0;
    for (;start <= end; start++) {
        num += easy_list[start-1];
    }
    std::cout << num;
}
