// 백준 1043 거짓말

#include <iostream>
#include <queue>

void BFS(std::queue<int> q[], bool *visit, std::queue<int> KnownQue) {
    std::queue<int> MotherQue;

    while (KnownQue.empty() == false) {
        int x = KnownQue.front();
        KnownQue.pop();
        MotherQue.push(x);
        visit[x] = true;
    }

    while (MotherQue.empty() == false) {
        int x = MotherQue.front();
        MotherQue.pop();

        if (visit[x] == false) {
            visit[x] = true;
        }

        while (q[x].empty() == false) {
            int y = q[x].front();
            q[x].pop();

            if (visit[y] == false) {
                visit[y] = true;
                MotherQue.push(y);
            }
        }
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int person = 0; int party = 0;
    std::cin >> person >> party;
    int knownPersonNum = 0;
    std::cin >> knownPersonNum;

    std::queue<int>* q = new std::queue<int>[person + 1]{};
    std::queue<int> KnownPersonQue;
    bool *visit = new bool[person + 1]{};
    
    for (int i = 0; i < knownPersonNum; i++) {
        int tempPerson = 0;
        std::cin >> tempPerson;
        KnownPersonQue.push(tempPerson);
        visit[tempPerson] = true;
    }

    std::queue<int>* partyList = new std::queue<int>[51] {};

    for (int i = 0; i < party; i++) {
        int partyperson;
        std::cin >> partyperson;

        int partyPerson[51]{};

        for (int j = 0; j < partyperson; j++) {
            std::cin >> partyPerson[j];
            partyList[i].push(partyPerson[j]);
        }

        for (int j = 0; j < partyperson; j++) {
            for (int k = j + 1; k < partyperson; k++) {
                q[partyPerson[j]].push(partyPerson[k]);
                q[partyPerson[k]].push(partyPerson[j]);
            }
        }
    }

    BFS(q, visit, KnownPersonQue);

    delete[] q;

    int result = 0;
    for (int i = 0; i < party; i++) {
        bool able = true;
        while (partyList[i].empty() == false) {
            int x = partyList[i].front();
            partyList[i].pop();
            if (visit[x] == true) {
                able = false;
                break;
            }
        }

        if (able) result++;
    }
    std::cout << result;
    delete[] partyList;
    delete[] visit;
    return 0;
}
