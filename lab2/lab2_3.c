#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

void findPairsNlogN(int *arr, int n, int target, FILE *out) 
{
    fprintf(out, "Pairs with sum %d using O(n log n) approach:\n", target);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    while (left < right) 
    {
        int sum = arr[left] + arr[right];
        if (sum == target) 
        {
            fprintf(out, "%d %d\n", arr[left], arr[right]);
            left++;
            right--;
        } else if (sum < target) 
        {
            left++;
        } else {
            right--;
        }
    }

    fprintf(out, "\n");
}

void findPairsON(int *arr, int n, int target, FILE *out) 
{
    fprintf(out, "Pairs with sum %d using O(n) approach:\n", target);

    int hash[10000] = {0}; 
    for (int i = 0; i < n; i++) 
    {
        int complement = target - arr[i];
        if (complement >= 0 && hash[complement]) 
        {
            fprintf(out, "%d %d\n", arr[i], complement);
        }
        hash[arr[i]] = 1;
    }

    fprintf(out, "\n");
}

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        printf("Usage: %s <input_file> <output_file> <target_sum>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int target = atoi(argv[3]);

    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (in == NULL || out == NULL) 
    {
        printf("Error: Cannot open files.\n");
        return 1;
    }

    int arr[1000], n = 0;
    while (fscanf(in, "%d", &arr[n]) == 1 && n < 1000) 
    
    {
        n++;
    }

    findPairsNlogN(arr, n, target, out);
    findPairsON(arr, n, target, out);

    fclose(in);
    fclose(out);

    printf("Done! Check %s for output.\n", output_file);
    return 0;
}

