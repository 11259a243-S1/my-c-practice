#include <stdio.h>
#define MAX 50
float PQ[MAX];
int FRONT = -1,REAR = -1;
//3. INSERT(ITEM)
void insert(float item){
    if (REAR == MAX - 1){
        printf("Queue Overflow\n");
    }else{
        if (FRONT == -1) FRONT = 0;
        REAR++;
        PQ[REAR] = item;
    }
}
//4.FindMax()
int findMax(){
    if (FRONT == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    int maxIndex = FRONT;
    for (int i = FRONT + 1; i <= REAR; i++) {
        if (PQ[i] > PQ[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
    }
//5.DELETE()
void delete(){
    if (FRONT == -1){
        printf("Queue Underflow\n");
        return;
    }
int index = findMax();
    if (index == -1) return;

    printf("Deleted element: %.2f\n", PQ[index]);

    // Shift elements to the left
    for (int i = index; i < REAR; i++) {
        PQ[i] = PQ[i + 1];
    }
    REAR--;

    // Reset if queue becomes empty
    if (REAR < FRONT) {
        FRONT = -1;
        REAR = -1;
    }
}
int main() {
    int choice;
    float item;
    while(1){
        scanf("%d",&choice);
        if (choice == 1) {        // Insert
            scanf("%f", &item);
            insert(item);
        } else if (choice == 2) { // Delete
            delete();
        } else if (choice == 3) { // FindMax
            int idx = findMax();
            if (idx != -1) {
                printf("Max CGPA: %.2f\n", PQ[idx]);
            }
        } else if (choice == 4) { // Exit
            break;
        }
    }

    return 0;
}