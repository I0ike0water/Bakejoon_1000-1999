// 백준 1167 트리의 지름

#include <iostream>
#include <vector>
#include <stack>

struct Node {
    int idx;
    int length;
};

Node DFS(std::vector<std::vector<Node>> tree, int start, int nodeNum) {
    std::stack<Node> s;
    std::vector<bool> visit(nodeNum + 1, false);
    s.push({start, 0});
    visit[start] = true;

    int maxidx = 0;
    int maxLength = 0;

    while (s.empty() == false) {
        Node x = s.top();
        s.pop();
        if (visit[x.idx] == false) visit[x.idx] = true;

        for (Node n : tree[x.idx]) {
            int l = n.length;
            int i = n.idx;

            if (visit[i] == true) continue;
            visit[i] = true;

            int length = x.length + n.length;

            if (length > maxLength) {
                maxLength = length;
                maxidx = i;
            }
            s.push({i, length});
        }
    }
    return {maxidx, maxLength};
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int nodeNum = 0;
    std::cin >> nodeNum;

    std::vector<std::vector<Node>> tree (nodeNum + 1);

    for (int i = 0; i < nodeNum; i++) {
        int parent = 0;
        std::cin >> parent;

        int sibling = 0; int length = 0;
        while (sibling != -1) {
            std::cin >> sibling;
            if (sibling == -1) break;
            std::cin >> length;

            tree[parent].push_back({ sibling, length });
            tree[sibling].push_back({ parent, length });
        }
    }
    Node farestNode = DFS(tree, 1, nodeNum);
    Node result = DFS(tree, farestNode.idx, nodeNum);
    std::cout << result.length;
    return 0;
}
