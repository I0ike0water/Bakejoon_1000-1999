// 백준 1032 명령 프롬프트.cpp
#include <iostream>
#include <string>

int main()
{
    int test;
    std::cin >> test;
    
    std::string file_name;
    std::cin >> file_name;

    std::string result = file_name;
    std::string compare = file_name;
    int name_size = file_name.length();
    
    for (int i = 1; i < test; i++) {
        std::cin >> file_name;
        for (int j = 0; j < name_size; j++) {
            if (compare[j] != file_name[j]) result[j] = '?';
        }
    }
    std::cout << result;
}
