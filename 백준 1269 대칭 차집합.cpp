// 백준 1269 대칭 차집합.cpp

#include <iostream>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int a_num = 0;
    int b_num = 0;
    std::cin >> a_num >> b_num;
    
    bool* digit = new bool[100000001]{};
    int temp = 0;
    int sum = a_num + b_num;

    for (int i = 0; i < a_num; i++) {
        std::cin >> temp;
        digit[temp] = true;
    }

    for (int i = 0; i < b_num; i++) {
        std::cin >> temp;
        if (digit[temp] == true) sum -= 2;
    }

    std::cout << sum;
    delete[] digit;
    return 0;
}
