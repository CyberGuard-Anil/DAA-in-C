#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparisons = 0; // global comparison counter

// Quick Sort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            comparisons++;
            if (arr[j] <= pivot) {
                int temp = arr[++i];
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

// Generate ascending array
void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i + 1;
}

// Generate descending array
void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = n - i;
}

// Generate random array
void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
}

// Display first few elements (for brevity)
void displaySample(int arr[], int n) {
    int limit = n < 20 ? n : 20;
    for (int i = 0; i < limit; i++) printf("%d ", arr[i]);
    if (n > 20) printf("...");
    printf("\n");
}

int main() {
    srand(time(NULL));
    int option;
    int sizes[] = {1000, 2000, 3000, 4000};
    int numSets = 4;

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

    printf("\n%-10s %-15s %-15s %-20s %-15s\n", "Size", "BeforeSort", "AfterSort", "Time(sec)", "Comparisons");
    printf("---------------------------------------------------------------------------------------\n");

    for (int s = 0; s < numSets; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));

        if (option == 1) generateAscending(arr, n);
        else if (option == 2) generateDescending(arr, n);
        else if (option == 3) generateRandom(arr, n);
        else {
            printf("Invalid option!\n");
            free(arr);
            return 0;
        }

        // Display before sorting
        printf("%-10d ", n);
        displaySample(arr, n);

        // Sorting
        comparisons = 0;
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Display after sorting
        printf("%-10s ", "");
        displaySample(arr, n);

        // Summary row
        printf("%-10s %-15s %-15s %-20f %-15ld\n", "", "", "", timeTaken, comparisons);

        free(arr);
    }

    // Print scenario
    if (option == 1) printf("\nScenario: Best-case\n");
    else if (option == 2) printf("\nScenario: Worst-case\n");
    else printf("\nScenario: Average-case\n");

    return 0;
}

