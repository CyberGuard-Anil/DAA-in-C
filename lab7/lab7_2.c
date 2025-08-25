#include <stdio.h>
#include <stdlib.h>


struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left, *right;
};


struct SYMBOL* createNode(char alphabet, int frequency) {
    struct SYMBOL* newNode = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
    newNode->alphabet = alphabet;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void swap(struct SYMBOL** a, struct SYMBOL** b) {
    struct SYMBOL* temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(struct SYMBOL* heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left]->frequency < heap[smallest]->frequency)
        smallest = left;
    if (right < size && heap[right]->frequency < heap[smallest]->frequency)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}


struct SYMBOL* extractMin(struct SYMBOL* heap[], int* size) {
    struct SYMBOL* root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return root;
}


void insertHeap(struct SYMBOL* heap[], int* size, struct SYMBOL* node) {
    heap[*size] = node;
    int i = *size;
    (*size)++;

    while (i != 0 && heap[(i - 1) / 2]->frequency > heap[i]->frequency) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


struct SYMBOL* buildHuffmanTree(char alphabets[], int freq[], int n) {
    struct SYMBOL* heap[n * 2]; // heap array
    int size = 0;


    for (int i = 0; i < n; i++) {
        heap[size] = createNode(alphabets[i], freq[i]);
        size++;
    }


    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(heap, size, i);


    while (size > 1) {
        struct SYMBOL* left = extractMin(heap, &size);
        struct SYMBOL* right = extractMin(heap, &size);

        struct SYMBOL* parent = createNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        insertHeap(heap, &size, parent);
    }


    return heap[0];
}


void inorderTraversal(struct SYMBOL* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    if (root->alphabet != '$')  
        printf("%c ", root->alphabet);
    inorderTraversal(root->right);
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    char alphabets[n];
    int freq[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &alphabets[i]);  
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    struct SYMBOL* root = buildHuffmanTree(alphabets, freq, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

