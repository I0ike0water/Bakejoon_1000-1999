// 백준 1316 그룹 단어 체커.cpp 

#include <iostream>
#include <string>

int main(){
    int test;
    std::string line;
    std::cin >> test;
    
    int group = 0;
    for (int i = 0; i < test; i++) {
        std::cin >> line;
        bool group_check = true;
        char prev = line[0];
        bool alphabet[26] = { 0, };

        for(int j = 0; j <line.length(); j++){
            if (alphabet[line[j] - 'a']) {
                if (line[j] != prev) {
                    group_check = false;
                    break;
                }
            }
            if (!alphabet[line[j] - 'a']) {
                alphabet[line[j] - 'a'] = true;
            } 
            prev = line[j];
        }
        if (group_check) group++;
    }
    std::cout << group;
}