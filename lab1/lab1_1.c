#include <stdio.h>
#include <limits.h>

int main() 
{
    FILE *infile, *outfile;
    int n, i;

    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Input file not found!\n");
        return 1;
    }

    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Unable to create output file!\n");
        fclose(infile);
        return 1;
    }

    fscanf(infile, "%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) 
    {
        fscanf(infile, "%d", &arr[i]);
    }

    fclose(infile);
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    int largest = INT_MIN;

    for (i = 0; i < n; i++) 
    {
        int val = arr[i];

        if (val > largest)
            largest = val;      
        if (val < smallest) 
        {
            second_smallest = smallest;
            smallest = val;
        } else if (val < second_smallest && val != smallest) 
        {
            second_smallest = val;
        }
    }

    if (second_smallest == INT_MAX)
        fprintf(outfile, "No second smallest element found \n");
    else
        fprintf(outfile, "Second smallest element = %d\n", second_smallest);

    fprintf(outfile, "Largest element = %d\n", largest);
    fclose(outfile);

    printf("Done! \nCheck output.txt\n");
    return 0;
}

