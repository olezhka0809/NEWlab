#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Client{
    char* nume;
    char* idnp;
    int sold;
}Client;

typedef struct BankAcount
{
    char* id;
    char* pasword;
    struct Client*accountClient;
    struct BankAcount*next;
}BankAcount;

typedef struct Bank{
    char* denumireBanca;
    struct BankAcount* accounts;
}Bank;  

Client* creeareClient(char*nume, char* idnp, int sold ){
    Client* clientNou = (Client*) malloc(sizeof(Client));
    if(clientNou ==NULL){
        printf("Eroare alocare memorie !\n");
        exit(EXIT_FAILURE);
    }
    clientNou->nume = strdup(nume);
    clientNou->idnp = strdup(idnp);
    clientNou->sold = sold;
    return clientNou;
}

BankAcount* createBankAcount(char* id ,char*pasword, char*nume, char* idnp, int sold){
    BankAcount* newBankAcount = (BankAcount*)malloc(sizeof(BankAcount));
    if(newBankAcount == NULL){
        printf("Eroare alocare dinamica !");
        exit(EXIT_FAILURE);
    }
    Client* account = creeareClient(nume, idnp, sold);
    newBankAcount ->id = strdup(id);
    newBankAcount->pasword =strdup(pasword);
    newBankAcount->accountClient =account;
    newBankAcount->next = NULL;
    return newBankAcount;
}

Bank* creareBanca(char*denumire ){
    Bank*bancaNoua = (Bank*)malloc(sizeof(Bank));
    if(bancaNoua ==NULL){
        printf("Eroare alcoare dinamica !\n");
        exit(EXIT_FAILURE);
    }
    bancaNoua->denumireBanca = strdup(denumire);
    bancaNoua->accounts =NULL;
    return bancaNoua;
}


void adaugaBankAcount( BankAcount* account , Bank* banca ){
    if(banca == NULL){
        printf("Eroare : Banca invalida !\n");
        return;
    }
    
    if(banca ->accounts == NULL){
        banca->accounts = account;
    }else{
        BankAcount* currentNode = banca->accounts ;
        while ( currentNode ->next !=NULL)
        {
            currentNode =currentNode->next;
        }
        currentNode->next = account;
    }
    printf("Account -ul a fost adaugat cu succes !");
}

void depozit(char* id, char* pasword,char* idnp, char*nume, Bank *Bank,int depozit){
    if(Bank == NULL){
        printf("Banca nu are continut!");
        return;
    }
    BankAcount* currentAccount =  Bank->accounts;
    while (currentAccount !=NULL)
    {
        if(strcmp(currentAccount->id , id)== 0 && strcmp(currentAccount->pasword, pasword) == 0){
            if(strcmp(idnp, currentAccount->accountClient->idnp) == 0 && strcmp(currentAccount->accountClient->nume,nume)==0){
                currentAccount->accountClient->sold +=depozit;
                printf("Depozitul de %d a fost efectuat cu succes in contul lui  %s . \n",depozit, currentAccount->accountClient->nume);
                return;
            }
        }
        currentAccount = currentAccount->next;
    }
    printf("Eroare: Nu exista clientcu id: '%s' si pasword : '%s' !\nSau le-ati introdus gresti ,verifica inca o data !\n", id, pasword);   
}

void withdraw(Bank* banca, char*id, char*pasword, char*idnp, char*nume, int suma){
    if(banca == NULL){
        printf("Error: Banca nu exista !\n");
        return;
    }
    BankAcount* currentAccount = banca->accounts;
    while (currentAccount !=NULL)
    {
        if(strcmp(currentAccount->id, id) == 0 && strcmp(currentAccount->pasword, pasword) == 0){
            if(strcmp(currentAccount->accountClient->idnp , idnp) == 0 && strcmp(currentAccount->accountClient->nume , nume)== 0){
                int extrasSum = currentAccount->accountClient->sold-suma ;
                if(extrasSum >=0){
                    printf("Din cont s-au extras cu succes %d lei \nSuma ramasa este %d lei \n", suma, extrasSum);
                    return;
                }else{
                    printf("Fonduri insufieciente  verifica soldul!");
                    return;
                }
            }
        }
        currentAccount =currentAccount->next;
    }
    printf("Eroare : ai gresit id sau parola!\nVerifica datele introduse !\n");
}


void transfer(Bank *banca, char*id1, char*id2,char*nume1, char*nume2, int money){
    if(banca ==NULL){
        printf("Eroare: Banca invalida!\n");
        return;
    }
    BankAcount*currentAccount = banca->accounts; 
    int gasit1 =0;
    int gasit2= 0;
    BankAcount*persone1 =NULL;
    BankAcount*persone2 =NULL;

    while (currentAccount !=NULL)
    {
        if(strcmp(currentAccount->id, id1) && strcmp(currentAccount->accountClient->nume, nume1)){
            persone1 = currentAccount;
            gasit1 =1;
        }
        if(strcmp(currentAccount->id, id2) && strcmp(currentAccount->accountClient->nume, nume2)){
            persone2 = currentAccount;
            gasit2 =1;
        }
        currentAccount = currentAccount->next;
    }
    if(gasit1 ==1 && gasit2==1){
        int sold1 = persone1->accountClient->sold;
        int sold2 = persone2->accountClient->sold;
        int sumExtras = sold1-money;
        if(sumExtras<0){
            printf("Eroare transfer!\nFonduri insufiecente la %s!\n", persone1->accountClient->nume);
            return;
        }else{
            sold1 = sumExtras;
            sold2 += money;
            printf("Persoana %s a transferat %d bani persoanei %s !\nTranzactia a fost realizata cu succes !\n", persone1->accountClient->nume, money,persone2->accountClient->nume  );
            return;
        }
    }else{
        if(gasit1 !=1){
            printf("Persoana: %s cu id: %s nu are cont sau datele au fost introduse gresit !\n", nume1, id1);
            printf("Transfer anulat !\n");
            return;
        }else if (gasit2 !=1){
            printf("Persoana: %s cu id: %s nu are cont sau datele au fost introduse gresit !\n", nume2, id2);
            printf("Transfer anulat !\n");
            return;
            
        }
    }
}

void AfisareClientiBanca(Bank* banca){
    if(banca==NULL){
        printf("Banca nu are clienti !\n");
        return;
    }
    BankAcount*currentAccount = banca->accounts;
    int i =0;
    while (currentAccount !=NULL)
    {
      
        printf("\nId account Client %d : %s\n",i+1, currentAccount->id);
        if(currentAccount->accountClient !=NULL){
            Client * currentClient = currentAccount->accountClient;
            printf("Client idnp %d : %s\n", i+1, currentClient->idnp);
            printf("Nume client %d : %s\n",i+1,currentClient ->nume);
            printf("Sold client %d: %d\n",i+1, currentClient->sold);
            i++;
            currentAccount= currentAccount->next;
        }
    }
}

void free_Bank(Bank* banca) {
    BankAcount* current_node = banca->accounts;
    while (current_node != NULL) {
        BankAcount* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(banca);
}


int main(int argc, char*argv[]){
     if (argc != 2) {
        printf("Error: Incorrect usage! Please provide the input file name.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Failed to open the input file.\n");
        return 1;
    }

    // Read bank name from the file
    char numeBanca[100];
    if (fscanf(file, "%s", numeBanca) != 1) {
        printf("Error: Failed to read bank name from the input file.\n");
        fclose(file);
        return 1;
    }

    // Create bank
    Bank* banca = creareBanca(numeBanca);
    if (banca == NULL) {
        printf("Error: Failed to create bank.\n");
        fclose(file);
        return 1;
    }
    printf("\n\tBanca %s a fost creata cu succes!\t\n",numeBanca);
    printf("\n--------------------Bine ati venit la Banca %s ------------------\n", numeBanca);
    printf("Serviciile bancii: \n");
    printf("Press 1 : Creare Banc account\n");
    printf("Press 2 : Depozit\n");
    printf("Press 3 : Transfer\n");
    printf("Press 4 : Extrage bani\n");
    printf("Press 0 : Exit\n");
    int k ;

    char*nume ,*idnp , * id,*pasword,*id2, *nume2;
    nume= (char*)malloc(150*sizeof(char));
    nume2= (char*)malloc(150*sizeof(char));
    idnp = (char*)malloc(150*sizeof(char));
    id = (char*)malloc(150*sizeof(char));
    id2 = (char*)malloc(150*sizeof(char));
    pasword = (char*)malloc(150*sizeof(char));

    
    BankAcount* accountNew =NULL;
    int alegere, sum, bani;
    while (fscanf(file, "%d", &k) == 1) {
        switch (k) {
            case 1:
                if (fscanf(file, "%s %s %s %s %d", nume, idnp, id, pasword, &alegere) != 5) {
                    printf("Error: Invalid input format for account creation.\n");
                    break;
                }
                if (alegere == 1 && fscanf(file, "%d", &sum) != 1) {
                    printf("Error: Invalid input format for deposit amount.\n");
                    break;
                }
                accountNew = createBankAcount(id, pasword, nume, idnp, sum);
                adaugaBankAcount(accountNew, banca);
                AfisareClientiBanca(banca);
                break;
            case 2:
                if (fscanf(file, "%s %s %s %s %d", id, pasword, nume, idnp, &bani) != 5) {
                    printf("Error: Invalid input format for deposit.\n");
                    break;
                }
                depozit(id, pasword, idnp, nume, banca, bani);
                break;
            case 3:
                if (fscanf(file, "%s %s %s %s %d", id, id2, nume, nume2, &bani) != 5) {
                    printf("Error: Invalid input format for transfer.\n");
                    break;
                }
                transfer(banca, id, id2, nume, nume2, bani);
                break;
            case 4:
                if (fscanf(file, "%s %s %s %s %d", id, pasword, nume, idnp, &bani) != 5) {
                    printf("Error: Invalid input format for withdrawal.\n");
                    break;
                }
                withdraw(banca, id, pasword, idnp, nume, bani);
                break;
            case 0:
                printf("\nThank you for choosing our bank, %s!\nGoodbye!\n", numeBanca);
                fclose(file);
                free_Bank(banca);
                return 0;
            default:
                printf("Error: Invalid operation code: %d\n", k);
                break;
        }
    }
    fclose(file);
    free_Bank(banca);
    return 0;
}