// 백준 1389 케빈 베이컨 6단계 법칙

#include <iostream>
#include <vector>
#include <queue>

void BFS(const std::vector<std::vector<int>>& relation,
    std::vector<std::vector<int>>& far, const int vertex, const int start) {

    std::vector<bool> visit(vertex + 1, false);
    std::queue<int> q;

    visit[start] = true;
    for (int i = 0; i < relation[start].size(); i++) {
        q.push(relation[start][i]);
        visit[relation[start][i]] = true;
    }

    int distance = 2;
    while (q.empty() == false) {
        int size = q.size();

        while (size--) {
            int x = q.front();
            if (visit[x] == false) visit[x] = true;
            q.pop();

            for (int y : relation[x]) {
                if (visit[y] == true) continue;

                q.push(y);
                visit[y] = true;
                if (distance < far[start][y]) {
                    far[start][y] = distance;
                    far[y][start] = distance;
                }
            }
        }
        distance++;
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int vertex = 0; int edge = 0;
    std::cin >> vertex >> edge;

    std::vector<std::vector<int>> relation (vertex + 1);
    std::vector<std::vector<int>> far(vertex + 1, std::vector<int>(vertex + 1, 100));

    for (int i = 0; i < edge; i++) {
        int a = 0; int b = 0;
        std::cin >> a >> b;

        relation[a].push_back(b);
        relation[b].push_back(a);
        far[a][b] = 1;
        far[b][a] = 1;
    }

    for (int i = 1; i <= vertex; i++) {
        BFS(relation, far, vertex, i);
    }
    
    
    int min = 500000;
    int idx = 0;
    for (int i = 1; i <= vertex; i++) {
        int tempSum = 0;
        for (int j = 1; j <= vertex; j++) {
            if (i == j) continue;
            tempSum += far[i][j];
        }
        if (tempSum < min) {
            min = tempSum;
            idx = i;
        }
    }
    std::cout << idx;
    return 0;
}
