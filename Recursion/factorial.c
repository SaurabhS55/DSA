#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int fact(int);
int main(){
    int n,f;
    printf("Enter number");
    scanf("%d",&n);
    f=fact(n);
    printf("Factorial= %d",f);
    return 0;

}
int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*fact(n-1);
    }

}