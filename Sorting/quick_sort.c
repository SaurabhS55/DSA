#include <stdio.h>
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high)
{
  // int pivot = array[high];
  // int i = (low - 1);
  // for (int j = low; j < high; j++)
  // {
  //   if (array[j] <= pivot)
  //   {
  //     i++;
  //     swap(&array[i], &array[j]);
  //   }
  // }
  // swap(&array[i + 1], &array[high]);
  // return (i + 1);
  int i = low+1;
  int j = high;
  int pivot = array[low];
  do{
    while(array[i] <= pivot){
      i++;
    }
    while(array[j] > pivot){
      j--;
    }
    if(i < j){
      swap(&array[i], &array[j]);
    }
  }while (i < j);
  swap(&array[low],&array[j]);
  return j;
}
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
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
  quickSort(arr, 0, n - 1);
  printf("\nSorted array in Acsending Order:\n");
  printArray(arr, n);
}