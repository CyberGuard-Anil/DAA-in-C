#include <stdio.h>

// Function to swap two numbers
void EXCHANGE(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to right-rotate first p2 elements of the array
void ROTATE_RIGHT(int *arr, int p2) {
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&arr[i], &arr[i - 1]);
    }
}

int main() {
    FILE *infile = fopen("input4.txt", "r");
    FILE *outfile = fopen("output4.txt", "w");

    if (infile == NULL || outfile == NULL) {
        printf("Error: Cannot open input or output file.\n");
        return 1;
    }

    int n;
    fscanf(infile, "%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        fscanf(infile, "%d", &arr[i]);
    }

    int p2;
    fscanf(infile, "%d", &p2); // Number of elements to rotate

    // Write original array to output
    fprintf(outfile, "Before ROTATE: ");
    for (int i = 0; i < n; i++) {
        fprintf(outfile, "%d ", arr[i]);
    }
    fprintf(outfile, "\n");

    // Rotate first p2 elements
    if (p2 > 1 && p2 <= n) {
        ROTATE_RIGHT(arr, p2);
    }

    // Write modified array to output
    fprintf(outfile, "After ROTATE: ");
    for (int i = 0; i < n; i++) {
        fprintf(outfile, "%d ", arr[i]);
    }
    fprintf(outfile, "\n");

    fclose(infile);
    fclose(outfile);

    printf("Program executed successfully. Check output4.txt for result.\n");

    return 0;
}

