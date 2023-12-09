// 백준 1541 잃어버린 괄호.cpp

#include <iostream>
#include <stack>
#include <math.h>

long long StoI(std::stack<char>& s) {
    int size = s.size();
    long long result = 0;
    for (int i = 0; i < size; i++) {
        result += (s.top() - '0') * pow(10, i);
        s.pop();
    }
    return result;
}

int main()
{
    std::string expression;
    std::stack<char> s;
    bool minusExist = false;

    std::cin >> expression;
    long long totalSum = 0;

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') s.push(expression[i]);
        else {
            long long temp = 0;
            if (expression[i] == '-' && minusExist == false) {
                minusExist = true;

                if (s.empty() == false) {
                    temp = StoI(s);
                    totalSum += temp;
                }
                continue;
            }

            if (s.empty() == false) {
                temp = StoI(s);
                if (minusExist) totalSum -= temp;
                else totalSum += temp;
            }
        }
    }
    if (s.empty() == false) {
        long long temp = StoI(s);
        if (minusExist) totalSum -= temp;
        else totalSum += temp;
    }

    std::cout << totalSum;
    return 0;
}