#include <stdio.h>     
void shellSort(int array[], int n) {
    int i, j, gap, temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
} 
void printArray(int a[], int n)   
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("\t%d", a[i]);  
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
    shellSort(arr, n);
    printf("\nSorted array in Acsending Order:\n");
    printArray(arr, n);  
    return 0;
}  