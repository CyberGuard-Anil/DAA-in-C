#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person 
{
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

struct person *arr;
int n = 0;  
int capacity = 100; 

void swap(struct person *a, struct person *b) 
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int i) 
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l].age < arr[smallest].age)
        smallest = l;
    if(r < n && arr[r].age < arr[smallest].age)
        smallest = r;

    if(smallest != i) 
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(smallest);
    }
}

void maxHeapify(int i) 
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l].weight > arr[largest].weight)
        largest = l;
    if(r < n && arr[r].weight > arr[largest].weight)
        largest = r;

    if(largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(largest);
    }
}

void buildMinHeap() 
{
    for(int i = n/2 - 1; i >= 0; i--) 
    {
        minHeapify(i);
    }
}

void buildMaxHeap() 
{
    for(int i = n/2 - 1; i >= 0; i--) 
    {
        maxHeapify(i);
    }
}

void insertMinHeap(struct person p) {
    arr[n] = p;
    int i = n;
    n++;

    while(i != 0 && arr[(i-1)/2].age > arr[i].age) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}
void deleteOldest() 
{
    int oldestIndex = 0;
    for(int i=1; i<n; i++) 
    {
        if(arr[i].age > arr[oldestIndex].age)
            oldestIndex = i;
    }
    printf("Deleted: %s (Age: %d)\n", arr[oldestIndex].name, arr[oldestIndex].age);
    arr[oldestIndex] = arr[n-1];
    n--;
    buildMinHeap();
}

void display() 
{
    printf("ID   %-10s Age  Height  Weight\n", "Name");
    for(int i=0; i<n; i++) 
    {
        printf("%-4d %-10s %-4d %-6d %-6d\n",
               arr[i].id,
               arr[i].name,
               arr[i].age,
               arr[i].height,
               arr[i].weight);
    }
}


void readData(char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if(!fp) 
    {
        printf("Error opening file!\n");
        return;
    }
    while(fscanf(fp, "%d %s %d %d %d", &arr[n].id, arr[n].name, &arr[n].age, &arr[n].height, &arr[n].weight) != EOF) {
        n++;
    }
    fclose(fp);
    printf("Data Loaded Successfully!\n");
    display();
}

void youngestWeight() {
    int idx = 0;
    for(int i=1; i<n; i++) {
        if(arr[i].age < arr[idx].age)
            idx = i;
    }
    printf("Weight of youngest student: %.2f kg\n", arr[idx].weight * 0.453592); 
}

int main() {
    arr = (struct person *)malloc(capacity * sizeof(struct person));

    int choice;
    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on age\n");
        printf("3. Create a Max-heap based on weight\n");
        printf("4. Display weight of youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if(choice == 1) {
            readData("students.txt");  
        } else if(choice == 2) {
            buildMinHeap();
            printf("Min-Heap created (by Age)\n");
            display();
        } else if(choice == 3) {
            buildMaxHeap();
            printf("Max-Heap created (by Weight)\n");
            display();
        } else if(choice == 4) {
            youngestWeight();
        } else if(choice == 5) {
            struct person p;
            printf("Enter id name age height weight: ");
            scanf("%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight);
            insertMinHeap(p);
            printf("Inserted Successfully!\n");
            display();
        } else if(choice == 6) {
            deleteOldest();
            display();
        }
    } while(choice != 7);

    free(arr);
    return 0;
}

