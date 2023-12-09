// 백준 1652 누울 자리를 찾아라.cpp

#include <iostream>
#include <string.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int size = 0;
    int width = 0;
    int length = 0;

    std::cin >> size;

    std::string* line = new std::string[size]{};

    for (int i = 0; i < size; i++) {
        std::cin >> line[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (line[i][j] == '.' && line[i][j+1] == '.') {
                width++;
                while (line[i][j] == '.' && j < size - 1) j++;
            }
        }

        for (int j = 0; j < size - 1; j++) {
            if (line[j][i] == '.' && line[j + 1][i] == '.') {
                length++;
                while (line[j][i] == '.' && j < size - 1) j++;
            }
        }
    }

    std::cout << width << ' ' << length;
    delete[] line;
}
