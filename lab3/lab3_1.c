#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) 
    {
        fprintf(out, "%d ", arr[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}

