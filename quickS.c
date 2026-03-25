#include <stdio.h>

void imprime_janela(int v[], int inicio, int fim, int tamanho_total) {
    for (int i = 0; i < tamanho_total; i++) {
        if (i >= inicio && i <= fim) 
            printf("[%d] ", v[i]); // Destaque para a parte ativa
        else 
            printf(" %d  ", v[i]); // Parte "quieta" do vetor
    }
    printf("\n");
}

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int v[], int inicio, int fim, int tam){
    int pivo = v[inicio];
    int fronteira_menor = inicio;
    int fronteira_maior = fim;

    printf("--- Particionando com pivo %d (indices %d a %d) ---\n", pivo, inicio, fim);

    for (int i=(inicio+1); i<=fim; i++) {
        if(v[i]<pivo){
            fronteira_menor++;
            troca(&v[fronteira_menor], &v[i]);
        }
    }
    troca(&v[inicio], &v[fronteira_menor]);

    imprime_janela(v, inicio, fim, tam);
    printf("Pivo %d fixado na posicao %d\n\n", pivo, fronteira_menor);
    return fronteira_menor;
}

void quickS(int v[], int inicio, int fim, int tam){
    int q;
    if(inicio < fim) {
        q = partition(v, inicio, fim, tam);

        printf("Indo para ESQUERDA de %d (indices %d a %d)\n", v[q], inicio, q - 1);
        quickS(v, inicio, q-1, tam);

        printf("Indo para DIREITA de %d (indices %d a %d)\n", v[q], q + 1, fim);
        quickS(v, q+1, fim, tam);
    }
     
}

int main(){
    int v[] = {10, 5, 4, 9, 10, 2, 3, 10, 28};
    int inicio = 0;
    int tamanho = sizeof(v)/sizeof(v[0]);
    int fim = tamanho-1;
    
    quickS(v, inicio, fim, tamanho);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) printf("%d ", v[i]);
    printf("\n");

    return 0;
}