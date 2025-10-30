#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        perror("malloc failed");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// insert at front
void push_front(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

// insert at end
void push_back(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

// delete a node
void delete_node(Node** head, Node* del) {
    if (*head == NULL || del == NULL) return;

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

// print list forward
void print_forward(Node* head) {
    for (Node* temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

// print list backward
void print_backward(Node* tail) {
    for (Node* temp = tail; temp != NULL; temp = temp->prev)
        printf("%d ", temp->data);
    printf("\n");
}

int main() {
    Node* head = NULL;

    push_front(&head, 10);
    push_front(&head, 20);
    push_back(&head, 30);
    push_back(&head, 40);

    printf("Forward: ");
    print_forward(head);

    // get tail for reverse printing
    Node* tail = head;
    while (tail->next != NULL) tail = tail->next;

    printf("Backward: ");
    print_backward(tail);

    // delete middle node
    delete_node(&head, head->next);

    printf("After deletion: ");
    print_forward(head);

    return 0;
}

