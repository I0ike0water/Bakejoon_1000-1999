// 백준 1543 문서 검색.cpp
#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::string target_line;

    std::getline(std::cin, line);
    std::getline(std::cin, target_line);

    bool is_appear = false;
    int appear_time = 0;

    for (int i = 0; i < line.length(); i++) {
        is_appear = false;
        if (line[i] == target_line[0]) {
            is_appear = true;
            for (int j = 1; j < target_line.length(); j++) {
                if (line[i + j] != target_line[j]){
                    is_appear = false;
                    break;
                }
            }
            if (is_appear == true) {
                i += target_line.length()-1;
                appear_time++;
            }
        }
    }
    std::cout << appear_time;
}

/*
aababa
aba
정답 : 1

abababc
ababc
정답 : 1

aabb
ab
답 : 1
*/