#include <stdio.h>
#include <string.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val){
     if (rear == MAX - 1){
        printf("Queue Overflow\n");
     }else{
        if (front == -1) front = 0;
        rear++;
        queue[rear] = val;
     }
}
void dequeue(){
    if (front == -1 || front > rear){
        printf("Queue Underflow\n");
    }else{
        printf("Dequeued: %d\n",queue[front]);
        front++;
    }
}
void display(){
    if(front == -1 || front > rear){
        printf("Queue is Empty\n");
    }else{
        for(int i = front; i<= rear;i++){
        printf("%d", queue[i]);
        }
        printf("\n");
        }
    }
int main() {
    char choice[20];
    int val;
    while(1){
        scanf("%s",choice);
        if (strcmp(choice, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(choice, "dequeue") == 0) {
            dequeue();
        } else if (strcmp(choice, "display") == 0) {
            display();
        } else if (strcmp(choice, "exit") == 0) {
            break;
        }
    }

    return 0;
}
        