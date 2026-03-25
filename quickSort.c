#include <stdio.h>

void imprime_vetor(int v[]){
    
    int tamanho = sizeof(v)/sizeof(v[0]);

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

int partition(int v[], int inicio, int fim){
    /**if(resposta == 'S'){
        troca(&v[inicio], &v[fim]);
    }*/
    int pivo = v[inicio];
    int fronteira_menor = inicio;
    int fronteira_maior = fim;

    for (int i=(inicio+1); i<=fim; i++) {
        if(v[i]<pivo){
            fronteira_menor++;
            troca(&v[fronteira_menor], &v[i]);
            imprime_vetor(v);
        } else {
            imprime_vetor(v);
        }
    }
    troca(&v[inicio], &v[fronteira_menor]);
    imprime_vetor(v);
    return fronteira_menor;
}

void quickS(int v[], int inicio, int fim){
    if(inicio < fim) {
        int q = partition(v, inicio, fim);
        imprime_vetor(v);
        quickS(v, inicio, q-1);
        imprime_vetor(v);
        quickS(v, q+1, fim);
        imprime_vetor(v);
    }
     
}

int main(){
    int v[] = {10, 5, 4, 9, 10, 2, 3, 10, 28};
    int inicio = 0;
    int tamanho = sizeof(v)/sizeof(v[0]);
    int fim = tamanho-1;
    char resposta;
    printf("Quer usar o ultimo como pivô? [S/N] ");
    scanf(" %c", &resposta);
    quickS(v, inicio, fim);

    return 0;
}