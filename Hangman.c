#include <stdio.h>
#include <string.h>


int introduLitera( char cuvant[], int n, char litera, int count){
    int gasit =0;
    for (int i = 0; i < n; i++)
    {
        if(cuvant[i] == litera){
            printf("Litera este gasita la : %d \n", i+1);
            printf("Numarul de incercari este %d\n", count);
            count--;
            gasit++;
        }
    }
    if(gasit !=0){
        printf("Litera nu a fost gasita !\n");
        count--;
    }
    return count;
    
}


int main(){
    int n, count;
    printf("Introdu numarul de  incercari : ");
    scanf("%d",&count);
    printf("Introdu numarul de caractere al cuvantului : ");
    scanf("%d",&n);
    char cuvant[n];
     
    printf("Introdu cuvantul: ");
    scanf("%s", cuvant);
    printf("Cuvantul introdus este %s \n", cuvant);
    char litera;

    printf("Numarul de incercari %d ", count);
    while (count !=0)
    {
        printf("Introdu litera : \n");
        scanf("%c", &litera);
        printf("Litera alesa este %c ", litera);
        count = introduLitera(cuvant, n, litera,count);
        printf("count %d ",count);
        printf("Mai ai %d incercari !",count);
    }

    return 0;
}