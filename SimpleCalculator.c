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
    printf(" + - Adunare \n");
    printf(" - - Scadere \n");
    printf(" * - Inmultire \n");
    printf(" / - Impartire \n");
    printf(" r - Radical\n");
    printf(" l - Logaritm\n");
    printf(" %c - Procent \n", p);
    printf(" c - Reseteaza rezultatul la 0 si permite suprapunerea rezultatelor\n");
    printf(" q - Iesire\n");

    while (1) {   
        printf("Introdu operatia : ");
        scanf(" %c", &c); 
        
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                if (rez == 0) {
                    printf("Introdu primul numar: ");
                    scanf("%lf", &num1);
                } else {
                    num1 = rez;
                }
                printf("Introdu al doilea numar: ");
                scanf("%lf", &num2);
                switch (c) {
                    case '+':
                        rez = addition(num1, num2);
                        printf("\n%.2lf + %.2lf = %.2lf  \n", num1, num2, rez);
                        break;
                    case '-':
                        rez = substraction(num1, num2);
                        printf("\n%.2lf - %.2lf = %.2lf  \n", num1, num2, rez);
                        break;
                    case '*':
                        rez = multiplication(num1, num2);
                        printf("\n%.2lf * %.2lf = %.2lf  \n", num1, num2, rez);
                        break;
                    case '/':
                        rez = division(num1, num2);
                        printf("\n%.2lf / %.2lf = %.2lf  \n", num1, num2, rez);
                        break;
                    case '%':
                        rez = procentaj(num1, num2);
                        printf("\n%.2lf %c %.2lf = %.2lf  \n", num1, c, num2, rez);
                        break;
                }
                break;
            case 'r':
                if (rez == 0) {
                    printf("Introdu numarul: ");
                    scanf("%lf", &num1);
                } else {
                    num1 = rez;
                }
                rez = Squareroots(num1);
                printf("\nradical %.2lf = %.2lf \n", num1, rez);
                break;
            case 'l':
                if (rez == 0) {
                    printf("Introdu numarul: ");
                    scanf("%lf", &num1);
                } else {
                    num1 = rez;
                }
                rez = Logarithmic(num1);
                printf("\nlogaritm %.2lf = %.2lf \n", num1, rez);
                break;
            case 'c':
                rez = 0;
                printf("Rezultatul resetat la 0.\n");
                break;
            case 'q':
                printf("Iesire din program.\n");
                exit(0);
            default:
                printf("Caracter necunoscut!\n");
                break;
        }
    }

    return 0;
}
