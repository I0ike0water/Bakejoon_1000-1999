// 백준 1092 배

#define A 1

#if A

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int crain = 0;
    std::cin >> crain;

    std::vector<int> crainList(crain, 0);

    for (int i = 0; i < crain; i++) {
        std::cin >> crainList[i];
    }

    int box = 0;
    std::cin >> box;

    std::priority_queue<int, std::vector<int>, std::less<int>> boxList;

    for (int i = 0; i < box; i++) {
        int temp;
        std::cin >> temp;
        boxList.push(temp);
    }
    
    std::sort(crainList.begin(), crainList.end(), comp);

    if (boxList.top() > crainList[0]) {
        std::cout << -1;
        return 0;
    }

    int time = 0;
    
    while (boxList.empty() == false) {
        std::priority_queue<int> temp;
        for (int i = 0; i < crain; i++) {
            while (boxList.empty() == false) {
                if (boxList.top() < crainList[i]) {
                    boxList.pop();
                    break;
                }
                else {
                    temp.push(boxList.top());
                    boxList.pop();
                }
            }
        }

        while (temp.empty() == false) {
            boxList.push(temp.top());
            temp.pop();
        }
        time++;
    }

    std::cout << time;

    return 0;
}

#else
#include <iostream>
#include <vector>
#include <algorithm>

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int crain = 0;
    std::cin >> crain;

    std::vector<int> crainList(crain, 0);

    for (int i = 0; i < crain; i++) {
        std::cin >> crainList[i];
    }

    int box = 0;
    std::cin >> box;

    std::vector<int> boxList(box, 0);

    for (int i = 0; i < box; i++) {
        std::cin >> boxList[i];
    }

    std::sort(crainList.begin(), crainList.end(), comp);
    std::sort(boxList.begin(), boxList.end(), comp);

    if (boxList[0] > crainList[0]) {
        std::cout << -1;
        return 0;
    }

    int time = 0;
    while (boxList.empty() == false) {
        time++;
        for (int i = 0; i < crain; i++) {
            for (auto it = boxList.begin(); it != boxList.end(); ++it) {
                if (*it <= crainList[i]) {
                    boxList.erase(it);
                    break;
                }
            }
        }
    }

    std::cout << time;

    return 0;
}
#endif


/*
3
10 7 4
9
9 9 8 7 6 6 5 5 2
-> 4
*/