/* 
Creating functions
1. Define double link list
2. Remove duplicate elements from link list
3. Remove all elements less than key X from link list
*/

#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};


void append(Node** head, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head;

    if (*head == nullptr) {
        *head = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}


void deleteNode(Node** head, Node* del_node) {
    if (*head == nullptr || del_node == nullptr) return;

    if (*head == del_node) *head = del_node->next;

    if (del_node->next != nullptr) del_node->next->prev = del_node->prev;

    if (del_node->prev != nullptr) del_node->prev->next = del_node->next;

    delete del_node;
}


void removeDuplicates(Node** head) {
    if ((*head) == nullptr || (*head)->next == nullptr) return;

    std::unordered_set<int> seen;
    Node* current = *head;
    Node* next;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            next = current->next;
            deleteNode(head, current);
            current = next;
        } else {
            seen.insert(current->data);
            current = current->next;
        }
    }
}

void removeIfLessThan(Node** head, int value) {
    if (*head == nullptr) return;

    Node* current = *head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        if (current->data < value) {
            deleteNode(head, current);
        }
        current = next;
    }
}
void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void printListLast(Node* node) {
     while (node ->next != nullptr) {
        node = node->next;
    }
    while (node != nullptr) {
        std :: cout << node->data << std::endl;
        node = node->prev;
    }
}

int main() {
    Node* head = nullptr;
    append(&head, 1);
    append(&head, 1);
    append(&head, 3);
    append(&head, 3);
    append(&head, 4);
    append(&head, 4);
    append(&head, 4);
    append(&head, 5);
    append(&head, 5);
    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 5);
    append(&head, 4);
    append(&head, 4);
    append(&head, 6);

    std::cout << "Define list: ";
    printList(head);

    removeDuplicates(&head);

    std::cout << "After delete duplicate list: ";
    printList(head);

    removeIfLessThan(&head, 4);
    std:: cout << "After remove elements bigger than a number " ;
    printList(head);

    printListLast(head);
    return 0;
}