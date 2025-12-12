#include <stdio.h>
#include <stdlib.h>
#define SALIR 0
#define DIVIDIR 1
#define MULTIPLICAR 2

#define ERR_OK 0
#define ERR_DbZ 1

float num1 = 0.0;
float num2 = 0.0;

float divir (float numerador, float denominador);
float multiplicar(float n1, float n2);

int dividir_s(float numerador, float denominador, float *result)
{
    if(denominador != 0)
    {
        *result = numerador/denominador;
        return ERR_OK;
    }else
    {
        return ERR_DbZ;
    }
}

int multiplicar_s(float num1, float num2, float *result)
{
    *result = num1*num2;
}

void ingresaDatos(void)
{
    printf("\nIngrese primer numero:");
    scanf("%f", &num1);
    printf("\nIngrese segundo numero:");
    scanf("%f", &num2);
}

int main()
{
    int menu = SALIR;
    int err_code = ERR_OK;
    float resultado = 0.0;
   do
   {
       printf("\n0-salir\n1-Dividir\n2Multiplicar\n");
       scanf("%i", &menu);

       if(menu == DIVIDIR)
       {
           ingresaDatos();
           //resultado = dividir (num1, num2);
           err_code = dividir_s(num1,num2,&resultado);
            if (err_code != ERR_OK)
            {
                printf("\nDivision por cero invalida");
            }else
            {
                printf("\nResultado=%f",resultado);
            }
        }

        if(menu == MULTIPLICAR)
        {
            ingresaDatos();
            //resultado = multiplicar(num1,num2);
            err_code = multiplicar_s(num1,num2,&resultado);
        }
   }while(menu != SALIR);

   printf("\n----------------------");
   printf("\n\FIN");
    return 0;
}

float dividir(float numerador, float denominador)
{
    float r = numerador/denominador;
    return r;
}

float multiplicar (float n1, float n2)
{
    return n1*n2;
}
