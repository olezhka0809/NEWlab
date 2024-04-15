#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void introduLitera( char cuvant[], char cuvantGasit[], int n, char litera ){
    int gasit =0;
    for (int i = 0; i < n; i++)
    {
        if(cuvant[i] == litera || cuvant[i] == toupper(litera) || cuvant[i] == tolower(litera) ){
            printf("Litera este gasita la pozitia: %d \n", i+1);
            cuvantGasit[i] = cuvant[i];
            gasit++;
        }
    }

    if(gasit ==0){
        printf("Litera nu a fost gasita !\n");
    }
}


int main(){
    printf("\n\tBine ai venit in jocul Hangman !!!\t\n");
    int n, count;

    char *cuvant;
    char *cuvantGasit;

    printf("Introdu cuvantul: ");

    cuvant = (char*)malloc(100* sizeof(char));
    scanf("%s", cuvant);
    n = strlen(cuvant);

    cuvantGasit= (char*)malloc((n+1)*sizeof(char));

    printf("\n------ Cuvantul introdus este %s --------\n\n", cuvant);
    char litera;
    
    for (int i = 0; i < n; i++) {
        cuvantGasit[i] = '_';
    }

    count= 2*n;
    
    cuvantGasit[n]='\0';
    printf("Numarul de incercari %d ", count);
    while (count >0)
    {
        printf("\nIntrodu litera :");
        scanf(" %c", &litera);
        count--;
        introduLitera(cuvant, cuvantGasit, n,litera);
        if(strcmp(cuvantGasit, cuvant)==0){
            printf("\n------- Felicitari ai gasit cuvantul !!! ---------\n");
            printf("Cuvantul : %s ", cuvant);
            free(cuvant);
            free(cuvantGasit);
            return 0;
        }
        printf("Cuvantul tau arata astfel: \n");
        printf("cuvant de ghicit :    %s   \n", cuvantGasit);
        printf("Mai ai %d incercari !\n",count);
    }

    printf("\n--------- Ai pierdut !\nCuvantul corect era %s ---------\n", cuvant);
    free(cuvant);
    free(cuvantGasit);
    return 0;
}