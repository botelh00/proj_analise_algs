#include <stdio.h>

void imprimirArray(int v[], int tam) {
    printf("{");
    for(int i = 0; i<tam; i++) {
        printf("%d ", v[i]);
    }
    printf("}");
    printf("\n");
}

void countinSort(int v[], int n, int exp){
    int saida[n];
    int count[10] = {0};

    for(int i = 0; i<n; i++) {
        count[(v[i]/exp)%10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n-1; i >= 0; i--) {
        saida[count[(v[i]/exp)%10]-1] = v[i];
        count[(v[i]/exp)%10]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
}

int achaMaior(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i<n; i++) {
        if(v[i]>maior) {
            maior = v[i];
        }
    }
    return maior;
}

void radix_sort(int v[], int n) {
    int maior = achaMaior(v, n);

    int passagem = 1;
    for(int exp = 1; maior/exp > 0; exp *= 10){
        countinSort(v, n, exp);
        printf("Passagem %d: ", passagem++);
        imprimirArray(v, n);
    }
}

int main(){
    int v[8] = {156, 215, 157, 256, 36, 23, 27, 156};
    int tam = sizeof(v)/sizeof(v[0]);

    printf("Array Original: ");
    imprimirArray(v, tam);
    printf("\n");

    printf("Inicio da ordenação: ");
    printf("\n");
    radix_sort(v, tam);

    printf("Array ordenado: ");
    imprimirArray(v, tam);

}