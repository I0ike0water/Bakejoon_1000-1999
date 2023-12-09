// 백준 1074 Z.cpp

#include <iostream>
#include <math.h>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int N = 0; int X = 0; int Y = 0;
    std::cin >> N >> Y >> X;

    int size = pow(2, N);

    int* xlist = new int[size];
    int* ylist = new int[size];

    xlist[0] = 0; xlist[1] = 1;
    ylist[0] = 0; ylist[1] = 2;

    int inx = 0; int iny = 1;
    for (int i = 2; i <= N; i++) {
        inx += 2;
        iny += 2;
        for (int j = pow(2, i - 1); j < pow(2, i); j++) {
            int temp1 = j - pow(2, i - 1);
            xlist[j] = pow(2, inx) + xlist[temp1];
            //xlist[j - pow(2, i - 1)]

            int temp2 = j - pow(2, i - 1);
            ylist[j] = pow(2, iny) + ylist[temp2];
        }
    }

    std::cout << xlist[X] + ylist[Y];
    delete[] xlist;
    delete[] ylist;
}

