#include<stdio.h>
#include<stdlib.h>
int main(){
    char *ptr;
    ptr=(char)malloc(30);
    strcpy(*ptr,"RAM");
    printf("%s",*ptr);
    free(ptr);
    return 0;
}