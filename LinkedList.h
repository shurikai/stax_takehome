//
// Created by Jason Chestnut on 12/23/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

struct Node {
    char item;
    Node* next = nullptr;
    Node(char c): item(c), next(nullptr) {}
};

class LinkedList {
public:
    explicit LinkedList(std::string new_string);

    LinkedList() :head(nullptr), curr(nullptr) {
    }

    ~LinkedList();
    void push_item(char new_item);
    void insert_item(int index, char item);
    void cleanup_list();

    std::string get_string();
    int size();

    char& operator[](int index);

    class Iterator {
    public:
        explicit Iterator(Node* start) : current(start) {}
        Iterator & operator++() {
            if (current) { current = current->next; }
            return *this;
        }
        bool operator==(const Iterator& rhs) const { return current == rhs.current; }
        // bool operator!=(const Iterator& rhs) { return current != rhs.current; }
        char operator*() { return current->item; }

    private:
        Node* current;
    };

    // Begin iterator
    Iterator begin() const {
        return Iterator(head);
    }

    // End iterator
    Iterator end() const {
        return Iterator(nullptr);
    }

private:
    Node* head;
    Node* curr;
};



#endif //LINKEDLIST_H
