#include <stdio.h>

void imprime_vetor(int v[], int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int v[], int inicio, int fim, int tamanho, char resposta){
    if(resposta == 'S'){
        troca(&v[inicio], &v[fim]);
    }
    int pivo = v[inicio];
    int fronteira_menor = inicio;
    int fronteira_maior = fim;

    for (int i=(inicio+1); i<=fim; i++) {
        if(v[i]<pivo){
            fronteira_menor++;
            troca(&v[fronteira_menor], &v[i]);
            imprime_vetor(v, tamanho);
        } else {
            imprime_vetor(v, tamanho);
        }
    }
    troca(&v[inicio], &v[fronteira_menor]);
    imprime_vetor(v, tamanho);
    return fronteira_menor;
}

int main(){
    int v[] = {10, 5, 4, 9, 10, 2, 3, 10, 28};
    int inicio = 0;
    int tamanho = sizeof(v)/sizeof(v[0]);
    int fim = tamanho-1;
    char resposta;
    printf("Quer usar o ultimo como pivô? [S/N] ");
    scanf(" %c", &resposta);
    partition(v, inicio, fim, tamanho, resposta);

    return 0;
}