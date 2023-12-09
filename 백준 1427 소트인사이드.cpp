// 백준 1427 소트인사이드.cpp
/*
문제
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 
각 자리수를 내림차순으로 정렬해보자.

입력
첫째 줄에 정렬하려고 하는 수 N이 주어진다. 
N은 1,000,000,000보다 작거나 같은 자연수이다.

예제1 입력 2143
예제1 출력 4321

예제2 입력 999998999
예제2 출력 999999998

#include <iostream>
#include <algorithm>

int main()
{
    int num = 0;
    std::cin >> num;
    int digit = 1;
    int temp = num;
    while (temp / 10 != 0) {
        temp /= 10;
        digit++;
    }

    int* number = new int[digit];
    for (int i = 0; i < digit; i++) {
        number[i] = num % 10;
        num /= 10;

    }
    std::sort(number, number + digit);
    for (int i = 0; i < digit; i++) {
        std::cout << number[digit - i - 1];
    }
    delete[] number;
    return 0;
}
-> 답이 틀리다고 나옴
*/
#include <iostream>
#include <algorithm>

int main()
{
    int num = 0;
    std::cin >> num;
    int digit = 0;
    int temp = num;
    int number[10];
    while (num > 0) {
        number[digit++] = num % 10;
        num /= 10;
    }

    std::sort(number, number + digit);
    for (int i = digit - 1; i >= 0; i--) {
        std::cout << number[i];
    }
    return 0;
}
//-> 답이 맞다고 나옴
//뭐가 다른거지?
