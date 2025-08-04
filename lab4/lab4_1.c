#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n, FILE *f) {
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", arr[i]);
    fprintf(f, "\n");
}

int main() {
    int choice, n = 0, arr[1000];
    char *inputFile, *outputFile;

    printf("Menu:\n");
    printf("1. Ascending input\n");
    printf("2. Descending input\n");
    printf("3. Random input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputFile = "inAsce.txt";
            outputFile = "outMergeAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outMergeDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outMergeRand.txt";
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    FILE *in = fopen(inputFile, "r");
    if (!in) {
        printf("Cannot open input file %s\n", inputFile);
        return 1;
    }

    while (fscanf(in, "%d", &arr[n]) == 1 && n < 1000)
        n++;
    fclose(in);

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        printf("Cannot open output file %s\n", outputFile);
        return 1;
    }

    fprintf(out, "Before Sorting:\n");
    printArray(arr, n, out);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(arr, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);
    long time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

    fprintf(out, "After Sorting:\n");
    printArray(arr, n, out);

    fprintf(out, "Number of Comparisons: %d\n", comparisons);
    fprintf(out, "Execution Time: %ld nanoseconds\n", time_ns);

    fclose(out);
    printf("Sorting complete. Output written to %s\n", outputFile);
    return 0;
}

