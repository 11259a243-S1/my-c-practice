#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
    int data; 
    struct Node* next; 
}; 
struct Node *front = NULL; 
struct Node *rear = NULL; 
int enqueue(int value) { 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    if (temp == NULL) { 
        printf("Memory allocation failed!\n"); 
        return -1; 
    } 
    temp->data = value; 
    temp->next = NULL; 
     if (front == NULL) { 
        front = rear = temp; 
        rear->next = front; 
    } else { 
        rear->next = temp; 
        rear = temp; 
        rear->next = front; 
    }
    printf("Inserted: %d\n", value); 
    return 0;
} 
int dequeue() { 
    if (front == NULL) { 
        printf("Queue Underflow! Queue is empty.\n"); 
        return -1; 
    } 
    int value; 
    if (front == rear) { 
        value = front->data; 
        free(front); 
        front = rear = NULL; 
    } else { 
        struct Node* temp = front; 
        value = temp->data; 
        front = front->next; 
        rear->next = front; 
        free(temp); 
    } 
    return value; 
} 
int display() { 
    if (front == NULL) {
        printf("Queue is empty.\n"); 
        return 0; 
    } 
    struct Node* temp = front; 
    printf("Circular Queue elements: "); 
    do { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } while (temp != front); 
    printf("\n"); 
    return 0;
} 
int main() { 
    enqueue(150); 
    enqueue(250); 
    enqueue(350); 
    display(); 
    printf("Dequeued: %d\n", dequeue()); 
    display(); 
    enqueue(400); 
    display(); 
    return 0; 
}
