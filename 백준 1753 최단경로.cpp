// 백준 1753 최단경로


#define A 1

#if A
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

struct edgeList {
    int start;
    int end;

    edgeList(int start, int end) : start(start), end(end) {}

    bool operator<(const edgeList& other) const {
        return ((start != other.start || start < other.start) && end < other.end);
    }
};

void BFS(std::map<edgeList, int>& m, std::queue<int> q[], bool* visit, std::vector<int>& distance, int startVertex) {
    std::priority_queue<std::pair<int, int>> currentQue; //앞에 int는 정렬용
    currentQue.push({0, startVertex }); 
    distance[startVertex] = 0;

    while (currentQue.empty() == false) {
        int x_v = currentQue.top().second;
        currentQue.pop();

        if (visit[x_v] == true) continue;
        visit[x_v] = true;

        while (q[x_v].empty() == false) {
            int y = q[x_v].front();
            q[x_v].pop();

            if (visit[y] == true) continue;

            edgeList el(x_v, y);

            if (distance[y] > distance[x_v] + m[el]) {
                distance[y] = m[el] + distance[x_v];
                currentQue.push({ -distance[y], y });
            }
        }
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int vertex = 0; int edge = 0;
    std::cin >> vertex >> edge; //정점, 간선
    int startVertex = 0;
    std::cin >> startVertex; //시작 정점

    std::map<edgeList, int> m;
    std::queue<int>* q = new std::queue<int>[vertex + 1]{};
    std::vector<int> distance(vertex + 1, 3000000);
    bool* visit = new bool[vertex + 1]{};

    for (int i = 0; i < edge; i++) {
        int a = 0; int b = 0; int w = 0;
        std::cin >> a >> b >> w;
        q[a].push(b);
        edgeList el(a, b);

        if (m.find(el) != m.end()) {
            m[el] = std::min(m[el], w); continue;
        }
        m[el] = w;
    }

    BFS(m, q, visit, distance, startVertex);

    for (int i = 1; i <= vertex; i++) {
        if (visit[i] == false) {
            std::cout << "INF\n";
            continue;
        }
        std::cout << distance[i] << "\n";
    }
    delete[] visit;
    return 0;
}

/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
->
0
2
3
7
INF

4 3
1
1 2 10
2 3 10
3 4 10
->
0
10
20
30

2 1
1
1 2 2
->
0
2

10 9
1
1 2 9
2 8 9
7 3 10
5 6 6
3 4 7
4 5 2
6 10 8
8 5 4
2 3 10
->
0
9
19
26
22
28
INF
18
INF
36

4 1
1
4 2 3
->
0
INF
INF
INF

5 6
1
4 1 1
1 2 2
1 3 3
2 3 4
2 5 5
3 5 6
->
0
2
3
INF
7

4 8
1
1 2 3
2 1 5
4 3 4
2 3 10
1 3 10
2 4 1
3 1 1
1 2 2
->
0
2
7
3

8 12
1
1 8 7
7 3 2
7 5 8
2 8 7
3 4 8
2 1 8
5 1 8
5 3 2
1 7 1
2 6 5
4 1 8
7 6 7
->
0
INF
3
11
9
8
1
7


8 20
1
5 8 5
7 4 5
4 5 1
1 7 5
8 6 1
5 2 4
4 7 2
7 1 5
4 6 9
6 5 1
7 6 1
7 3 2
8 5 2
6 3 1
8 4 9
8 3 3
4 3 3
8 2 5
1 4 3
3 5 8
->
0
8
6
3
4
6
5
9
*/