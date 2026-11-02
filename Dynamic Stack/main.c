#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push Operation
void push() {
    struct Node *newNode;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Element pushed successfully!\n");
}

// Pop Operation
void pop() {
    struct Node *temp;

    if(top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

// Display Operation
void display() {
    struct Node *temp = top;

    if(top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack elements:\n");

    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- DYNAMIC STACK ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                while(top != NULL)
                    pop();
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}