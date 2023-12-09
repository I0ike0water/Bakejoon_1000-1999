#include <iostream>

int main()
{
    int num = 0;
    std::cin >> num;

    if (num < 10) num *= 10;

    int result = 0;
    int cycle = 0;

    while (result != num) {
        if (cycle == 0) result = num;
        result = ((result % 10) * 10) + (((result / 10) + (result % 10)) % 10);
        cycle++;
    }

    if (num == 0) cycle++;

    std::cout << cycle;
}
