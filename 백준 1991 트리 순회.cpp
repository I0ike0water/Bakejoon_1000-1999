// 백준 1991 트리 순회

#define A 1

//preorder traversal 전위 순회
//inorder traversa 중위 순회
//postorder traversal 후위 순회

#if A
#include <iostream>
#include <vector>

void preorderTraversal(std::vector<std::vector<char>>& NodeList, char Root){
    if (Root == '.') return;

    std::cout << Root;
    preorderTraversal(NodeList, NodeList[Root - 'A'][0]);
    preorderTraversal(NodeList, NodeList[Root - 'A'][1]);
}

void inorderTraversa(std::vector<std::vector<char>>& NodeList, char Root) {
    if (Root == '.') return;
    
    inorderTraversa(NodeList, NodeList[Root - 'A'][0]);
    std::cout << Root;
    inorderTraversa(NodeList, NodeList[Root - 'A'][1]);
}

void postorderTraversal(std::vector<std::vector<char>>& NodeList, char Root) {
    if (Root == '.') return;

    postorderTraversal(NodeList, NodeList[Root - 'A'][0]);
    postorderTraversal(NodeList, NodeList[Root - 'A'][1]);
    std::cout << Root;
}

int main()
{
    int node = 0;
    std::cin >> node;

    std::vector<std::vector<char>> NodeList(node, std::vector<char>(2,'.'));

    //temp는 A, B, C, .... Z순으로 입력됨
    for (int i = 0; i < node; i++) {
        char temp = ' ';
        std::cin >> temp;
        std::cin >> NodeList[temp - 'A'][0] >> NodeList[temp - 'A'][1];
        //std::cin >> temp >> NodeList[i][0] >> NodeList[i][1]; //위와 결과가 다른 이유
    }
    preorderTraversal(NodeList, 'A');
    std::cout << "\n";
    inorderTraversa(NodeList, 'A');
    std::cout << "\n";
    postorderTraversal(NodeList, 'A');
    return 0;
}
#else
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

//preorder traversal 전위 순회
//inorder traversa 중위 순회
//postorder traversal 후위 순회

void preorderTraversal(std::vector<std::vector<char>>& NodeList) {
    std::stack<char> first;
    std::stack<char> second;

    first.push('A');

    while (first.empty() == false || second.empty() == false) {
        if (first.empty() == true) {
            char y = second.top();
            second.pop();
            first.push(y);
        }

        char x = first.top();
        std::cout << x;
        first.pop();
        if (x == '.') continue;

        for (int i = 0; i < 2; i++) {

            if (NodeList[x - 'A'][i] == '.') continue;

            if (i == 0) first.push(NodeList[x - 'A'][i]);
            else second.push(NodeList[x - 'A'][i]);
        }
    }
}

void inorderTraversa(std::vector<std::vector<char>>& NodeList) {
    std::stack<char> first;
    std::stack<char> second;

    first.push('A');

    while (first.empty() == false || second.empty() == false) {
        char x = first.top();
        char y = NodeList[x - 'A'][0];
        char z = NodeList[x - 'A'][1];

        if (y != '.') {
            first.push(y);
            if (z != '.')second.push(z);
            continue;
        }

        if (z != '.') second.push(z);

        while (first.empty() == false) {
            char popX = first.top();
            std::cout << popX;
            first.pop();
        }

        if (second.empty() == false) {
            first.push(second.top());
            second.pop();
        }
    }
}

void postorderTraversal(std::vector<std::vector<char>>& NodeList) {
    std::stack<char> first;
    std::stack<char> second;
    std::stack<char> result;

    first.push('A');

    while (first.empty() == false || second.empty() == false) {

        char x = ' ';

        if (second.empty() == true) {
            x = first.top();
            first.pop();
            result.push(x);
        }
        else {
            x = second.top();
        }

        char y = NodeList[x - 'A'][0];
        char z = NodeList[x - 'A'][1];

        if (y != '.') {
            second.push(y);
            if (z != '.')first.push(z);
            continue;
        }

        if (z != '.')first.push(z);

        while (second.empty() == false) {
            std::cout << second.top();
            second.pop();
        }
    }

    while (result.empty() == false) {
        std::cout << result.top();
        result.pop();
    }
}

int main()
{
    int node = 0;
    std::cin >> node;

    std::vector<std::vector<char>> NodeList(node, std::vector<char>(2, '.'));

    //temp는 A, B, C, .... Z순으로 입력됨
    for (int i = 0; i < node; i++) {
        char temp = ' ';
        std::cin >> temp;
        std::cin >> NodeList[temp - 'A'][0] >> NodeList[temp - 'A'][1];
        //std::cin >> temp >> NodeList[i][0] >> NodeList[i][1]; //위와 결과가 다른 이유
    }
    preorderTraversal(NodeList);
    std::cout << "\n";
    inorderTraversa(NodeList);
    std::cout << "\n";
    postorderTraversal(NodeList);
    return 0;
}
#endif


/*
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
->
ABDCEFG
DBAECFG
DBEGFCA
 
26
A B .
B C .
C D .
D E .
E F .
F G .
G H .
H I .
I J .
J K .
K L .
L M .
M N .
N O .
O P .
P Q .
Q R .
R S .
S T .
T U .
U V .
V W .
W X .
X Y .
Y Z .
Z . .
->
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ZYXWVUTSRQPONMLKJIHGFEDCBA
ZYXWVUTSRQPONMLKJIHGFEDCBA

6
A D C
B E F
C . .
D B .
E . .
F . .
->
ADBEFC
EBFDAC
EFBDCA

3
A B .
B . C
C . .
->
ABC
BAC
BCA

1
A . .
->
A
A
A
*/