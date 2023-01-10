#include <stdio.h>
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("\t%d", array[i]);
    }
    printf("\n");
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
    bubbleSort(arr, n);
    printf("\nSorted array in Acsending Order:\n");
    printArray(arr, n);
}