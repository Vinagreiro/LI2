//
// Created by vinagreiro on 2/27/19.
//
#include <stdio.h>
#include "histograma.h"

int i;
static char letras[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
static char frase[1024];
static int simb[26];

int conta(char w, char frase[]){
    int res=0, k;
    for(k=0;frase[k] != '\0';k++){
        if(frase[k] == w || frase[k] == w+32) {
            res += 1;
        }
    }
    return res;
}

void contadores(char letras[], char frase[]){
    for(i=0;i<26;i++){
        simb[i] = conta(letras[i], frase);
    }
}

int maior(){
    int z=0;
    for(i=0;i<26;i++){
        if(simb[i]>z){
            z=simb[i];
        }
    }
    return z;
}

void graf() {
    int fx, h, i, x=0, k, a;
    for(h=0;h<26;h++){
        simb[h]=0;
    }
    printf("Introduza a sua frase: ");
    fgets(frase,1024,stdin);
    contadores(letras, frase);
    fx = maior();
    k=fx;
    for (i = 0; i < fx; i++){
        for(x=0;x<26;x++){
            if(simb[x] == k){
                putchar('*');
                putchar(' ');
                simb[x]--;
            }
            else{
                putchar(' ');
                putchar(' ');
            }
        }
        k--;
        putchar('\n');
        }
        for(a=0;a<26;a++){
            printf("%c ", letras[a]);
    }
}
