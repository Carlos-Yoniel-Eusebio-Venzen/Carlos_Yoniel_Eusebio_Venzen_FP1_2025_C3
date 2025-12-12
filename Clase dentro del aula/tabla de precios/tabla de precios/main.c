#include <stdio.h>
#include <stdlib.h>

int main()
{
    //float son de 32 bits ocupan 4byte
    //double son de 64 bits ocupan 8bytes
    double lineaF[3];
    double Resultado = 0.0;
    double pro = 0.0;
    lineaF[0]= 1250.45;
    lineaF[1]= 120.00;
    lineaF[2]= 350.00;

    for (int i = 0; i < 3; i++)
    {
        printf("\nLinea[%i]=%f", i, lineaF[i]);
        Resultado += lineaF[i];
        pro = Resultado/3;
    }

    printf("\nTotal: %lf", Resultado);
    printf("\nPromedio: %.12lf", pro);
    return 0;
}
