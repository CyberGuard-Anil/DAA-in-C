#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int *arr, int l, int r) 
{
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
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

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) 
    {
        fprintf(out, "%d ", arr[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}

