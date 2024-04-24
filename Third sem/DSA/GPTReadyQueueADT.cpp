#include <stdio.h>
#include <stdlib.h>

// Queue as an ADT

void enqueue(int *tail) {
    int new_element;
    printf("Enter the element to enqueue: ");
    scanf("%d", &new_element);
    (*tail)++; // Incrementing the pointer
    *tail = new_element;
}

void dequeue(int *head) {
    printf("The element %d has been dequeued.", *head);
    (*head)++; // Incrementing the pointer
}

void peek(int *head) {
    printf("%d lies in the queue.", *head);
}

int main() {
    int *p, *head, *tail, i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    p = (int*)malloc(n * sizeof(int));
    head = tail = p; // Assigning p to both head and tail
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", (p + i));
        *tail = *(p + i);
    }
    enqueue(tail);
    dequeue(head);
    peek(head);
    free(p);
    return 0;
}

