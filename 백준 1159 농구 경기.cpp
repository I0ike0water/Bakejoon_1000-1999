// 백준 1159 농구 경기

#include <iostream>

int main()
{
    int num_name;
    std::cin >> num_name;

    std::string name;
    int first_name[26]{};
    bool surrender = true;

    for (int i = 0; i < num_name; i++) {
        std::cin >> name;
        first_name[name[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (first_name[i] > 4) {
            std::cout << char(i + 'a');
            surrender = false;
        }
    }
    if (surrender) std::cout << "PREDAJA";
}
