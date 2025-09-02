#include<stdio.h>
int main(){
    float m_s,km_h;
    
    printf("Enter your Speed in km/h: ");
    scanf("%f",&km_h);
    
    m_s = km_h * 0.27778;
    
    printf("your speed in m/s is: %.2f",m_s);
    return 0;
}