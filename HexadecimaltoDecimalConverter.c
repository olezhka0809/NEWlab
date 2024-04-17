#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000

void checkAllocation(void *ptr) {
    if (ptr == NULL) {
        printf("Eroare la alocarea de memorie. Iesire din program.\n");
        exit(EXIT_FAILURE);
    }
}

int intorcValoare(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isxdigit(c)) {
        return tolower(c) - 'a' + 10;
    }
    return -1; 
}

int multipluDe16(int j) {
    int nr = 1;
    while (j > 0) {
        nr *= 16;
        j--;
    }
    return nr;
}

void numarDecDinHex(char *numar) {
    int sum = 0;
    int lng = strlen(numar);
    int i = lng - 1;
    
    for (int j = 0; j < lng; j++) {
        int val = intorcValoare(numar[j]);
        if (val == -1) {
            printf("Caracterul '%c' nu este hexazecimal. Te rog reintrodu un numar valid.\n", numar[j]);
            return;
        }
        sum += multipluDe16(i) * val;
        printf("16^%d * %c \n", i, numar[j]);
        i--;
    }
    
    printf("Numarul in decimal este: %d \n", sum);
}

int main() {
    printf("--------------Transformare din Numere Hexazecimale in Decimale --------------\n\n");
    char *numarH = (char *)malloc(MAX * sizeof(char));
    checkAllocation(numarH);

    printf("Introduceti numarul in format hexazecimal: ");
    scanf("%s", numarH);
    printf("Numarul de caractere din cuvant este %d \n", strlen(numarH));
    
    numarDecDinHex(numarH);
    free(numarH);
    return 0;
}
