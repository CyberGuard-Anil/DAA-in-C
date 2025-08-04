#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int comparisons = 0;

void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        comparisons++;
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(FILE *f, int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", arr[i]);
    fprintf(f, "\n");
}

char* detectCase(char* filename) 
{
    if (strstr(filename, "Asce")) return "Worst-case";
    if (strstr(filename, "Desc")) return "Best-case";
    return "Average-case";
}

int main() 
{
    int choice, n = 0, arr[1000];
    char *inputFile, *outputFile;

    printf("Menu:\n");
    printf("1. Ascending input\n");
    printf("2. Descending input\n");
    printf("3. Random input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            inputFile = "inAsce.txt";
            outputFile = "outQuickAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outQuickDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outQuickRand.txt";
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    FILE *in = fopen(inputFile, "r");
    if (!in) 
    {
        printf("Cannot open input file %s\n", inputFile);
        return 1;
    }

    while (fscanf(in, "%d", &arr[n]) == 1 && n < 1000)
        n++;
    fclose(in);

    FILE *out = fopen(outputFile, "w");
    if (!out) 
    {
        printf("Cannot open output file %s\n", outputFile);
        return 1;
    }

    fprintf(out, "Before Sorting:\n");
    printArray(out, arr, n);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    quickSort(arr, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);
    long time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

    fprintf(out, "After Sorting:\n");
    printArray(out, arr, n);
    fprintf(out, "Number of Comparisons: %d\n", comparisons);
    fprintf(out, "Scenario: %s\n", detectCase(outputFile));
    fprintf(out, "Execution Time: %ld nanoseconds\n", time_ns);

    fclose(out);
    printf("Sorting complete. Output written to %s\n", outputFile);
    return 0;
}

