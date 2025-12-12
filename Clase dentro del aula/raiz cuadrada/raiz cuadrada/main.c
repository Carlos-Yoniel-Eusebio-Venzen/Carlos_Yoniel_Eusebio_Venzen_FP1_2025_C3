#include <stdio.h>
#include <stdlib.h>

int main()
{
   float x = 0.0;
   float b = 0.0;
   int cnt = 1;
   printf("Escribe Numero ");
   scanf("%f",&x);
   b = x;

   while(!(b == (x/b)))
   {
       b = 0.5 * ((x/b)+b);
       printf("\nb:%f -- interaciones :%i ",b,cnt);
       cnt++;
   }
    printf("\nLa raiz cuadrada de %f es %f",x,b);
    return 0;
}
