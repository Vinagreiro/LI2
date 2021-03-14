//
// Created by vinagreiro on 2/22/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nib.h"

int escolha;
char a;
static int nibInserido = 0;
static char nib[1024];

void banco(){
    int i, x=0;
    char cod[4];
    for(i=0;i<4;i++){
        cod[x]=nib[i];
        x++;
    }
    if(strcmp(cod, "0007") == 0)
        printf("O seu banco e: Novo Banco\n");
    else if(strcmp(cod, "0010") == 0)
        printf("O seu banco e: BPI\n");
    else if(strcmp(cod, "0018") == 0)
        printf("O seu banco e: Santander Totta\n");
    else if(strcmp(cod, "0019") == 0)
        printf("O seu banco e: BBVA\n");
    else if(strcmp(cod, "0023") == 0)
        printf("O seu banco e: Activo Bank\n");
    else if(strcmp(cod, "0025") == 0)
        printf("O seu banco e: Caixa BI\n");
    else if(strcmp(cod, "0032") == 0)
        printf("O seu banco e: Barclays\n");
    else if(strcmp(cod, "0033") == 0)
        printf("O seu banco e: Millennium BCP\n");
    else if(strcmp(cod, "0034") == 0)
        printf("O seu banco e: BNP Paribas\n");
    else if(strcmp(cod, "0035") == 0)
        printf("O seu banco e: CGD\n");
    else if(strcmp(cod, "0235") == 0)
        printf("O seu banco e: Banco Carregosa\n");
    else if(strcmp(cod, "0036") == 0)
        printf("O seu banco e: Montepio Geral\n");
    else if(strcmp(cod, "0038") == 0)
        printf("O seu banco e: Banif\n");
    else if(strcmp(cod, "0043") == 0)
        printf("O seu banco e: Deutsche Bank\n");
    else if(strcmp(cod, "0045") == 0)
        printf("O seu banco e: Credito Agricola\n");
    else if(strcmp(cod, "0046") == 0)
        printf("O seu banco e: Popular\n");
    else if(strcmp(cod, "0059") == 0)
        printf("O seu banco e: Caixa Economica da Misericordia de Angra do Heroismo\n");
    else if(strcmp(cod, "0061") == 0)
        printf("O seu banco e: Big\n");
    else if(strcmp(cod, "0065") == 0)
        printf("O seu banco e: Best\n");
    else if(strcmp(cod, "0079") == 0)
        printf("O seu banco e: BIC\n");
    else if(strcmp(cod, "0193") == 0)
        printf("O seu banco e: Banco CTT\n");
    else if(strcmp(cod, "0269") == 0)
        printf("O seu banco e: Bankinter\n");
    else if(strcmp(cod, "0781") == 0)
        printf("O seu banco e: Direccao Geral do Tesouro\n");
    else if(strcmp(cod, "5180") == 0)
        printf("O seu banco e: Caixa Central de Credito Agricola\n");
    else printf("Banco nao identificado\n");
}


void conta() {
    int i, x=8;
    while(nib[x] == '0'){
        x++;
    }
    for(;x<19;x++){
        putchar(nib[x]);
    }
}

void controlo(){
    printf("%c %c\n", nib[19], nib[20]);
}

void blocos() {
    int i;
    for (i = 0; i < 21; i++) {
        if (i == 4 || i == 8 || i == 12 || i == 16 || i == 19)
            putchar(' ');
        putchar(nib[i]);
    }
    putchar('\n');
}

void menu() {
    do{
    printf("\nBem vindo ao menu\n");
    printf("As suas opcoes sao:\n");
    printf("1 - Ler o seu nib: \n");
    printf("2 - Nome do banco\n");
    printf("3 - Numero da conta\n");
    printf("4 - Digitos de controlo\n");
    printf("5 - Nib divido por blocos\n");
    printf("6 - Sair do menu\n");
    scanf("%d", &escolha);

        switch (escolha) {

            case 1:
                printf("insira o seu Nib\n");
                    scanf("%s", nib);
                    nibInserido = 1;
                break;

            case 2:
                if (nibInserido == 0){
                    printf("Deve primeiro usar a opcao 1 para ler o seu Nib, carregue no caracter (p) para prosseguir\n");
                    scanf("%c", &a);
                    while(a != 'p'){
                        scanf("%c", &a);
                    }
                }
                else {
                    banco();
                }
                break;

            case 3:
                if (nibInserido == 0){
                    printf("Deve primeiro usar a opcao 1 para ler o seu Nib, carregue no caracter (p) para prosseguir\n");
                    scanf("%c", &a);
                    while(a != 'p'){
                        scanf("%c", &a);
                    }
                }
                else {
                    conta();
                }
                break;

            case 4:
                if (nibInserido == 0){
                    printf("Deve primeiro usar a opcao 1 para ler o seu Nib, carregue no caracter (p) para prosseguir\n");
                    scanf("%c", &a);
                    while(a != 'p'){
                        scanf("%c", &a);
                    }
                }
                else {
                    controlo();
                }
                break;

            case 5:
                if (nibInserido == 0){
                    printf("Deve primeiro usar a opcao 1 para ler o seu Nib, carregue no caracter (p) para prosseguir\n");
                    scanf("%c", &a);
                    while(a != 'p'){
                        scanf("%c", &a);
                    }
                }
                else {
                    blocos();
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Nao selecionou nenhuma opcao valida\n");
                break;
        }
        return menu();
    }
    while(escolha != 6);
}
