#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to insert a new node at the end of the linked list
void insert(struct Node** start, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *start;
    new_node->data = data;
    new_node->next = NULL;
    if (*start == NULL) {
        *start = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
// Function to find the last node whose position (n) is a multiple of k
struct Node* findLastNode(struct Node* start, int k) {
    if (start == NULL || k <= 0) {
        return NULL;
    }
    struct Node* result = NULL;
    int n = 0;
    for (struct Node* current = start; current != NULL; current = current->next) {
        n++;
        if (n % k == 0) {
            result = current;
        }
    }
    return result;
}
int main() {
    struct Node* start = NULL; 
    int k, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Take input for the linked list
    int data;
    printf("Enter %d elements for the linked list:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insert(&start, data);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Linked List: ");
    struct Node* result = findLastNode(start, k);
    if (result != NULL) {
        printf("Output: %d\n", result->data);
    } else {
        printf("No node found.\n");
    }
    return 0;
}
