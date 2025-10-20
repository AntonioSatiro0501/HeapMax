#include <stdio.h>

void troca(int *x, int *y){
    int troc = *x;
    *x = *y;
    *y = troc;
}

void avaliaArvore (int lista[], int tamanho, int maior){

    int aux = maior;
    int galhoEsq = maior*2 + 1;
    int galhoDir = maior*2 + 2; 

    if(galhoEsq < tamanho){

        if(lista[aux] < lista[galhoEsq]){
            aux = galhoEsq;
        }

        if(galhoDir < tamanho && lista[aux] < lista[galhoDir]){
            aux = galhoDir;
        }

        if(aux != maior){
            troca(&lista[maior], &lista[aux]);
            avaliaArvore(lista, tamanho, aux);
        }
    }
}

void heapMax(int tamanho, int lista[]) {

    int maior = 0;
    for(int f = (tamanho -1)/2; f >= 0; f-- ){
        avaliaArvore(lista, tamanho, f);
    }
}

void main() {
    int array [] = {14, 2, 6, 8, 5, 4, 3, 1, 7, 9, 6, 10, 17, 20, 12, 19};
    int n = sizeof(array) / 4;
    heapMax(n, array);

    printf("[");
    for(int i =0; i < n ; i++ ){
        printf("%d, ", array[i]);
    }
    printf("]");
}