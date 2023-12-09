// 백준 1193 분수찾기

#include <iostream>

int main()
{
    int num, temp = 1, count = 2, sub = 0;
    std::cin >> num;
    while (num > temp) {
        temp += count;
        count++;
    }

    sub = (temp - num);
    count--;

    (count % 2 == 0) ? printf("%d/%d", count - sub, 1 + sub) : 
        printf("%d/%d", 1 + sub, count - sub);
    
    return 0;
}