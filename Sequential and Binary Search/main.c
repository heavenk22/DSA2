#include <stdio.h>
#include <string.h>

int main() {
    char names[50][50], key[50], temp[50];
    int n, i, j, found = 0;
    int low, high, mid;

    printf("Enter number of contacts: ");
    scanf("%d", &n);

    printf("Enter contact names:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    printf("Enter name to search: ");
    scanf("%s", key);

    // Sequential Search
    for(i = 0; i < n; i++) {
        if(strcmp(names[i], key) == 0) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Sequential Search: Contact found at position %d\n", i+1);
    else
        printf("Sequential Search: Contact not found\n");

    // Sorting names for Binary Search
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(strcmp(names[j], names[j+1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }

    // Binary Search
    low = 0;
    high = n-1;
    found = 0;

    while(low <= high) {
        mid = (low + high) / 2;

        if(strcmp(names[mid], key) == 0) {
            found = 1;
            break;
        }
        else if(strcmp(names[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found)
        printf("Binary Search: Contact found at position %d\n", mid+1);
    else
        printf("Binary Search: Contact not found\n");

    return 0;
}