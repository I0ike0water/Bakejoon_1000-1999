// 백준 1764 듣보잡.cpp

/*
#include <iostream>
#include <algorithm>
#include <queue>

int main()
{
    int dud, boo;
    std::cin >> dud >> boo;
    std::string* dud_l = new std::string[dud];
    std::string* boo_l = new std::string[boo];

    for (int i = 0; i < dud; i++) std::cin >> dud_l[i];
    for (int i = 0; i < boo; i++) std::cin >> boo_l[i];

    std::sort(dud_l, dud_l + dud);
    std::sort(boo_l, boo_l + boo);
    std::queue<std::string> q;

    for (int i = 0; i < dud; i++) {
        if (std::binary_search(boo_l, boo_l + boo, dud_l[i])) {
            q.push(dud_l[i]);
        }
    }
    std::cout << q.size() << "\n";
    while (!q.empty()) {
        std::cout << q.front() << "\n";
        q.pop();
    }
    delete[] dud_l;
    delete[] boo_l;
}
*/


#include <iostream>
#include <algorithm>
#include <queue>

int main()
{
    int dud, boo;
    std::cin >> dud >> boo;
    std::string* dudboo = new std::string[dud+boo];

    for (int i = 0; i < (dud+boo); i++) std::cin >> dudboo[i];

    std::sort(dudboo, dudboo + (dud+boo));
    std::queue<std::string> q;

    for (int i = 1; i < dud+boo; i++) {
        if (dudboo[i] == dudboo[i-1]) {
            q.push(dudboo[i]);
        }
    }
    std::cout << q.size() << "\n";
    while (!q.empty()) {
        std::cout << q.front() << "\n";
        q.pop();
    }
    delete[] dudboo;
    return 0;
}

