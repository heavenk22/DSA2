#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *newNode, *temp;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Node inserted successfully!\n");
}

void delete() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void reverseDisplay(struct Node *temp) {
    if(temp == NULL)
        return;

    reverseDisplay(temp->next);
    printf("%d -> ", temp->data);
}

void reverse() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("List reversed successfully!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Reverse Display\n");
        printf("5. Reverse List\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Reverse Display: ");
                reverseDisplay(head);
                printf("NULL\n");
                break;

            case 5:
                reverse();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}