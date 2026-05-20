#include <stdio.h>

void imprimirArray(int v[], int tam) {
    printf("{");
    for(int i = 0; i<tam; i++) {
        printf("%d ", v[i]);
    }
    printf("}");
    printf("\n");
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void afunda(int v[], int tam, int pai) {
    int maior = pai;
    int esq = 2*pai+1;
    int dir = 2*pai+2;

    if (esq < tam && v[esq] > v[maior]) {
        maior = esq;
    }

    if (dir < tam && v[dir] > v[maior]) {
        maior = dir;
    }

    if(maior != pai) {
        trocar(&v[pai], &v[maior]);
        afunda(v, tam, maior);
        imprimirArray(v, tam);
    }
}

void heapSort(int v[], int tam) {
    for (int i = tam/2 - 1; i >= 0; i--) {
        afunda(v, tam, i);
    }

    for (int i = tam - 1; i>0; i--) {
        trocar(&v[0], &v[i]);
        imprimirArray(v, tam);
        afunda(v, i, 0);
    }
}

int main() {
    int v[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam = sizeof(v) / sizeof(v[0]);

    printf("Array original: \n");
    imprimirArray(v, tam);

    printf("Inicio da ordenação: \n");

    heapSort(v, tam);

    printf("Array ordenado: \n");
    imprimirArray(v, tam);

    return 0;
}