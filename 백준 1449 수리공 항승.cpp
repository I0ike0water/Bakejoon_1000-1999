// 백준 1449 수리공 항승
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int leakPoint = 0;
    int tapeLength = 0;
    std::cin >> leakPoint >> tapeLength;

    std::vector<int> v(leakPoint, 0);

    for (int i = 0; i < leakPoint; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    int tape = 0;
    int i = 0;
    while (i < leakPoint) {
        int j = i;
        while (j < leakPoint && v[j] - v[i] + 1 <= tapeLength) {
            j++;
        }
        i = j;
        tape++;
    }

    std::cout << tape;
    return 0;
}
