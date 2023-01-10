#include <stdio.h>
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\t%d", array[i]);
    }
    printf("\n");
}
void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
int main()
{
    int n;
    printf("\n Enter size of array: ");
    scanf("%d", &n);
    int arr[n], ele;
    printf("\n Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Sorted array in Acsending Order:\n");
    printArray(arr, n);
    return 0;
}