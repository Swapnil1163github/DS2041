#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insert(struct Node** start, int data) {
    // Implementation of the insert function
    // ...
}

// Function to find the last node whose position (n) is a multiple of k
struct Node* findLastNode(struct Node* start, int k) {
    // Implementation of the findLastNode function
    // ...
}

int main() {
    // Declaration and initialization of variables
    struct Node* start = NULL;
    int k, n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Take input for the linked list
    int data;
    printf("Enter %d elements for the linked list:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insert(&start, data);
    }

    // Input the value of k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Display the linked list
    printf("Linked List: ");

    // Call the findLastNode function
    struct Node* result = findLastNode(start, k);

    // Output the result
    if (result != NULL) {
        printf("Output: %d\n", result->data);
    } else {
        printf("No node found.\n");
    }

    return 0;
}
