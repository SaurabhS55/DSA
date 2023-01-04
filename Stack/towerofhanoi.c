#include <stdio.h>
#include <stdlib.h>
int tower(int,char*,char*,char*);
int main()
{
    printf("\n Enter number of Disks");
    int n;
    scanf("%d",&n);
    tower(n, "source", "destination", "temp");
    return 0;
}
int tower(int n, char *s, char *d, char *t)
{
    if (n == 0)
    {
        return -1;
    }
    tower(n - 1, s, t, d);
    printf("\n Disk %d is moved from %s to %s", n, s, d);
    tower(n - 1, t, d, s);
}