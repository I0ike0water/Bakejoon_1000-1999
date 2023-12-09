// 백준 1406 에디터__벡터

#include <iostream>
#include <stack>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    std::string line;
    std::cin >> line;

    int size = line.length();

    std::stack<char> left;
    std::stack<char> right;

    for (int i = 0; i < size; i++) {
        left.push(line[i]);
    }

    int orderNum = 0;
    std::cin >> orderNum;

    while (orderNum--) {
        char order;
        std::cin >> order;

        if (order == 'L' && left.empty() == false) {
            right.push(left.top());
            left.pop();
        }
        else if (order == 'D' && right.empty() == false) {
            left.push(right.top());
            right.pop();
        }
        else if (order == 'B' && left.empty() == false) left.pop();
        else if (order == 'P') {
            char x;
            std::cin >> x;
            left.push(x);
        }
    }
    
    while (left.empty() == false)
    {
        right.push(left.top()); left.pop();
    }

    while (right.empty() == false)
    {
        std::cout << right.top(); right.pop();
    }
    return 0;
}