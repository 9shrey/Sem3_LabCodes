#include <stdio.h>

void deleteKSmallerElements(int arr[], int n, int k) {
    int stack[n]; 
    int top = -1; 

    
    for (int i = 0; i < n; i++) {
        while (top != -1 && k > 0 && stack[top] < arr[i]) {
            top--; 
            k--;   
        }
        stack[++top] = arr[i]; 
    }

   
    while (k > 0) {
        top--;
        k--;
    }
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
