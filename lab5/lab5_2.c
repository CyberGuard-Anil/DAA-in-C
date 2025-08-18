#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparisons = 0; // For counting comparisons

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            comparisons++;
            if (arr[j] <= pivot) {
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

// Function to read file into array
int readFile(char *filename, int arr[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    int n = 0;
    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(fp);
    return n;
}

// Function to write array to file
void writeFile(char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int option;
    char inputFile[30], outputFile[30];
    int arr[10000];
    int n;

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 4) {
        printf("Exiting...\n");
        return 0;
    }

    // Select file based on option
    if (option == 1) {
        sprintf(inputFile, "ascending.txt");
    } else if (option == 2) {
        sprintf(inputFile, "descending.txt");
    } else if (option == 3) {
        sprintf(inputFile, "random.txt");
    } else {
        printf("Invalid option!\n");
        return 0;
    }

    // Read input file
    n = readFile(inputFile, arr);
    if (n == 0) return 0;

    printf("Before Sorting: ");
    displayArray(arr, n);

    // Sort
    comparisons = 0;
    quickSort(arr, 0, n - 1);

    printf("After Sorting: ");
    displayArray(arr, n);

    // Save to output file
    sprintf(outputFile, "output.txt");
    writeFile(outputFile, arr, n);

    printf("Number of Comparisons: %ld\n", comparisons);

    // Identify Scenario
    if (option == 1)
        printf("Scenario: Best-case\n");
    else if (option == 2)
        printf("Scenario: Worst-case\n");
    else
        printf("Scenario: Average-case\n");

    return 0;
}

