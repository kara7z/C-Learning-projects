#include<stdio.h>
int main(){
    int a,b,resulte1,resulte2,resulte3,resulte4;
    printf("Enter number 1(it must be real number): ");
    scanf("%d",&a);
    printf("Enter number 2(it must be real number): ");
    scanf("%d",&a);

    resulte1 = a+b;
    printf("%d + %d= %d\n",a,b,resulte1);
    resulte2 =a-b;
    printf("%d - %d= %d\n",a,b,resulte2);
    resulte3 =a*b;
    printf("%d * %d= %d\n",a,b,resulte3);
    resulte4 =a/b;
    printf("%d / %d= %d\n",a,b,resulte4);

    
    return 0;
}