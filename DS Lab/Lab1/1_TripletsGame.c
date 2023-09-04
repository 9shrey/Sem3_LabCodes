#include <stdio.h>

int main()
{
    int a[100], n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Input elements in the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Triplets with a sum of 0:\n");

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] == 0)
                {
                    printf("%d %d %d\n", a[i], a[j], a[k]);
                }
            }
        }
    }

    return 0;
}
