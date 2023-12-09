// 백준 1012 유기농 배추

#include <iostream>
#include <queue>

void available_x(int x, int y, int garden[51][51], bool check[51][51], 
    std::queue<int>& x_q, std::queue<int>& y_q) {
    int temp = x;
    while (temp != 50) {
        if (temp == 50) break;
        temp++;
        if (garden[temp][y] == 0 || check[temp][y] == true) break;
        check[temp][y] = true;
        x_q.push(temp);
        y_q.push(y);
;    }

    while (x != 0) { //x--
        if (x == 0) break;
        x--;
        if (garden[x][y] == 0 || check[x][y] == true) break;
        check[x][y] = true;
        x_q.push(x);
        y_q.push(y);
    }
}

void available_y(int x, int y, int garden[51][51], bool check[51][51], 
    std::queue<int>& x_q, std::queue<int>& y_q) {
    int temp = y;
    while (temp != 50) { //y++
        if (temp == 50) break;
        temp++;
        if (garden[x][temp] == 0 || check[x][temp] == true) break;
        check[x][temp] = true;
        y_q.push(temp);
        x_q.push(x);
    }

    while (y != 0) { //y--
        if (y == 0) break;
        y--;
        if (garden[x][y] == 0 || check[x][y] == true) break;
        check[x][y] = true;
        y_q.push(y);
        x_q.push(x);
    }
}

int main()
{
    int test = 0, width = 0, height = 0, cabbage = 0;
    std::cin >> test;

    while (test--) {
        std::cin >> width >> height >> cabbage;

        int garden[51][51]{};
        bool check[51][51]{};
        
        for (int i = 0; i < cabbage; i++) {
            int x, y;
            std::cin >> x >> y;
            garden[x][y] = 1;
        }

        int warm = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (garden[i][j] == 1 && check[i][j] == false) {
                    check[i][j] = true;
                    std::queue<int> x_q;
                    std::queue<int> y_q;

                    available_x(i, j, garden, check, x_q, y_q);
                    available_y(i, j, garden, check, x_q, y_q);

                    while (!x_q.empty()) {

                        available_x(x_q.front(), y_q.front(), garden, check, x_q, y_q);
                        available_y(x_q.front(), y_q.front(), garden, check, x_q, y_q);

                        x_q.pop();
                        y_q.pop();
                    }
                    warm++;
                }
                
            }
        }
        printf("%d\n", warm);
    }
}
