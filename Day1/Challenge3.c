#include<stdio.h>
int main(){
    float Km,Yards;
    
    printf("Enter your distance in Km: ");
    scanf("%f",&Km);
    
    Yards = Km * 1093.61;
    
    printf("Your distance in Yards is: %.2f",Yards);
    return 0;
}