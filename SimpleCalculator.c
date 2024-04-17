#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double addition(double a, double b) {
    return a + b;
}

double substraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}

double Squareroots(double a) {
    return sqrt(a);
}

double Logarithmic(double a) {
    return log(a);
}

double procentaj(double valoare, double procentaj) {
    return (valoare * procentaj) / 100;
}

int main() {
    printf("--------------Calculator Simulator --------------\n");
    char c;
    char p = '%';
    double num1, num2, rez = 0;
    printf("Functional: \n");
    printf(" + - Aduanre \n");
    printf(" - - Scadere \n");
    printf(" * - Inmultire \n");
    printf(" / - Impartire \n");
    printf(" r - Radical\n");
    printf(" l - Logaritm\n");
    printf( " %c - Procent \n", p);


    while (1) {   
        printf("Introdu n1: ");
        scanf("%lf", &num1);
        printf("Introdu n2: ");
        scanf("%lf", &num2);
        scanf(" %c", &c); 
        
        switch (c) {
            case '+':
                rez = addition(num1, num2);
                printf("\n%.2lf\n", rez);
                rez =0;
                break;
            case '-':
                rez = substraction(num1, num2);
                printf("\n%.2lf\n", rez);
                rez =0;
                break;
            case '*':
                rez = multiplication(num1, num2);
                printf("\n%.2lf\n", rez);
                rez =0;
                break;
            case '/':
                rez = division(num1, num2);
                printf("\n%.2lf\n", rez);
                rez =0;
                break;
            case 'r':
                rez = Squareroots(num1);
                printf("\n%.2lf\n", rez);
                rez =0;
                break;
            case 'l':
                rez = Logarithmic(num1);
                printf("\n%.2lf\n", rez);
                rez =0;
                break;
            case '%':
                rez = procentaj(num1, num2);
                printf("\n%.2lf\n", rez);
                break;
            default:
                printf("Caracter necunoscut!\n");
                break;
        }
    }

    return 0;
}
