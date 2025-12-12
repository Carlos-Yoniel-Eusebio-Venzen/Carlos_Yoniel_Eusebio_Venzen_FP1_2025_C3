#include <stdio.h>
#include <stdlib.h>
#define EDAD_MIN 0
#define EDAD_MAX 120

int main()
{
    //AND OR NOT
    // == !=
    //enunciado
    //0 a 2 es un infante
    //3 a 10 es un niño
    //11 a 12 es pre adolescente
    //13 a 17 es adolescente
    //18 a 40 es mayor de edad
    //41 a 65 es adulto mayor
    //65 a EDAD_MAX es envejecinte
    int edad = EDAD_MIN;
    printf("\nIngrese la edad: ");
    scanf("%i", &edad);

    if(edad >= EDAD_MIN && edad <= EDAD_MAX)
    {
        if(edad >= EDAD_MIN && edad <=2)
        {
              printf("\nEs un infante");
        }else if(edad <= 10)
        {
            printf("\nEs un nino");
        }else if (edad <=12)
        {
            printf("\nEs un pre-adolescente");
        }else if (edad <=17)
        {
            printf("\nEs un adolescente");
        }else if(edad<=40)
        {
            printf("\nEs un mayor de edad");
        }else if(edad<=65)
        {
            printf("\nEs un adulto mayor");
        }else if(edad>65)
        {
            printf("\nEs un envejeciente");
        }
    }
    else
    {
        if(edad < EDAD_MIN)
        {
            printf("\n---Usted viene del pasado---");
        }

        if(edad > EDAD_MAX)
        {
            printf("\n---Usted eres un vampiro---");
        }
        printf("\n---Edad fuera del rango valido---");
    }
    printf("\n---FIN---");
    return 0;
}
