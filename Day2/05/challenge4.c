#include<stdio.h>
#include<windows.h>

int main (){
  int quantity;
  int maxvalue;
  printf("enter how much products do you want: ");
  scanf("%d",&quantity);
  int price[quantity];
  for (int i =0 ;i<quantity;i++){
    printf("enter the price of this product %d: ",i+1);
    scanf("%d",&price[i]);
  }

          maxvalue = price[0];

   for (int i =0 ;i<quantity;i++){
   
        if (maxvalue <price[i])
        {
            maxvalue = price[i];
        }


    }
  
    printf("the max of this products is: %d",maxvalue);
}



