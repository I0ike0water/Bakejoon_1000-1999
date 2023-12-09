// 백준 1932 정수 삼각형.cpp

#define A 1

//바텀업 알고리즘
//탑다운 알고리즘
#if A
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int size = 0;
    std::cin >> size;

    std::vector<std::vector<int>> triangle(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> triangle[i][j];
        }
    }

    for (int row = size - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            triangle[row][col] += std::max(triangle[row + 1][col], triangle[row + 1][col + 1]);
        }
    }

    std::cout << triangle[0][0];

    return 0;
}
#else
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[501][501] = { 0, };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                arr[i][j] = arr[i - 1][j] + arr[i][j];
            }
            else if (j == i) {
                arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
            }
            else {
                arr[i][j] = max(arr[i - 1][j - 1] + arr[i][j], arr[i - 1][j] + arr[i][j]);
            }
            result = max(result, arr[i][j]);
        }
    }
    cout << result;
} 
#endif

/*
2
1
1 1
->2

1
2
->2
*/