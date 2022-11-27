// #include<stdio.h>
// #include<conio.h>
// int main(){
//     int n;
//     printf("Enter number\n");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//     printf(" %d",fibo(i));
//     }
//     return 1;


// }
// int fibo(int n){
//     if(n==0){
//         return 0;
//     }
//     else if(n==1){
//         return 1;
//     }
//     else{
//         return fibo(n-2)+fibo(n-1);
//     }
// }
#include<stdio.h>
#include<conio.h>
int main(){
    int n,t0=0,t1=1,t2;
    printf("Enter number\n");
    scanf("%d",&n);
    printf(" %d %d",t0,t1);
    for(int i=1;i<n-1;i++){
        t2=t1+t0;
        printf(" %d",t2);
        t0=t1;
        t1=t2;
    }
    return 1;


}
