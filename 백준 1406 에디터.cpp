// 백준 1406 에디터.cpp

#include <iostream>

class Node {
public:
    char data;
    Node* next;
    Node* prev;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : size(0) {
        head = nullptr;
        tail = nullptr;
    }

    void append(char new_data) {
        Node* newNode = new Node();
        newNode->data = new_data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }

    void pop_position(int position) {
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        if (current != head) {
            current->prev->next = current->next;
        }
        else {
            head = head->next;
            delete[] current;
            return;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        size--;
    }

    void insert(char newData, int position) {
        if (position == 0) {
            Node* newNode = new Node();
            newNode->data = newData;
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            size++;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        Node* NewNode = new Node();
        NewNode->data = newData;
        NewNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NewNode;
        }
        temp->next = NewNode;
        NewNode->prev = temp;
        size++;
    }

    std::string printList() {
        Node* temp = head;
        std::string result = "";
        while (temp != nullptr) {
            result += temp->data;
            temp = temp->next;
        }
        return result;
    }

    int getSize() {
        return size;
    }
};

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    std::string line;
    std::cin >> line;

    LinkedList list;
    for (int i = 0; i < line.length(); i++) {
        list.append(line[i]);
    }

    int orderNum = 0; int cursor = line.length();
    std::cin >> orderNum;

    while (orderNum--) {
        std::string order;
        std::cin >> order;

        if (order == "L") {
            if (cursor > 0) cursor--;
        }
        else if (order == "D") {
            if (cursor < list.getSize()) cursor++;
        }
        else if (order == "B") {
            if (cursor > 0) {
                list.pop_position(cursor);
                cursor--;
            }
        }
        else if (order == "P") {
            char temp;
            std::cin >> temp;
            list.insert(temp, cursor);
            cursor++;
        }
    }
    std::cout << list.printList();
    return 0;
}
