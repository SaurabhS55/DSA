#include<stdio.h>
#include<stdlib.h>
int ackermann(int,int);
int main(){
    int m,n,r;
    printf("Enter two no.s");
    scanf("%d%d",&m,&n);
    r=ackermann(m,n);
    printf("Ackermann number of %d and %d is %d",m,n,r);
}
int ackermann(int m,int n){
    if(m==0){
        return n+1;
    }
    else if(m>0 && n==0){
        return ackermann(m-1,1);
    }
    else if(m>0 && n>0){
        return ackermann(m-1,ackermann(m,n-1));
    }
    else{
        return -1;
    }
}