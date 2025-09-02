#include<stdio.h>
int main(){
    int a,b,resulte1,resulte2,resulte3;
    float resulte4;
    printf("Enter number 1(it must be real number): ");
    scanf("%d",&a);
    printf("Enter number 2(it must be real number): ");
    scanf("%d",&b);

    resulte1 = a + b;
    printf("%d + %d = %d\n",a,b,resulte1);
    resulte2 =a - b;
    printf("%d - %d = %d\n",a,b,resulte2);
    resulte3 =a * b;
    printf("%d * %d = %d\n",a,b,resulte3);
   if (b ==0)
   {
    printf("error");
   }
   
   else
   {
    resulte4 = a / b;
    printf("%d / %d = %.2f\n",a,b,resulte4);

   }
    
    return 0;
}