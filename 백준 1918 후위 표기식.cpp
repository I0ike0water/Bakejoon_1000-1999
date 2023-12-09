// 백준 1918 후위 표기식.cpp

#include <iostream>
#include <stack>

int main() {
    std::string expression = "";
    std::cin >> expression;

    std::stack<char> s;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= 65 && expression[i] <= 90) { //알파벳일 경우 그냥 출력
            std::cout << expression[i]; continue;
        }

        if (s.empty() == true) { //스택이 비어있는 경우 연산자 넣음
            s.push(expression[i]); continue;
        }

        if (expression[i] == '(') {
            s.push(expression[i]); continue;
        }

        if (expression[i] == '+' || expression[i] == '-') {
            int test = 2;
            if (s.top() == '(') {
                s.push(expression[i]); 
                continue;
            }

            while (s.empty() == false && s.top() != '(') { //top의 연산자는 무조건 현재의 연산자보다 크거나 같다.
                std::cout << s.top();  
                s.pop();
            }
            s.push(expression[i]);
            continue;
        }

        if (expression[i] == '*' || expression[i] == '/') {
            if (s.top() == '(') {
                s.push(expression[i]); 
                continue;
            }

            if (s.top() == '*' || s.top() == '/') {
                while (s.empty() == false && s.top() != '(' && (s.top() == '*' || s.top() == '/')) {
                    //top의 연산자가 - 나 + 가 될때 까지 pop
                    std::cout << s.top();  s.pop();
                }
            }
            
            s.push(expression[i]);
            continue;
        }

        if (expression[i] == ')') {
            while (s.empty() == false) {
                if (s.top() == '(') {
                    s.pop();
                    break;
                }
                else {
                    std::cout << s.top();
                    s.pop();
                }
            }
        }
    }
    while (s.empty() == false) {
        std::cout << s.top();
        s.pop();
    }
}



/*
A+B+C
->
AB+C+

A*(B+C)
->
ABC+*

A+B
->
AB+

A+B*C
->
ABC*+

A+B*C-D/E
->
ABC*+DE/-

(((A+B)+C)+D)
->
AB+C+D+

A+B*C+D*E+G
->
ABC*+DE*+G+

((((A*B)+C)+D)+((E*F)*G))+E)
->
AB*C+D+EF*G*+E+

A*(B+C)/D
->
ABC+*D/

A+B*C+D
->
ABC*+D+

G*(A-B*(C/D+E)/F)
->
GABCD/E+*F/-*
*/

