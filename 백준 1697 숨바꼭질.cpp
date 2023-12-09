#include <iostream>
#include <queue>

int BFS(int *coordinate, bool* visit, int target, int player) {
    std::queue<int> q;
    q.push(player);
    int time = 0;
    bool find = false;
    while (find == false) {
        int size = q.size();

        while (size--) {
            int x = q.front();
            q.pop();
            if (visit[x] == false) visit[x] = true;

            if (x < 200000 && visit[x + 1] == false) {
                if (x + 1 == target) {
                    time++;
                    find = true;
                    break;
                }
                q.push(x + 1);
                visit[x + 1] = true;
            }

            if (0 < x && visit[x - 1] == false) {
                if (x - 1 == target) {
                    time++;
                    find = true;
                    break;
                }
                q.push(x - 1);
                visit[x - 1] = true;
            }

            if (x*2 <= 200000 && visit[x*2] == false) {
                if (x * 2 == target) {
                    time++;
                    find = true;
                    break;
                }
                q.push(x * 2);
                visit[x * 2] = true;
            }
        }
        if (find == false) time++;
    }
    return time;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int player = 0; int target = 0;
    std::cin >> player >> target;

    if (player == target) {
        std::cout << 0;
        return 0;
    }

    int* coordinate = new int[200001]{};
    bool* visit = new bool[200001]{};
    
    int result = BFS(coordinate, visit, target, player);
    std::cout << result;
    return 0;
}


/*
0 1
-> 1

3 3
-> 0

6 11
-> 2

1 15
-> 5
*/