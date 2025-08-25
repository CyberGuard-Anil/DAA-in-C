#include <stdio.h>

struct ITEM 
{
    int item_id;
    float profit;
    float weight;
    float ratio;
};


void swap(struct ITEM *a, struct ITEM *b) 
{
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct ITEM arr[], int n, int i) 
{
    int largest = i;        
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  

 
    if (left < n && arr[left].ratio > arr[largest].ratio)
        largest = left;
    if (right < n && arr[right].ratio > arr[largest].ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(struct ITEM arr[], int n) 
{
 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) \
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

    for (int i = 0; i < n / 2; i++) 
    {
        swap(&arr[i], &arr[n - i - 1]);
    }
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].item_id = i + 1;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    heapSort(items, n);

    float totalProfit = 0.0;
    float amountTaken[n];

    for (int i = 0; i < n; i++)
        amountTaken[i] = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) 
        {
        
            amountTaken[i] = 1.0;
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else 
        {
            amountTaken[i] = capacity / items[i].weight;
            totalProfit += items[i].profit * amountTaken[i];
            capacity = 0;
            break;
        }
    }


    printf("\nItem No\tProfit\t\tWeight\t\tAmount to be taken\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%f\t%f\t%f\n", items[i].item_id,
               items[i].profit, items[i].weight, amountTaken[i]);
    }

    printf("Maximum profit: %f\n", totalProfit);

    return 0;
}

