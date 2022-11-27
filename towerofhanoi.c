#include<stdio.h>
int tower(int n,char source[15],char destination[15],char temp[15]){
    if(n==0){
        return;
    }
    tower(n-1,source,temp,destination);
    printf("\n Disk %d is moved from %s to %s",n,source,destination);
    tower(n-1,temp,destination,source);
    }
    int main(){
        tower(3,"source","destination","temp");
        return 0;
    }