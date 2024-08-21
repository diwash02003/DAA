#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman Tree
typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// A Min Heap
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

// Function to create a new MinHeapNode
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to create a MinHeap
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Function to swap two MinHeapNodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if size of heap is 1
int isSizeOne(MinHeap* minHeap) {
    return minHeap->size == 1;
}

// Function to extract minimum value node from heap
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a node to MinHeap
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build the MinHeap
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to check if this node is leaf
int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Function to print the Huffman codes from the root of Huffman Tree
void printCodes(MinHeapNode* root, int arr[], int top, char* code[]) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, code);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, code);
    }
    if (isLeaf(root)) {
        code[(unsigned char)root->data] = (char*)malloc(top + 1);
        for (int i = 0; i < top; ++i)
            code[(unsigned char)root->data][i] = arr[i] == 1 ? '1' : '0';
        code[(unsigned char)root->data][top] = '\0';
    }
}

// Function to build Huffman Tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to print the binary representation of a string
void printBinaryRepresentation(const char* str) {
    printf("Original Binary Representation:\n");
    while (*str) {
        printf("%c: %d\n", *str, *str);
        ++str;
    }
}

// Function to print encoded string using Huffman codes
void printEncodedString(const char* str, char* code[]) {
    printf("\nEncoded String:\n");
    while (*str) {
        if (code[(unsigned char)*str]) {
            printf("%s", code[(unsigned char)*str]);
        }
        ++str;
    }
    printf("\n");
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    int freq[] = { 5, 9, 12, 13, 16, 45, 7, 6 };
    int size = sizeof(data) / sizeof(data[0]);

    // Build Huffman Tree and print codes
    MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Initialize Huffman codes
    char* code[256] = {0}; // Array to hold Huffman codes for each character
    int arr[100];
    printf("Huffman Codes:\n");
    printCodes(root, arr, 0, code);

    // Print original binary representation
    printBinaryRepresentation("abcdefgh");

    // Print encoded string using Huffman codes
    printEncodedString("abcdefgh", code);

    // Free allocated memory
    for (int i = 0; i < 256; ++i) {
        if (code[i]) {
            free(code[i]);
        }
    }

    return 0;
}
