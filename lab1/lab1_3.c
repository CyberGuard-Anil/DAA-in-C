#include <stdio.h>

int main() 
{
    FILE *infile, *outfile;
    int n, i, j;

    infile = fopen("input3.txt", "r");
    outfile = fopen("output3.txt", "w");  

    if (infile == NULL || outfile == NULL) 
    {
        printf("File open error\n");
        return 1;
    }

    fscanf(infile, "%d", &n);
    int arr[n];
    int freq[n];

    for (i = 0; i < n; i++) 
    {
        freq[i] = -1;
    }

    for (i = 0; i < n; i++) 
    {
        fscanf(infile, "%d", &arr[i]);
    }

    fclose(infile);

    for (i = 0; i < n; i++) 
    {
        if (freq[i] == -1) 
        {
            int count = 1;
            for (j = i + 1; j < n; j++) 
            {
                if (arr[i] == arr[j]) 
                {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
        }
    }

    fprintf(outfile, "Array: ");
    for (i = 0; i < n; i++) 
    {
        fprintf(outfile, "%d ", arr[i]);
    }
    fprintf(outfile, "\n");

    int duplicate_count = 0;
    int max_freq = 0;
    int most_repeating = -1;

    for (i = 0; i < n; i++) 
 
    {
        if (freq[i] > 1) 
        {
            duplicate_count++;
        }
        if (freq[i] > max_freq) 
        {
            max_freq = freq[i];
            most_repeating = arr[i];
        }
    }

    fprintf(outfile, "Total number of duplicate values = %d\n", duplicate_count);
    fprintf(outfile, "The most repeating element in the array = %d\n", most_repeating);
    fclose(outfile);

    printf("Done! \nCheck output3.txt\n");
    return 0;
}

