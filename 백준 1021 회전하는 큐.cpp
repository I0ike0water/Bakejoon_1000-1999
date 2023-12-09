// 백준 1021 회전하는 큐.cpp

#include <iostream>
#include <deque>

int main()
{
    int size = 0; int find = 0;
    std::cin >> size >> find;
    
    int target = 0;

    std::deque<int> d;
    for (int i = 1; i <= size; i++) {
        d.push_back(i);
    }

    int count = 0;
    while(find--) {
        std::cin >> target;

        int idx = 0;
        for (int j = 0; j < d.size(); j++) {
            if (d[j] == target) {
                idx = j;
                break;
            }
        }

        int left = idx;
        int right = d.size() - idx;

        if (left <= right) {
            count += left;
            for (int j = 0; j < left; j++) {
                int front = d.front();               
                d.pop_front();
                d.push_back(front);
            }
        }
        else {
            count += right;
            for (int j = 0; j < right; j++) {
                int back = d.back();
                d.pop_back();
                d.push_front(back);
            }
        }
        d.pop_front();
    }

    std::cout << count;
}