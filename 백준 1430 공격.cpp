// 백준 1430 공격

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

float  BFS(std::vector<std::queue<int>> map, 
    std::vector<bool>& attackAble, int tower, int start, int power) 
{
    std::vector<bool> visit(tower + 1, false);
    std::queue<std::pair<int, float>> q;
    q.push({start, power});
    visit[start] = true;
    bool find = false;

    while (q.empty() == false) {
        int x = q.front().first;
        float currentPower = q.front().second;
        q.pop();

        if (attackAble[x] == true) return currentPower;

        while (map[x].empty() == false) {
            int k = map[x].front();
            map[x].pop();

            if (visit[k] == true) continue;

            if (attackAble[k] == true) {
                find = true;
                return currentPower / 2;
            }
            else q.push({ k, currentPower / 2 });
        }
    }
    return 0.f;
}

bool rangeCalc(std::pair<int, int> a, std::pair<int, int> b,int range) {
    float x = a.first - b.first;
    float y = a.second - b.second;
    float dist = sqrt(pow(x, 2) + pow(y, 2));
    return dist <= range;
}

int main()
{
    int tower = 0; int range = 0; int power = 0; int ex = 0; int ey = 0;
    std::cin >> tower >> range >> power >> ex >> ey;

    std::vector<std::queue<int>> map(tower + 1);
    std::vector<std::pair<int, int>> towerLocation(tower + 1, {0, 0});
    std::vector<bool> attackAble(tower + 1, false);

    for (int i = 1; i <= tower; i++) {
        std::cin >> towerLocation[i].first >> towerLocation[i].second;
        if (rangeCalc(towerLocation[i], { ex, ey }, range)) attackAble[i] = true;
    }

    for (int i = 1; i <= tower; i++) {
        for (int j = i +1 ; j <= tower; j++) {
            if (rangeCalc(towerLocation[i], towerLocation[j], range)) {
                map[i].push(j);
                map[j].push(i);
            }
        }
    }
    
    double result = 0.0f;

    for (int i = 1; i <= tower; i++) {
        result += BFS(map, attackAble, tower, i, power);
    }

    std::cout << result;
    return 0;
}
