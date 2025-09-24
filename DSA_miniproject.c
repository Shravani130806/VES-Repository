#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char name[20];
} Passenger;


typedef struct Node {
    Passenger p;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int nextId = 1;


int isEmpty() {
    return front == NULL;
}


void enqueue(char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->p.id = nextId++;
    strcpy(newNode->p.name, name);
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Passenger %s (ID: %d) checked in.\n", name, newNode->p.id);
}


void dequeue() {
    if (isEmpty()) {
        printf("No passengers in queue!\n");
        return;
    }
    Node* temp = front;
    printf("Passenger %s (ID: %d) is being served.\n", temp->p.name, temp->p.id);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}


void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Current Queue:\n");
    Node* temp = front;
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->p.id, temp->p.name);
        temp = temp->next;
    }
}


int main() {
    int choice;
    char name[20];

    do {
        printf("\n--- Airport Check-in Menu ---\n");
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
                enqueue(name);
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

    return 0;
}
