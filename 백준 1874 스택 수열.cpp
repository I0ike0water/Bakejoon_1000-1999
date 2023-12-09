// 백준 1874 스택 수열.cpp

#include <iostream>
#include <stack>

int main()
{
    int number = 0;
    std::cin >> number;
    std::string print = "";
    std::stack<int> s;

    bool able = true;
    int last_pop = 0, pop_num = 0;

    while (number--) {
        std::cin >> pop_num;

        if (pop_num > last_pop) {
            for (int i = last_pop + 1; i < pop_num + 1; i++) {
                print += "+\n";
                s.push(i);
            }
            last_pop = pop_num;
        }
        
        if (s.top() != pop_num && !s.empty()) able = false;
        else {
            s.pop();
            print += "-\n";
        }
    }
    std::cout << (able ? print : "NO");
    return 0;
}
