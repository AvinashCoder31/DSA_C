#include <stdio.h>

void Radixsort(int a[], int n);

void main() {
    int x[20], i, n;
    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d", &n);
    printf("\nEnter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    Radixsort(x, n);
    printf("\nThe sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
}

void Radixsort(int a[], int n) {
    int bucket[10][10], buck[10]; 
    int i, j, k, l, num, div, large, pass;
    div = 1;
    num = 0;
    large = a[0];
    
    // Find the largest number
    for (i = 1; i < n; i++) {
        if (a[i] > large) {
            large = a[i];
        }
    }
    
    // Find how many digits the largest number has
    while (large > 0) {
        num++;
        large = large / 10;
    }
    
    // Perform sorting based on each digit
    for (pass = 0; pass < num; pass++) {
        // Initialize the bucket count
        for (k = 0; k < 10; k++) {
            buck[k] = 0;
        }
        
        // Distribute into buckets based on the current digit
        for (i = 0; i < n; i++) {
            l = (a[i] / div) % 10;
            bucket[l][buck[l]] = a[i];
            buck[l]++;
        }
        
        // Print buckets for each digit place
        printf("\nBuckets for digit place %d (div = %d):\n", pass+1, div);
        for (k = 0; k < 10; k++) {
            printf("Bucket %d: ", k);
            for (j = 0; j < buck[k]; j++) {
                printf("%d ", bucket[k][j]);
            }
            printf("\n");
        }
        
        // Collect back into array
        i = 0;
        for (k = 0; k < 10; k++) {
            for (j = 0; j < buck[k]; j++) {
                a[i++] = bucket[k][j];
            }
        }
        
        // Print array after sorting by current digit
        printf("\nArray after sorting by digit place %d: ", pass+1);
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        
        // Move to next digit place
        div = div * 10;
    }
}
_