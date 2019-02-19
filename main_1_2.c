#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_NUMEROS 10
#define MAX_TEXTO 255

typedef int INT;
typedef INT *PTR_INT;
typedef char CHAR;
typedef INT VETOR[MAX_NUMEROS];
typedef PTR_INT PTR_VETOR;
typedef CHAR STRING[MAX_TEXTO];

typedef void (*FUNC_ORDEM)(PTR_VETOR, INT, INT);

void exbirPtrVetor(STRING texto, PTR_VETOR vetor){
    int i;
    printf("%s\n", texto);
    for (i = 0; i < MAX_NUMEROS; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void trocar (int *ptr_x, int *ptr_y) {
    int aux = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = aux;
}

void ordemCrescente(PTR_VETOR ptr_vetor, INT i, INT j){
    if (ptr_vetor[j] > ptr_vetor[j + 1]) {
        trocar(&ptr_vetor[j], &ptr_vetor[j + 1]);
    }
}

void ordemDecrescente(PTR_VETOR ptr_vetor, INT i, INT j){
    if (ptr_vetor[j] < ptr_vetor[j + 1]) {
        trocar(&ptr_vetor[j], &ptr_vetor[j + 1]);
    }
}


void bubbleSort(PTR_VETOR ptr_vetor, FUNC_ORDEM ordem ){
    INT i, j, aux;
    for (i = 0; i < MAX_NUMEROS - 1; i++){
        for (j = 0; j < MAX_NUMEROS - i - 1; j++) {
            ordem(ptr_vetor, i, j);
        }
    }
}

int main (int argc, char* argv[]) {
    // Utilizando caracteres e acentuação da língua portuguesa!
    setlocale(LC_ALL, "Portuguese");

    VETOR vetor = {10, 20, 1, 5, 4, -1, 15, 10, 45, 9};
    PTR_VETOR ptr_vetor = &vetor[0];

    exbirPtrVetor("Vetor inicial", ptr_vetor);

    printf("Colocando os números em ordem crescente...\n");
    bubbleSort(ptr_vetor, ordemCrescente);
    exbirPtrVetor("Vetor ordenado", ptr_vetor);

    printf("Colocando os números em ordem descrescente...\n");
    bubbleSort(ptr_vetor, ordemDecrescente);
    exbirPtrVetor("Vetor ordenado", ptr_vetor);

	return EXIT_SUCCESS;
}
