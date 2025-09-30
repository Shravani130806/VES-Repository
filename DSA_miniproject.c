#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[20];
    int priority; 
} Passenger;
typedef struct Node {
    Passenger p;
    struct Node* next;} Node;
Node* front = NULL;   
int nextId = 1;    
int isEmpty() {
    return front == NULL;}
void enqueue(char name[], int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return; }
    newNode->p.id = nextId++;
    strcpy(newNode->p.name, name);
    newNode->p.priority = priority;
    newNode->next = NULL;
    if (isEmpty() || priority > front->p.priority) {
        newNode->next = front;
        front = newNode;}
        else {
        Node* temp = front;
        while (temp->next != NULL && temp->next->p.priority >= priority) {temp = temp->next; }
        newNode->next = temp->next;
        temp->next = newNode;}
    printf("Passenger %s (ID: %d, Priority: %d) checked in.\n", 
            name, newNode->p.id, newNode->p.priority);}
void dequeue() {
    if (isEmpty()) {
        printf("No passengers in queue!\n");
        return;}
    Node* temp = front;
    printf("Passenger %s (ID: %d, Priority: %d) is being served.\n", 
            temp->p.name, temp->p.id, temp->p.priority);
    front = front->next;
    free(temp);}
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;}
    printf("Current Queue (Highest priority first):\n");
    Node* temp = front;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Priority: %d\n", 
                temp->p.id, temp->p.name, temp->p.priority);
        temp = temp->next;}}
int main() {
    int choice, priority;
    char name[20];

    do {
        printf("\n--- Airport Check-in (Priority Queue) ---\n");
        printf("1. Add Passenger\n");
        printf("2. Serve Passenger\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter passenger name: ");
                scanf("%s", name);
                printf("Enter priority 
                (1=Low, 2=Medium, 3=High): ");
                scanf("%d", &priority);
                enqueue(name, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;}
