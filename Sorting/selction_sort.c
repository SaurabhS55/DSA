#include <stdio.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selectionSort(int array[], int size)
{
  for (int step = 0; step < size - 1; step++)
  {
    int min_idx = step;
    for (int i = step + 1; i < size; i++)
    {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
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
  selectionSort(arr, n);
  printf("\n Sorted array in Acsending Order:\n");
  printArray(arr, n);
}