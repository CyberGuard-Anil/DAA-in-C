#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandom(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;  
}

void writeToFile(const char *filename, int arr[], int n) 
{
    FILE *f = fopen(filename, "w");
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", arr[i]);
    fprintf(f, "\n");
    fclose(f);
}

int compareAsc(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void *a, const void *b) 
{
    return (*(int*)b - *(int*)a);
}

int main() 
{
    int size;
    printf("Enter number of elements to generate (recommended: 300–500): ");
    scanf("%d", &size);

    if (size <= 0 || size > 10000) 
    {
        printf("Invalid size. Please enter a positive number under 10,000.\n");
        return 1;
    }

    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(0));  
    generateRandom(arr, size);
    writeToFile("inRand.txt", arr, size);

    qsort(arr, size, sizeof(int), compareAsc);
    writeToFile("inAsce.txt", arr, size);

    qsort(arr, size, sizeof(int), compareDesc);
    writeToFile("inDesc.txt", arr, size);

    printf("Files generated:\n");
    printf("• inRand.txt (random)\n");
    printf("• inAsce.txt (sorted ascending)\n");
    printf("• inDesc.txt (sorted descending)\n");

    free(arr);
    return 0;
}

