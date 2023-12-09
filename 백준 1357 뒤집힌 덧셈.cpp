// 백준 1357 뒤집힌 덧셈.cpp
/*
#include <iostream>
#include <cmath>
int REV(int x) {
    int reverse[4] = {0, };
    int size = 1;
    int result = 0;
    for (int i = 0; x / 10 > 0; i++) {
        reverse[i] = x % 10;
        x /= 10;
        size++;
    }
    reverse[size-1] = x;
    for (int i = size; i > 0; i--) {
        result += reverse[size-i] * pow(10, i - 1);
    }
    return result;
}

int main(){
    int x ;
    int y;
    int result;
    std::cin >> x >> y;

    result = REV(x) + REV(y);
    std::cout << REV(result);
    return 0;
}
*/

#include <iostream>

int REV(int x) {
    int result = 0;
    for (;x > 0; x /= 10) {
        result = result * 10 + x % 10; //혁명적이다.
    }
    return result;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << REV(REV(x) + REV(y));
    return 0;
}