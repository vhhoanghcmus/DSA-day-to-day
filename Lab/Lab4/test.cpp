#include <iostream>

// Định nghĩa cấu trúc của một nút
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Hàm để thêm nút vào đầu danh sách
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;
    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// Hàm merge cho natural merge sort
Node* merge(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

// Hàm để tìm và trả về đầu của chuỗi tiếp theo
Node* findNextRun(Node* start) {
    while (start->next && start->data <= start->next->data) {
        start = start->next;
    }
    return start->next;
}

// Hàm natural merge sort
void naturalMergeSort(Node** head_ref) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        Node* current = *head_ref;
        Node* tail = nullptr;
        Node* next_run = findNextRun(current);

        while (next_run) {
            sorted = false;
            while (next_run && current->data <= next_run->data) {
                current = next_run;
                next_run = findNextRun(current);
            }

            if (tail) {
                tail->next = merge(*head_ref, current);
                tail->next->prev = tail;
            } else {
                *head_ref = merge(*head_ref, current);
            }

            while (*head_ref && (*head_ref)->next) {
                tail = *head_ref;
                *head_ref = (*head_ref)->next;
            }

            current = next_run;
            if (next_run) {
                next_run = findNextRun(current);
            }
        }
    }
}

// Hàm để in danh sách liên kết đôi
void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
}

// Hàm chính để thử nghiệm các hàm trên
int main() {
    Node* head = nullptr;

    // Thêm dữ liệu vào danh sách
    push(&head, 12);
    push(&head, 11);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    // In danh sách
    std::cout << "Danh sách ban đầu: ";
    printList(head);

    // Sắp xếp danh sách
    naturalMergeSort(&head);

    // In danh sách sau khi sắp xếp
    std::cout << "\nDanh sách sau khi sắp xếp: ";
    printList(head);

    return 0;
}