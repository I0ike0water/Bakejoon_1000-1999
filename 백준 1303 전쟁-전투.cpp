// 백준 1303 전쟁-전투.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

int BFS(std::vector<std::vector<char>>& field, std::vector<std::vector<bool>>& isvisit, 
    int width, int length, int pos, char color) {
    std::queue<int> q;
    q.push(pos);

    int count = 1;
    while (q.empty() == false) {
        pos = q.front();
        q.pop();

        int x = pos % width; int y = pos / width;
        if (isvisit[x][y] == false) isvisit[x][y] = true;

        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];

            if (0 <= nx && nx < width && 0 <= ny && ny < length) {
                if (isvisit[nx][ny] == false && field[nx][ny] == color) {
                    isvisit[nx][ny] = true;
                    q.push(nx + ny * width);
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int width = 0; int length = 0; int W = 0; int B = 0;

    std::cin >> width >> length;
    int size = width * length;

    std::vector<std::vector<char>> field(width, std::vector<char>(length, 0));
    std::vector<std::vector<bool>> isvisit(width, std::vector<bool>(length, false));

    for (int y = 0; y < length; y++) {
        std::string line;
        std::cin >> line;
        for (int x = 0; x < width; x++) {
            field[x][y] = line[x];
        }
    }

    for (int y = 0; y < length; y++) {
        for (int x = 0; x < width; x++) {
            if (isvisit[x][y] == false) {
                int soilder = BFS(field, isvisit, width, length, x + y * width, field[x][y]);
                if (field[x][y] == 'W') W += pow(soilder, 2);
                else B += pow(soilder, 2);
            }
        }
    }
    std::cout << W << ' ' << B;
    return 0;
}