#include <stdio.h>
void merge(int arr[], int p, int q, int r)
{
    int i=p;
    int j=q+1;
    int k=p;
    int b[r];
    while(i<=q && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>q){
        while(j<=r)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=r)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    for(i=p;i<=r;i++){
        arr[i]=b[i];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("\t%d", arr[i]);
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
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array in Acsending Order:\n");
    printArray(arr, n);
}