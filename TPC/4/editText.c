//
// Created by vinagreiro on 3/6/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int escolha, i, j, n, m;
char w, h, k;
int a, b;
static char matr[20][20]={0};

void matriz(FILE** ficheiro, int* a, int* b){
    *ficheiro = fopen("ficheiro.txt","r");
    fscanf(*ficheiro, "%d %d", a, b);
    fgetc(*ficheiro);
    for(i=0;i<*a;i++){
        for(j=0;j<*b;j++){
            fscanf(*ficheiro, "%c", &w);
            fgetc(*ficheiro);
            if((w != ' ') && (w != '\n')){
                matr[i][j]=w;
            }
        }
    }
    fclose(*ficheiro);
    printf("%d %d\n",*a, *b);
    for(i=0;i<*a;i++){
        for(j=0;j<*b;j++){
            printf("%c ", matr[i][j]);
        }
        putchar('\n');
    }
}

void altera(int n, int m, char k, int a, int b, char matr[20][20]) {
    printf("Insira a linha do elemento que pretender alterar:\n");
    scanf("%d", &n);
    while (n >a || n<1) {
        scanf("%d", &n);
    }
    printf("Insira a coluna do elemento que pretender alterar:\n");
    scanf("%d", &m);
    while (m>b || m<1) {
        scanf("%d", &m);
    }
    printf("Insira o elemento que pretender introduzir:\n");
    scanf("%c", &k);
    while (k != 'X' && k != 'O' && k != '.') {
        scanf("%c", &k);
    }
    matr[n-1][m-1] = k;
}

void grava(FILE** ficheiro, char matr[20][20], int* a, int* b){
    *ficheiro = fopen("ficheiro.txt","w");
    fprintf(*ficheiro,"%d %d\n",*a, *b);
    for(i=0;i<*a;i++){
        for(j=0;j<*b;j++){
            fprintf(*ficheiro,"%c ", matr[i][j]);
        }
        fprintf(*ficheiro, "\n");
    }
    fclose(*ficheiro);
    printf("%d %d\n",*a, *b);
    for(i=0;i<*a;i++){
        for(j=0;j<*b;j++){
            printf("%c ", matr[i][j]);
        }
        printf("\n");
    }
}

void menu() {
    FILE *ficheiro;
    do{
        printf("\nBem vindo ao menu\n");
        printf("As suas opcoes sao:\n");
        printf("1 - Abrir o ficheiro: \n");
        printf("2 - Alterar o ficheiro\n");
        printf("3 - Gravar o ficheiro\n");
        printf("4 - Sair do menu\n");
        scanf("%d", &escolha);

        switch (escolha) {

            case 1:
                matriz(&ficheiro, &a, &b);
                break;

            case 2:
                if (ficheiro == NULL){
                    printf("Deve primeiro usar a opcao 1 para abrir o ficheiro, carregue no caracter (p) para prosseguir\n");
                    scanf("%c", &h);
                    while(h != 'p'){
                        scanf("%c", &h);
                    }
                }
                else {
                    altera(n, m, k, a, b, matr);
                }
                break;

            case 3:
                if (ficheiro == NULL){
                    printf("Deve primeiro usar a opcao 1 para abrir o ficheiro, carregue no caracter (p) para prosseguir\n");
                    scanf("%c", &h);
                    while(h != 'p'){
                        scanf("%c", &h);
                    }
                }
                else {
                    grava(&ficheiro, matr, &a, &b);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Nao selecionou nenhuma opcao valida\n");
                break;
        }
    }
    while(escolha != 4);
}