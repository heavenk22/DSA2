#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char name[]) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;

    return newNode;
}

// Insert a name
struct Node* insert(struct Node *root, char name[]) {
    if(root == NULL)
        return createNode(name);

    if(strcmp(name, root->name) < 0)
        root->left = insert(root->left, name);
    else if(strcmp(name, root->name) > 0)
        root->right = insert(root->right, name);

    return root;
}

// Inorder Traversal
void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%s ", root->name);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node *root) {
    if(root != NULL) {
        printf("%s ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->name);
    }
}

// Search a name
void search(struct Node *root, char key[]) {
    if(root == NULL) {
        printf("Name not found!\n");
        return;
    }

    if(strcmp(key, root->name) == 0) {
        printf("Name found: %s\n", root->name);
    }
    else if(strcmp(key, root->name) < 0) {
        search(root->left, key);
    }
    else {
        search(root->right, key);
    }
}

int main() {
    struct Node *root = NULL;
    int choice;
    char name[50];

    while(1) {
        printf("\n\n--- BINARY SEARCH TREE ---\n");
        printf("1. Insert Name\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Name\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%49s", name);
                root = insert(root, name);
                printf("Name inserted successfully!\n");
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                break;

            case 5:
                printf("Enter name to search: ");
                scanf("%49s", name);
                search(root, name);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}