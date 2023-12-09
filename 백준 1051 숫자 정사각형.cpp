// 백준 1051 숫자 정사각형
#include <iostream>

int main()
{
    int length = 0; int width = 0;
    std::cin >> length >> width;

    int size = length * width;

    int* map = new int[size] {};
    std::string line;

    for (int i = 0; i < length; i++) {
        std::cin >> line;
        for (int j = 0; j < width; j++) {
            map[j + i * width] = line[j];
        }
    }

    int max = 1;
    for (int i = 0; i < size; i++) {
        int x = i % width;
        int y = i / width;

        
        for (int j = i + 1; (j - i + x) < width; j++) {
            int widthLength = 0;
            if (map[i] == map[j]) widthLength = j - i;

            if (widthLength != 0) {
                for (int k = i + width; k < size; k += width) {
                    int heightLength = 0;
                    if (map[i] == map[k]) heightLength = (k - i) / width;

                    if (heightLength > widthLength) break;

                    if (widthLength == heightLength) {
                        if (map[k + j - i] == map[i] && max < (widthLength+1)*(widthLength+1)) {
                            max = (widthLength + 1) * (widthLength + 1);
                        }
                    }
                }
            }
        }
    }
    std::cout << max;
    delete[] map;
    return 0;
}

