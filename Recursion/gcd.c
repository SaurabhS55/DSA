#include<stdio.h>
#include<conio.h>
int gcd(int,int);
int main(){
    int n1,n2;
    printf("Enter two numbers\n");
    scanf("%d %d",&n1,&n2);
    printf("GCD of %d nad %d = %d",n1,n2,gcd(n1,n2));
    return 0;

}
int gcd(int n1,int n2){
    if(n2!=0){
        return gcd(n2,n1%n2);
    }
    else{
        return n1;
    }
}