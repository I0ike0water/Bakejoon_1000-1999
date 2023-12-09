// 백준 1057 토너먼트.cpp

#include <iostream>
#include <queue>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int num = 0;
    int t1 = 0; int t2 = 0;
    std::cin >> num >> t1 >> t2;

    std::queue<int> q;

    for (int i = 1; i <= num; i++) q.push(i);


    int round = 1;
    bool isEnd = false;

    while (q.size() > 1) {
        int size = q.size();
        int tournamanet = size / 2;

        std::queue<int>temp_q;

        for (int i = 0; i < tournamanet; i++) {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();

            if ((x == t1 && y == t2) || (x == t2 && y == t1)) {
                isEnd = true;
                break;
            }
            else if (y == t1 || y == t2) temp_q.push(y);
            else temp_q.push(x);
        }

        if (isEnd == true) break;

        if (size % 2 == 1) {
            int x = q.front();
            q.pop();
            temp_q.push(x);
        }

        while (temp_q.empty() == false) {
            int x = temp_q.front();
            q.push(x);
            temp_q.pop();
        }
        round++;
    }

    if (isEnd == true) std::cout << round;
    else std::cout << -1;
    return 0;
}