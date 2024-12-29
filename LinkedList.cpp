//
// Created by Jason Chestnut on 12/23/24.
//

#include "LinkedList.h"

LinkedList::LinkedList(std::string new_string) {
    if (new_string.empty()) return;

    // Create the head node
    this->head = new Node(new_string[0]);
    this->curr = head;
    Node *current = this->curr;

    // Loop through the string and create nodes
    for (size_t i = 1; i < new_string.size(); ++i) {
        this->push_item(new_string[i]);
        // current->next = new Node(new_string[i]);
        // current = current->next;
    }

    return;
}

LinkedList::~LinkedList() {
    this->cleanup_list();
}

void LinkedList::push_item(char new_item) {
    if (this->head == NULL) {
        this->head = new Node(new_item);
        this->head->next = nullptr;
        return;
    }

    Node *current = this->head;
    for (current = this->head; current->next != nullptr; current = current->next) {
    }
    current->next = new Node(new_item);
    current->next->next = nullptr;
}


void LinkedList::insert_item(int index, char item) {
    int idx = 0;
    Node *current = this->head;

    while (idx < index) {
        current = current->next;
        ++idx;
    }
    Node *new_node = new Node(item);
    new_node->next = current->next;
    current->next = new_node;
}

void LinkedList::cleanup_list() {
    while (this->head != nullptr) {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

char& LinkedList::operator[](int index) {
    Node* current = head;
    size_t count = 0;

    // Traverse the list to the specified index
    while (current) {
        if (count == index) {
            return current->item;
        }
        current = current->next;
        ++count;
    }

    // If index is out of bounds, throw an exception
    throw std::out_of_range("Index out of range");
}

std::string LinkedList::get_string() {
    std::string result = "";
    Node *current = this->head;

    if (this->head != nullptr) {
        do {
            result += current->item;
            current = current->next;
        }
        while (current != nullptr);
    }

    return result;
}

int LinkedList::size() {
    int count = 0;
    Node *current = this->curr;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}
