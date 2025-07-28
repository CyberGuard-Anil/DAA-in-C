#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 4) {
        printf("Usage: %s <size> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *in = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "w");

    if (!in || !out) 
    {
        printf("Error opening files.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        fscanf(in, "%d", &arr[i]);
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) 
    {
        fprintf(out, "%d ", arr[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}

