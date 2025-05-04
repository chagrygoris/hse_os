#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;



node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* reverse_list(node* head) {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void free_list(node* head) {
    node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void print_list(node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    int num;

    while (scanf("%d", &num) && num != 0) {
        node* new_node = create_node(num);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    head = reverse_list(head);
    print_list(head);
    free_list(head);

    return 0;
}