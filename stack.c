#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

void CreateStack(Stack* s) {
    s->head = NULL;
}

Node* CreateNode(int init) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = init;
    node->next = NULL;
    return node;
}

int isEmpty(Stack s) {
    return s.head == NULL;
}

void Push(Stack* s, Node* node) {
    if (isEmpty(*s)) {
        s->head = node;
    } else {
        node->next = s->head;
        s->head = node;
    }
}

int Pop(Stack* s) {
    if (isEmpty(*s)) {
        return 0;
    }
    Node* node = s->head;
    int data = node->data;
    s->head = node->next;
    free(node);
    return data;
}

int Top(Stack s) {
    if (isEmpty(s)) {
        return 0;
    }
    return s.head->data;
}

void DestroyStack(Stack* s) {
    Node* node = s->head;
    while (s->head != NULL) {
        s->head = node->next;
        free(node);
        node = s->head;
    }
}

void PrintStack(Stack s) {
    Node* node = s.head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    CreateStack(&stack);

    Node* node;
    for (int i = 0; i < 10; i++) {
        node = CreateNode(i + 1);
        Push(&stack, node);
    }
    PrintStack(stack); // Expected output: 10 9 8 7 6 5 4 3 2 1 

    printf("%d\n", Pop(&stack)); // Expected output: 10
    PrintStack(stack); // Expected output: 9 8 7 6 5 4 3 2 1 

    printf("%d\n", Top(stack)); // Expected output: 9
    PrintStack(stack); // Expected output: 9 8 7 6 5 4 3 2 1

    DestroyStack(&stack);

    return 0;
}
