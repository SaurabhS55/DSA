#include <stdio.h>
#include <stdlib.h>
int binary_search(int arr[], int n, int ele)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (ele == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < ele)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
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
    int r = binary_search(arr, n, ele);
    (r == -1) ? printf("\n Element not found") : printf("\n Element found at %d", r);
    return 0;
}