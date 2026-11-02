#include <stdio.h>

int main() {
    int n, i, j, temp;
    float a[50], b[50], c[50];

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &a[i]);
        b[i] = c[i] = a[i];
    }

    // Bubble Sort
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // Selection Sort
    for(i = 0; i < n-1; i++) {
        int min = i;
        for(j = i+1; j < n; j++) {
            if(b[j] < b[min])
                min = j;
        }

        temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }

    // Insertion Sort
    for(i = 1; i < n; i++) {
        float key = c[i];
        j = i-1;

        while(j >= 0 && c[j] > key) {
            c[j+1] = c[j];
            j--;
        }
        c[j+1] = key;
    }

    printf("\nBubble Sort: ");
    for(i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    printf("\nSelection Sort: ");
    for(i = 0; i < n; i++)
        printf("%.2f ", b[i]);

    printf("\nInsertion Sort: ");
    for(i = 0; i < n; i++)
        printf("%.2f ", c[i]);

    return 0;
}