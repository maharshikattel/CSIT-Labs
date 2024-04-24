#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node from the doubly linked list by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Structure for a node in the circular linked list
struct CircularNode {
    int data;
    struct CircularNode* next;
};

// Function to create a new node
struct CircularNode* createCircularNode(int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEndCircular(struct CircularNode** head, int data) {
    struct CircularNode* newNode = createCircularNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    struct CircularNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node from the circular linked list by value
void deleteNodeCircular(struct CircularNode** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct CircularNode* temp = *head;
    struct CircularNode* prev = NULL;

    while (temp->data != key) {
        if (temp->next == *head) {
            printf("Node with value %d not found.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == temp) { // Only one node in the list
        *head = NULL;
    } else if (temp == *head) { // If node to be deleted is head node
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = temp->next;
        prev->next = *head;
    } else if (temp->next == *head) { // If node to be deleted is last node
        prev->next = *head;
    } else { // Node to be deleted is somewhere in the middle
        prev->next = temp->next;
    }

    free(temp);
}

// Function to print the circular linked list
void printCircularList(struct CircularNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct CircularNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    // Doubly linked list
    struct Node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    printf("Doubly linked list: ");
    printList(head);
    deleteNode(&head, 2);
    printf("Doubly linked list after deleting node with value 2: ");
    printList(head);

    // Circular linked list
    struct CircularNode* circularHead = NULL;
    insertEndCircular(&circularHead, 1);
    insertEndCircular(&circularHead, 2);
    insertEndCircular(&circularHead, 3);
    printf("Circular linked list: ");
    printCircularList(circularHead);
    deleteNodeCircular(&circularHead, 2);
    printf("Circular linked list after deleting node with value 2: ");
    printCircularList(circularHead);

    return 0;
}
