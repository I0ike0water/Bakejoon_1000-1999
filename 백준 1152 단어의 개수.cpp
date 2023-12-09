// 백준 1152 단어의 개수.cpp

#include <iostream>
#include <string>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    std::string line;
    std::getline(std::cin, line);

    int blank = 0;
    for (int i = 1; i < line.length()-1; i++) {
        if (line[i] == ' ') blank++;
    }
    if (line.length() == 1 && line[0] == ' ') {
        std::cout << blank;
    }
    else {
        std::cout << blank + 1;
    }
    
    return 0;
}
