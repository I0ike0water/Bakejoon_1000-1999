// 백준 1260 DFS와 BFS.cpp

#include <iostream>
#include <queue>
#include <stack>

void BFS(int point, int start_idx, bool point_list[], bool **line_list) {
    std::queue<int> q;
    q.push(start_idx);

    while (q.empty() == false) {
        int x = q.front();
        point_list[start_idx] = true;
        q.pop();
        std::cout << x << ' ';

        for (int i = 0; i < point + 1; i++) {
            if (line_list[x][i] == true && point_list[i] == false) {
                point_list[i] = true;
                q.push(i);
            }
        }
    }
}

void DFS(int point, int start_idx, bool point_list[], bool** line_list) {
    std::stack<int> s;
    s.push(start_idx);

    while (!s.empty()) {
        int x = s.top();
        s.pop();

        if (point_list[x] == false) {
            std::cout << x << ' ';
            point_list[x] = true;
        }

        for (int i = point; i >= 0; i--) {
            if (line_list[x][i] == true && !point_list[i]) {
                s.push(i);
            }
        }
    }
}

int main()
{
    int point = 0;
    int line = 0;
    int start_idx = 0;

    std::cin >> point >> line >> start_idx;

    bool** line_list = new bool* [point + 1]{};
    for (int i = 0; i < point + 1; i++) {
        line_list[i] = new bool[point + 1]{};
    }

    bool* bfs_point_list = new bool[point + 1]{};
    bool* dfs_point_list = new bool[point + 1]{};

    for (int i = 0; i < line; i++) {
        int x = 0; int y = 0;
        std::cin >> x >> y;
        line_list[x][y] = line_list[y][x] = true;
    }

    DFS(point, start_idx, dfs_point_list, line_list);
    std::cout << "\n";
    BFS(point, start_idx, bfs_point_list, line_list);

    delete[] bfs_point_list;
    delete[] dfs_point_list;
    for (int i = 0; i < point + 1; i++) {
        delete[] line_list[i];
    }
    delete[] line_list;
}
