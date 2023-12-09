// 백준 1780 종이의 개수
#include <iostream>
#include <vector>

void recursion(std::vector<int>& map, int n, int& one, int& zero, int& minus) {
    bool same = true;
    int x = map[0];

    for (int i = 1; i < n * n; i++) {
        if (x != map[i]) {
            same = false;
            break;
        }
    }

    if (same) {
        if (x == 0) zero++;
        else if (x == 1) one++;
        else if (x == -1) minus++;
        return;
    }

    if (n <= 3) {
        for (int i = 0; i < n * n; i++) {
            if (map[i] == 0) zero++;
            else if (map[i] == 1) one++;
            else if (map[i] == -1) minus++;
        }
        return;
    }

    for (int i = 0; i < 9; i++) {
        int width = n / 3;
        std::vector<int> v(width * width, 0);
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < width; k++) {
                int temp = k + width * (i % 3) + (j + (i / 3) * width) * n;
                v[j * width + k] = map[temp];
            }
        }
        recursion(v, width, one, zero, minus);
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n = 0;
    std::cin >> n;

    int size = n * n;
    std::vector<int> map(size, 0);

    for (int i = 0; i < size; i++) {
        std::cin >> map[i];
    }
    int one = 0; int zero = 0; int minus = 0;
    recursion(map, n, one, zero, minus);

    std::cout << minus << "\n" << zero << "\n" << one;
    return 0;
}

/*
3
-1 0 1
-1 0 1
-1 0 1
->
3
3
3

3
1 -1 1
-1 1 -1
1 -1 0
->
4
1
4

3
0 0 0
0 0 0
0 0 1
->
0
8
1

3
-1 -1 -1
-1 1 -1
-1 -1 -1
->
8
0
1

9
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
->
0
0
1
*/