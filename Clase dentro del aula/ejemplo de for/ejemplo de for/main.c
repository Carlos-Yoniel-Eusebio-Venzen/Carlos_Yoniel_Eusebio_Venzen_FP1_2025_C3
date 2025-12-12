#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;

    for(num = -10;num <=10;num++)
    {
        if(num != 0)
        {
            if(num == -5 || num == 5)
            {
            printf("\nValor de num[%i]^2=%i",num,num*num);
        }else
        {
            printf("\nValor de num=%i",num);
        }

        }
    }
    printf("\n---FIN---");
    return 0;
}
