#include <stdio.h>

int findMax(int arr[], int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int arr[] = {5, 2, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxElement = findMax(arr, size);

    printf("The maximum element in the array is: %d\n", maxElement);

    return 0;
}
