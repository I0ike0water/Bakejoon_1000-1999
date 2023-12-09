// 백준 1005 ACM Craft.cpp

#include <iostream>
#include <vector>
#include <queue>

int BFS(std::vector<std::queue<int>>& ruleList, 
    std::vector<int>& buildCost, 
    std::vector<int>& counter,
    int dest, int building) 
{
    std::vector<int> timeCost(building + 1, 0);
    std::vector<bool> visit(building + 1, false);
    std::vector<int> WaitForBuild(building + 1, 0);

    std::queue<int> q;

    for (int i = 1; i <= building; i++) {
        if (counter[i] == 0) {
            q.push(i);
            visit[i] = true;
        }
        timeCost[i] = buildCost[i];
    }

    while (q.empty() == false) {
        int x = q.front();
        q.pop();

        timeCost[x] += WaitForBuild[x];

        while (ruleList[x].empty() == false) {
            int dx = ruleList[x].front();
            ruleList[x].pop();

            if (visit[dx] == true) continue;

            counter[dx]--;
            if (WaitForBuild[dx] < timeCost[x]) WaitForBuild[dx] = timeCost[x];

            if (counter[dx] > 0) {
                continue;
            }

            visit[dx] = true;
            q.push(dx);
        }
    }

    return timeCost[dest];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int test = 0;
    std::cin >> test;

    while (test--) {
        int building = 0; int rule = 0;
        std::cin >> building >> rule;
        
        std::vector<int> buildCost(building + 1, 0);
        std::vector<std::queue<int>> ruleList(building + 1);
        std::vector<int> counter(building + 1 , 0);

        for (int i = 1; i <= building; i++) {
            std::cin >> buildCost[i];
        }

        for (int i = 0; i < rule; i++) {
            int s = 0; int d = 0;
            std::cin >> s >> d;
            ruleList[s].push(d);
            counter[d]++;
        }

        int dest;
        std::cin >> dest;

        std::cout << BFS(ruleList, buildCost, counter, dest, building) << "\n";
    }
    return 0;
}