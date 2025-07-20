#include <stdio.h>

int main() 
{
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];

    prefixSum[0] = arr[0]; 

    for (int i = 1; i < n; i++) 
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    printf("Prefix Sum Array: ");
   
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", prefixSum[i]);
    }
    printf("\nLine separate nhi ho raha tha sir!\n");
    return 0;
}

