// 백준 1485 정사각형.cpp
#include <iostream>
#include <algorithm>

struct Dot {
    int x;
    int y;
};

int main()
{
    int test = 0;
    std::cin >> test;

    while (test--) {
        Dot dot[4]{};
        for (int i = 0; i < 4; i++) {
            std::cin >> dot[i].x >> dot[i].y;
        }

        bool isSquare = true;
        long long distances[6]{};
        int index = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int dx = dot[i].x - dot[j].x;
                int dy = dot[i].y - dot[j].y;
                distances[index] = std::abs(dx * dx + dy * dy);
                index++;
            }
        }

        std::sort(distances, distances + 6);

        isSquare = distances[0] > 0 && distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] 
            && distances[4] == distances[5]; //대각선의 길이도 같아야함

        
        if (isSquare == true) std::cout << 1 << "\n";
        else std::cout << 0 << "\n";
    }
    return 0;
}

/*
5
1 1
1 2
2 1
2 2
2 2
3 3
4 4
5 5
-1 0
1 1
2 -1
0 -2
100000 100000
-100000 -100000
100000 -100000
-100000 100000
0 1
3 0
3 2
6 1
->
1
0
1
1
0


*/
