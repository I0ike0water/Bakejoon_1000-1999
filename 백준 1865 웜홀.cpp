// 백준 1865 웜홀.cpp

#include <iostream>
#include <vector>

#define INT_MAX 2147400000

struct Node {
    int start;
    int dest;
    int distance;
};

void BF(std::vector<Node> edge, int node) {
    std::vector<int> distance(node + 1, INT_MAX);

    for (int i = 0; i < node; i++) {
        for (int j = 0; j < edge.size(); j++) {
            if (distance[edge[j].start] + edge[j].distance < distance[edge[j].dest]) {
                distance[edge[j].dest] = distance[edge[j].start] + edge[j].distance;
            }
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        if (distance[edge[i].start] + edge[i].distance < distance[edge[i].dest]) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
    return;
}

int main()
{
    int test = 0; 
    std::cin >> test;

    while (test--) {
        int node = 0; int road = 0; int wormhole = 0;
        std::cin >> node >> road >> wormhole;

        std::vector<Node> edge;

        int start; int end; int distance;

        for (int i = 0; i < road; i++) {
            std::cin >> start >> end >> distance;
            edge.push_back({ start, end, distance });
            edge.push_back({ end, start, distance });
        }

        for (int i = 0; i < wormhole; i++) {
            std::cin >> start >> end >> distance;
            edge.push_back({ start, end, -distance });
        }

        BF(edge, node);
    }
    return 0;
}

