// 백준 1431 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>

void quickSort(std::vector<std::string>& arr, int low, int high) {
    if (low >= high) return;

    int i = low; int j = low;
    std::string& pivot = arr[high];
    for (; j < high; ++j) {
        if (arr[j].length() < pivot.length()) {
            std::swap(arr[i++], arr[j]);
        }
        else if (arr[j].length() == pivot.length()) {
            int jsum = 0;
            int psum = 0;
            for (char num : arr[j]) {
                if (num >= '0' && num <= '9') jsum += num - '0';
            }
            for (char num : pivot) {
                if (num >= '0' && num <= '9') psum += num - '0';
            }

            if (jsum < psum) {
                std::swap(arr[i++], arr[j]);
            }
            else if (jsum == psum) {
                if (arr[j] < pivot) {
                    std::swap(arr[i++], arr[j]);
                }
            }
        }
    }
    std::swap(arr[i], pivot);

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int guitar = 0;
    std::cin >> guitar;
    std::vector<std::string> guitarList(guitar);

    for (std::string& it : guitarList) {
        std::cin >> it;
    }

    quickSort(guitarList, 0, guitar - 1);

    for (std::string it : guitarList) {
        std::cout << it << "\n";
    }

    return 0;
}
