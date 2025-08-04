#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 400  

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

int main() {
    int arr[SIZE];
    srand(time(0));  

    generateRandom(arr, SIZE);
    writeToFile("inRand.txt", arr, SIZE);

    qsort(arr, SIZE, sizeof(int), compareAsc);
    writeToFile("inAsce.txt", arr, SIZE);

    qsort(arr, SIZE, sizeof(int), compareDesc);
    writeToFile("inDesc.txt", arr, SIZE);

    printf("Files generated: inRand.txt, inAsce.txt, inDesc.txt with %d elements\n", SIZE);
    return 0;
}

