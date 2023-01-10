#include <stdio.h>
#include <stdlib.h>
#define max 10
int linear_search(int arr[], int n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
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
    printf("\nEnter searching element: ");
    scanf("%d", &ele);
    int r = linear_search(arr, n, ele);
    (r == -1) ? printf("\n Element not found") : printf("\n Element found at %d", r);
    return 0;
}