// 백준 1916 최소비용 구하기.cpp

#include <iostream>
#include <vector>
#include <queue>

int dijk(std::vector<std::vector<std::pair<int, int>>> route,
    int start, int dest, int city) 
{
    std::vector<int> dist(city + 1, 100000000);
    std::priority_queue<std::pair<int, int>> pq;

    pq.push({ start, 0 });
    dist[start] = 0;

    while (pq.empty() == false) {
        int cost = -1 * pq.top().second;
        int current = pq.top().first;
        pq.pop();

        if (dist[current] < cost) continue;

        for (int i = 0; i < route[current].size(); i++) {
            int currentCost = cost + route[current][i].second;

            if (currentCost < dist[route[current][i].first]) {
                dist[route[current][i].first] = currentCost;
                pq.push({ route[current][i].first, -1 * currentCost });
            }
        }
    }
    return dist[dest];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int city = 0; int bus = 0;
    std::cin >> city >> bus;

    std::vector<std::vector<std::pair<int, int>>> route(city + 1);

    for (int i = 0; i < bus; i++) {
        int s = 0; int d = 0; int c = 0;
        std::cin >> s >> d >> c;

        route[s].push_back({ d, c });
    }

    int start = 0; int dest = 0;
    std::cin >> start >> dest;

    int result = dijk(route, start, dest, city);
    std::cout << result;
    return 0;
}

/*
4
3
1 3 0
3 2 0
2 4 0
1 4
-> 0

7
7
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
1 7 2
7 6 2
1 6
-> 4
*/