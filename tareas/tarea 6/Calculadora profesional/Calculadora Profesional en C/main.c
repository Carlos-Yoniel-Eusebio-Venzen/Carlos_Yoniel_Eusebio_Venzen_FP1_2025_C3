#include <stdio.h>
#include <math.h>


/*
 _____________________________________________________________________________________
            CALCULADORA PROFESIONAL
    (OPERACIONES BASICAS, MATRICES Y NUMEROS COMPLEJOS)
 _____________________________________________________________________________________
*/

/* Funciones normales */

void operaciones_basicas(void);
void operaciones_matrices(void);
void operaciones_complejos(void);

/* Funciones para operaciones con matrices */

void leermatriz(double A[10][10], int f, int c);
void imprimirmatriz(double A[10][10], int f, int c);
void sumarmatrices(double A[10][10], double B[10][10], double C[10][10], int f, int c);
void restarmatrices(double A[10][10], double B[10][10], double C[10][10], int  f, int c);
void multiplicarMatrices(double A[10][10], double B[10][10], double C[10][10], int f1, int c1, int f2, int c2);

int main()
{
    int opcion;
    do
    {
       printf("\n___________________________________________\n");
       printf("         CALCULADORA PROFESIONAL\n");
       printf("\n___________________________________________\n");
       printf("1. Operaiones Basicas\n");
       printf("2. Operaciones con Matrices\n");
       printf("3. Operaciones con numeros complejos\n");
       printf("0. Salir\n");
       printf("Selecione una opcion: ");
       scanf("%d", &opcion);

       switch(opcion){
            case 1: operaciones_basicas(); break;
            case 2: operaciones_matrices(); break;
            case 3: operaciones_complejos(); break;
            case 0: printf("\nSaliendo...\n"); break;
            default: printf("\nEsta opcion es invalida");
        }

    }
    while(opcion != 0);
    return 0;
}

/*
 _____________________________________________________________________________________
            1. Operaciones Basicas
 _____________________________________________________________________________________
*/

void operaciones_basicas(void)
{
    double a, b, res;
    int op;
    printf("\nIngrese dos numeros: ");
    scanf("%lf %lf", &a, &b);
    printf("\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\nSelecione: ");
    scanf("%d", &op);

    switch(op)
    {
        case 1: res = a+b; break;
        case 2: res = a-b; break;
        case 3: res = a*b; break;
        case 4:
            if(b != 0)
                res = a/b;
            else
            {
                printf("/nError: division por cero. \n");
                return;
            }
            break;
        default: printf("\nOpcion no valida.\n");
        return;
    }
    printf("Resultado: %.2lf\n", res);
}

/*
 _____________________________________________________________________________________
            2. Operaciones con Matrices
 _____________________________________________________________________________________
*/

void operaciones_matrices(void)
{
    double A[10][10], B[10][10], C[10][10];
    int f1, c1, f2, c2, op;

    printf("\nIngrese filas y columnas de la primera matriz: ");
    scanf("%d %d", &f1, &c1);
    printf("\nIngrese filas y columnas de la segunda matriz: ");
    scanf("%d %d", &f2, &c2);

    printf("\nLectura de matriz A: \n");
    leermatriz(A, f1, c1);
    printf("\nLectura de matriz B:\n");
    leermatriz(B, f2, c2);

    printf("\n1. Suma\n2. Resta\n3. Multiplicacion\nSelecione: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        if(f1 == f2 && c2)
        {
            sumarmatrices(A, B, C, f1, c1);
            printf("\nResultado de la suma: \n");
            imprimirmatriz(C, f1, c1);
        }
        else
            printf("\nLas matrices deben tener el mismo tamano. \n");
        break;


    case 2:
        if(f1 == f2 && c1 == c2)
        {
            restarmatrices(A, B, C, f1, f2);
            printf("\nResultado de la suma: \n");
            imprimirmatriz(C, f1, c1);

        }
        else
            printf("\nLas matrices deben tener el mismo tamano. \n");
        break;

    case 3:
        if(c1 == f2)
        {
            multiplicarMatrices(A, B, C, f1, c1, f2, c2);
            printf("\nLas dimensiones no permiten multiplicar.\n");
            imprimirmatriz(C, f1, c2);
        }
        else
            printf("\nLas dimensiones no permiten multiplicar. \n");
        break;

    default:
        printf("\nOpcion invalida. \n");
    }
}


void leermatriz(double A[10][10], int f, int c)
{
    int i, j;
    for(i = 0; i < f; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("Elemento[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &A[i][j]);
        }
    }
}

void imprimirmatriz(double A[10][10], int f, int c)
{
    int i, j;
    for(i = 0; i < f; i++)
    {
        for(j = 0; j < c; j++)
            printf("%10.4lf", A[i][j]);
        printf("\n");
    }
}

void sumarmatrices(double A[10][10], double B[10][10], double C[10][10], int f, int c)
{
    int i, j;
    for(i = 0; i < f; i++)
        for(j = 0; j < c; j++)
        C[i][j] = A[i][j] + B[i][j];
}

void restarmatrices(double A[10][10], double B[10][10], double C[10][10], int f, int c)
{
    int i, j;
    for(i = 0; i < f; i++)
        for(j = 0; j < c; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiplicarMatrices(double A[10][10], double B[10][10], double C[10][10], int f1, int c1, int f2, int c2)
{
    int i, j, k;
    for(i = 0; j < c2; j++)
    {
        for(j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for(k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

/*
 _____________________________________________________________________________________
            3. Operaciones con numeros complejos
 _____________________________________________________________________________________
*/

void operaciones_complejos(void)
{
    double realA, realB, imagA, imagB, resR, resI;
    int op;

    printf("\nIngrese la parte real y la parte imaginaria del primer numero: ");
    scanf("%lf %lf", &realA, &imagA);
    printf("\nIngrese la parte real y la parte imaginaria del segundo numero: ");
    scanf("%lf %lf", &realB, &imagB);

    printf("\n1. Suma\n2. Resta\n3. Multiplicacion\nSelecione: ");
    scanf("%d", op);

    switch(op)
    {
        case 1:
            resR = realA + realB;
            resI = imagA + imagB;
            break;
        case 2:
            resR = realA + realB;
            resI = imagA + imagB;
            break;
        case 3:
            resR = (realA * realB) - (imagA * imagB);
            resI = (realA * realB) + (imagA * imagB);
            break;
        default:
            printf("\nOpcion invalida.\n");
            return;
    }
    printf("\nResultado: %.4lf + %.4lf\n.", resR, resI);
}
