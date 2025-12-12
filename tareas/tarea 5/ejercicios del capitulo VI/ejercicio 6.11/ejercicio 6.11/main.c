#include <stdio.h>
#include <stdlib.h>

// Estructura para números complejos
typedef struct {
    double real;
    double imag;
} Complejo;

// Funciones para operaciones básicas
void operacionesBasicas();
void operacionesComplejos();
void operacionesMatrices();

// Funciones auxiliares
Complejo sumarComplejos(Complejo a, Complejo b);
Complejo restarComplejos(Complejo a, Complejo b);
Complejo multiplicarComplejos(Complejo a, Complejo b);
Complejo dividirComplejos(Complejo a, Complejo b);

int main() {
    int opcion;

    printf("\n==============================\n");
    printf("      [Calculus C]\n");
    printf("==============================\n");

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Operaciones básicas (double)\n");
        printf("2. Números complejos\n");
        printf("3. Operaciones con matrices\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: operacionesBasicas(); break;
            case 2: operacionesComplejos(); break;
            case 3: operacionesMatrices(); break;
            case 4: printf("\nSaliendo de [Calculus C]...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while(opcion != 4);

    return 0;
}

// ====================
// Operaciones básicas
// ====================
void operacionesBasicas() {
    double a, b;
    char op;

    printf("\n--- Operaciones básicas ---\n");
    printf("Ingrese la operación (ejemplo: 5 + 3): ");
    scanf("%lf %c %lf", &a, &op, &b);

    switch(op) {
        case '+': printf("Resultado: %.2lf\n", a + b); break;
        case '-': printf("Resultado: %.2lf\n", a - b); break;
        case '*': printf("Resultado: %.2lf\n", a * b); break;
        case '/':
            if (b != 0) printf("Resultado: %.2lf\n", a / b);
            else printf("Error: división entre cero.\n");
            break;
        default: printf("Operador inválido.\n");
    }
}

// ====================
// Números complejos
// ====================
void operacionesComplejos() {
    Complejo a, b, resultado;
    int opcion;

    printf("\n--- Operaciones con números complejos ---\n");
    printf("Ingrese el primer número (parte real e imaginaria): ");
    scanf("%lf %lf", &a.real, &a.imag);
    printf("Ingrese el segundo número (parte real e imaginaria): ");
    scanf("%lf %lf", &b.real, &b.imag);

    printf("\nSeleccione operación:\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1: resultado = sumarComplejos(a, b); break;
        case 2: resultado = restarComplejos(a, b); break;
        case 3: resultado = multiplicarComplejos(a, b); break;
        case 4: resultado = dividirComplejos(a, b); break;
        default: printf("Opción inválida.\n"); return;
    }

    printf("Resultado: %.2lf + %.2lfi\n", resultado.real, resultado.imag);
}

// ====================
// Operaciones con matrices
// ====================
void operacionesMatrices() {
    int filas, columnas, i, j;
    printf("\n--- Operaciones con matrices ---\n");
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    double A[10][10], B[10][10], C[10][10];
    printf("Ingrese los elementos de la matriz A:\n");
    for(i=0; i<filas; i++)
        for(j=0; j<columnas; j++)
            scanf("%lf", &A[i][j]);

    printf("Ingrese los elementos de la matriz B:\n");
    for(i=0; i<filas; i++)
        for(j=0; j<columnas; j++)
            scanf("%lf", &B[i][j]);

    printf("\nSeleccione operación:\n1. Sumar\n2. Multiplicar\nOpción: ");
    int op;
    scanf("%d", &op);

    if (op == 1) {
        for(i=0; i<filas; i++)
            for(j=0; j<columnas; j++)
                C[i][j] = A[i][j] + B[i][j];
        printf("Resultado de la suma:\n");
        for(i=0; i<filas; i++) {
            for(j=0; j<columnas; j++)
                printf("%.2lf\t", C[i][j]);
            printf("\n");
        }
    } else if (op == 2) {
        // Asumimos matrices cuadradas para simplificar
        for(i=0; i<filas; i++)
            for(j=0; j<columnas; j++) {
                C[i][j] = 0;
                for(int k=0; k<columnas; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
        printf("Resultado de la multiplicación:\n");
        for(i=0; i<filas; i++) {
            for(j=0; j<columnas; j++)
                printf("%.2lf\t", C[i][j]);
            printf("\n");
        }
    } else {
        printf("Opción inválida.\n");
    }
}

// ====================
// Funciones de complejos
// ====================
Complejo sumarComplejos(Complejo a, Complejo b) {
    Complejo r = {a.real + b.real, a.imag + b.imag};
    return r;
}

Complejo restarComplejos(Complejo a, Complejo b) {
    Complejo r = {a.real - b.real, a.imag - b.imag};
    return r;
}

Complejo multiplicarComplejos(Complejo a, Complejo b) {
    Complejo r = {
        a.real*b.real - a.imag*b.imag,
        a.real*b.imag + a.imag*b.real
    };
    return r;
}

Complejo dividirComplejos(Complejo a, Complejo b) {
    double denom = b.real*b.real + b.imag*b.imag;
    Complejo r = {
        (a.real*b.real + a.imag*b.imag) / denom,
        (a.imag*b.real - a.real*b.imag) / denom
    };
    return r;
}
