#include <stdio.h>

void deleteKSmallerElements(int arr[], int n, int k) {
    int stack[n]; // Create a stack to store elements
    int top = -1; // Initialize the top of the stack

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the stack is not empty and k is greater than 0
        while (top != -1 && k > 0 && stack[top] < arr[i]) {
            top--; // Pop elements from the stack
            k--;   // Decrement k
        }
        stack[++top] = arr[i]; // Push the current element onto the stack
    }

    // If k is still greater than 0, remove the remaining elements from the stack
    while (k > 0) {
        top--;
        k--;
    }

    // Print the modified array
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    deleteKSmallerElements(arr, n, k);

    return 0;
}
