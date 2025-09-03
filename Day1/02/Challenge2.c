#include<stdio.h>
#include<stdbool.h>

int main() {
    float price = 125.00;
    char product[23]="";
    float Quantity=0.0;
    float result=0.0;
    float reduction;
    
    do
    {
    printf("What's the name of the product you want: ");
    fgets(product,sizeof(product),stdin);
   
    printf("Enter how much %s you want: ",product);
    scanf("%f",&Quantity);
    }while(Quantity<=0);
    
      
    if (Quantity>1){
    result = price + (Quantity - 1) * price * 0.98;
    // result = result - result*(1-0.02*price);
    // - Quantity * price* 0.02;
    printf("You have to pay: %.2f DHS",result);
    }
       
        
    else{
    result = Quantity *price;
    printf("You have to pay: %.2f DHS",result);
    }
    return 0;
    
    
    // 2% = 0.02
}