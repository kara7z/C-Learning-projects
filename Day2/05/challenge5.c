#include<stdio.h>
#include<windows.h>

int main (){
  int quantity;
  int minvalue;
  printf("enter how much products do you want: ");
  scanf("%d",&quantity);
  int price[quantity];
  for (int i =0 ;i<quantity;i++){
    printf("enter the price of this product %d: ",i+1);
    scanf("%d",&price[i]);
  }

          minvalue = price[0];

   for (int i =0 ;i<quantity;i++){
   
        if (minvalue >price[i])
        {
            minvalue = price[i];
        }


    }
  
    printf("the min price of this products is: %d",minvalue);
}
