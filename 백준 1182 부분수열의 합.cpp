// 백준 1182 부분수열의 합.cpp

#include <iostream>

void search(int *list, int target, int size, int N, int sum, int &result) {
    if (size == N) {
        if (target == sum) {
            result++;
        }
        return;
    }

    search(list, target, size + 1, N, sum + list[size], result);
    search(list, target, size + 1, N, sum, result);
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int num = 0; int target = 0;
    std::cin >> num >> target;

    int* list = new int[num] {};

    for (int i = 0; i < num; i++) {
        std::cin >> list[i];
    }

    int result = 0;

    if (target == 0) result--; //공집합

    search(list, target, 0, num, 0, result);
    std::cout << result;
    
    delete[] list;
    return 0;
}

/*
5 0
-7 -3 -2 5 8
-> 1

6 6
1 2 3 4 5 6
-> 4

5 -2
-1 -1 -1 -1 -1
-> 10

5 0
0 0 0 0 0
-> 31

*/