// 백준 1927 최소 힙.cpp :

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int time;
    std::cin >> time;

    std::vector<int> v;

    int num;
    while (time--) {
        std::cin >> num;

        if (num == 0) {
            if (v.empty() == true) std::cout << "0\n";
            else {
                std::cout << v.front() << "\n";
                v.erase(v.begin());
            }
        }
        else {
            if (v.empty() == true) v.push_back(num);
            else {
                if (num >= v.back()) v.push_back(num);
                else if (num <= v.front()) v.insert(v.begin(), num);
                else {
                    int start = 0; int end = v.size() - 1; int idx = 0;
                    while (start <= end) {
                        int mid = (start + end) / 2;

                        if (v[mid] < num) start = mid + 1;
                        else if (v[mid] > num) {
                            end = mid - 1;
                            idx = mid;
                        }
                        else {
                            idx = mid;
                            break;
                        }
                    }
                    v.insert(v.begin() + idx, num);
                }
            }
        }
    }
    return 0;
}

/*
9 0 12345678 1 2 0 0 0 0 32


11 1 3 2 4 0 5 0 0 0 0 0
-> 1 2 3 4 5 0

8 1 4 2 5 6 3 0 0
-> 1 2
*/