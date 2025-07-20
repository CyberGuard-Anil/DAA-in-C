#include <stdio.h>

void EXCHANGE(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void ROTATE_RIGHT(int *arr, int p2) 
{
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&arr[i], &arr[i - 1]);
    }
}

int main() 
{
    FILE *infile, *outfile;

    infile = fopen("input4.txt", "r");
    outfile = fopen("output4.txt", "w");

    if (infile == NULL || outfile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(infile, "%d", &n); 
    int arr[n];

    for (int i = 0; i < n; i++) {
        fscanf(infile, "%d", &arr[i]);
    }

    int p2;
    fscanf(infile, "%d", &p2); 
    fprintf(outfile, "Before ROTATE: ");
    for (int i = 0; i < n; i++) {
        fprintf(outfile, "%d ", arr[i]);
    }
    fprintf(outfile, "\n");

    ROTATE_RIGHT(arr, p2);


    fprintf(outfile, "After ROTATE: ");
    for (int i = 0; i < n; i++) {
        fprintf(outfile, "%d ", arr[i]);
    }
    fprintf(outfile, "\n");

    fclose(infile);
    fclose(outfile);

    printf("Done!\nCheck output4.txt\n");
    return 0;
}

