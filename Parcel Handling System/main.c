#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addParcel() {
    int parcel;

    if(rear == MAX - 1) {
        printf("Queue is Full!\n");
    }
    else {
        printf("Enter Parcel ID: ");
        scanf("%d", &parcel);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = parcel;

        printf("Parcel added successfully!\n");
    }
}

void deleteParcel() {
    if(front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    }
    else {
        printf("Deleted Parcel ID: %d\n", queue[front]);
        front++;

        if(front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    int i;

    if(front == -1) {
        printf("No parcels available!\n");
    }
    else {
        printf("Parcels in Queue:\n");

        for(i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- POST OFFICE PARCEL SYSTEM ---\n");
        printf("1. Add Parcel\n");
        printf("2. Delete Parcel\n");
        printf("3. Display Parcels\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addParcel();
                break;

            case 2:
                deleteParcel();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}