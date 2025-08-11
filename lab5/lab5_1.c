#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) 
        {
            if (arr[j] <= pivot) 
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 100000; 
    }
}

void copyArray(int src[], int dest[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        dest[i] = src[i];
    }
}

void reverseArray(int arr[], int n) 
{
    for (int i = 0; i < n / 2; i++) 
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() 
{
    srand(time(NULL)); 

    int sizes[] = {1000, 2000, 3000, 4000};
    int numSets = 4;

    printf("Size\tBestCase(sec)\tWorstCase(sec)\n");

    for (int s = 0; s < numSets; s++) 
    {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        int *tempArr = (int *)malloc(n * sizeof(int));

        
        generateRandomArray(arr, n);

        
        copyArray(arr, tempArr, n);
        quickSort(tempArr, 0, n - 1); 
        clock_t start = clock();
        quickSort(tempArr, 0, n - 1); 
        clock_t end = clock();
        double bestTime = ((double)(end - start)) / CLOCKS_PER_SEC;

       
        reverseArray(tempArr, n); 
        start = clock();
        quickSort(tempArr, 0, n - 1);
        end = clock();
        double worstTime = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%f\t%f\n", n, bestTime, worstTime);

        free(arr);
        free(tempArr);
    }

    return 0;
}

