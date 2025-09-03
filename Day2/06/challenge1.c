#include<stdio.h>
int main(){

int numberr;
    printf("enter numberr ");
    scanf("%d",&numberr);

    for (int i = 10; i >0; i--)
    {
        int result = i*numberr;
        printf("%d * %d = %d\n",i,numberr,result);
    }
    



    return 0;
}