#include <stdio.h>


void MergeSort(int[], int, int);
void Merge(int[], int, int, int);
void printArray(int[], int, int);
void printMergeStep(int[], int, int, int);

int main() {
    int x[20], i, n, order;

    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    // Asking user if they want ascending or descending order
    printf("\nEnter 1 for Ascending order, 2 for Descending order: ");
    scanf("%d", &order);

    // Sort the array
    MergeSort(x, 0, n - 1);

    // If descending order is chosen, reverse the array
    if (order == 2) {
        for (i = 0; i < n / 2; i++) {
            int temp = x[i];
            x[i] = x[n - i - 1];
            x[n - i - 1] = temp;
        }
        printf("\nArray sorted in descending order:\n");
    } else {
        printf("\nArray sorted in ascending order:\n");
    }

    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }


    return 0;
}

void MergeSort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;

        // Step-wise visualization: showing the split phase
        printf("\nDividing array from index %d to %d into subarrays:\n", p, r);
        printArray(a, p, r);

        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        Merge(a, p, q, r);

        // Visualization after merge
        printf("\nMerging subarrays from index %d to %d:\n", p, r);
        printArray(a, p, r);
    }
}

void Merge(int a[], int p, int q, int r) {
    int b[20], l1, r1, i;
    l1 = p;
    r1 = q + 1;
    i = p;

    while (l1 <= q && r1 <= r) {
        if (a[l1] < a[r1]) {
            b[i++] = a[l1++];
        } else {
            b[i++] = a[r1++];
        }
    }

    while (l1 <= q) {
        b[i++] = a[l1++];
    }

    while (r1 <= r) {
        b[i++] = a[r1++];
    }

    for (i = p; i <= r; i++) {
        a[i] = b[i];
    }

    // Show how the merge step worked
    printMergeStep(a, p, q, r);
}

// Function to print the array between two indices
void printArray(int arr[], int start, int end) {
    printf("Array segment: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print how merging is happening step by step
void printMergeStep(int arr[], int p, int q, int r) {
    printf("\nMerged segment from index %d to %d: ", p, r);
    for (int i = p; i <= r; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
