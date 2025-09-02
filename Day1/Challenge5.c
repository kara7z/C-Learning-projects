#include<stdio.h>
int main(){
    float Temp;

    printf("enter the temp of your water in Celsius: ");
    scanf("%f",&Temp);
    if (Temp<0)
    {
        printf("your water is solide");
    }
    else if (Temp>=0 && Temp<100)
    {
        printf("your water is liquide");
    }
    else if (Temp>=100)
    {
        printf("your water is Gaz");
    }
    else {
        printf("Please enter your temp correctly as number and logical temp of water");
    }
    
    return 0;
    
}