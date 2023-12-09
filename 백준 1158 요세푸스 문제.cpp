// 백준 1158 요세푸스 문제.cpp

#include <iostream>
#include <queue>

int main()
{
    int num = 0; int t_idx = 0;
    std::cin >> num >> t_idx;
    
    std::queue<int> q;

    for (int i = 1; i <= num; i++) {
        q.push(i);
    }

    int c_idx = 1;
    std::cout << '<';
    while (q.size() > 1) {
        if (c_idx == t_idx) {
            std::cout << q.front() << ", ";
            q.pop();
            c_idx = 1;
        }
        else {
            q.push(q.front());
            q.pop();
            c_idx++;
        }
    }
    std::cout << q.front() << ">";
    return 0;
}
