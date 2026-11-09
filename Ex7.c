#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    strcut Node *next;
};
struct Node*head=NULL;
strcut Node *createnewNode(int id){
    struct Node*newNode=malloc(sizeof(structNode));
    newNode->data=id;
    newNode->next=NULL;
    return newNode;
};
void insertbeginning(int id){
    struct Node *newNode=createnewNode(id);
newNode->next=head;
head=newNode;
}
void insertend(int id) {
    struct Node *newNode = createnewNode(id);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void deletedata(int id) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == id) {
        head = temp->next; 
        free(temp);        
        return;
    }
     while (temp != NULL && temp->data != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", id);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void printList() {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    insertbeginning(100);
    printList();
    insertend(200);
    printList();
    deletedata(200);
    printList();

    return 0;
}