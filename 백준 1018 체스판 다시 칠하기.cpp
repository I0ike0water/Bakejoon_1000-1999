// 백준 1018 체스판 다시 칠하기.cpp
#include <iostream>

struct CHESS {
    std::string line;
};

int main()
{
    int width = 0, length = 0;
    std::cin >> length >> width;
    
    CHESS* chess_line = new CHESS[length];
    
    int min = width * length;

    for (int i = 0; i < length; i++) std::cin >> chess_line[i].line;
    
    for (int k = 0; 8 <= length - k; k++) {
        for (int l = 0; 8 <= width - l; l++) {
            int cut_chess[8][8]{};
            int b_first = 0;
            int w_first = 0;
            char temp = ' ';

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cut_chess[i][j] = chess_line[i+k].line[j+l];

                    temp = cut_chess[i][j];

                    if (j % 2 == 0) {
                        if (i % 2 == 0) (temp == 'B') ? b_first++ : w_first++;
                        else (temp == 'W') ? b_first++ : w_first++;
                    }
                    else {
                        if (i % 2 == 0) (temp == 'W') ? b_first++ : w_first++;
                        else (temp == 'B') ? b_first++ : w_first++;
                    }
                }
            }
            
            int temp_min = ((b_first < w_first) ? b_first : w_first);
            if (temp_min < min) min = temp_min;
        }
    }
    std::cout << min;
}