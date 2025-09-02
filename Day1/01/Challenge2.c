#include<stdio.h>
int main(){
    float C,K;
    printf("Enter the temp in celsius: ");
    scanf("%f",&C);
    K = C + 273.15;
    printf("\nYour temp in Kelvin is: %.2f",K);
}