#include<stdio.h>
#include<stdlib.h>
// #define max 40
int length(int*,int);
int main(){
    printf("\n Enter list");
    int *l;
    for(int i=0;l[i];++i){
        scanf("%d",&l[i]);
    }
    // printf("%d",*l);
    printf("length of list= %d",length(l,0));
    return 0;
}
int length(int *l,int  n){
    int s=sizeof(l)/sizeof(l[0]);
    if(s==0){
        return n;
    }
    else{
        // int j=0;
        for(int i=0;i<s-1;i++){
            l[i]=l[i++];
        }
        return length(l,n+1);
    }
}