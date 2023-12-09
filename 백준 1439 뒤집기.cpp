// 백준 1439 뒤집기

#include <iostream>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string zerone;
    std::cin >> zerone;

    int zero = 0, one = 0;

    if (zerone[0] == '0') zero++;
    else one++;

    for (int i = 1; i < zerone.length(); i++) {
        if (zerone[i] != zerone[i - 1]) {
            if (zerone[i] == '0') zero++;
            else one++;
        }
    }
    
    std::cout << (zero > one ? one : zero);
    return 0;
}
