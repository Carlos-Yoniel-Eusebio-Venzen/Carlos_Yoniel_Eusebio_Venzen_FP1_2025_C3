#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = -10;
    while (num <=10)
     {
         if(num !=0)
         {
                if(num == -5 || num == 5)
                {
                   printf("\nValor de num[%i]^2= %i ",num, num*num);
                }else
                 {
                     printf("\nValor de num = %i ", num);
                 }

        }
         num++;
     }

     printf("\n----fin---");
    return 0;
}
