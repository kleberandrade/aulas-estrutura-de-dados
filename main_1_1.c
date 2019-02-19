#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMERO 5
#define EXIBIR_D(texto, numero) printf("%s %d\n",texto, numero)
#define EXIBIR_F(texto, numero) printf("%s %.2f\n",texto, numero)
#define LOOP(i,n) for(i = 0; i < (n); i++)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef int VETOR[MAX_NUMERO];

int procurarMenorValor(VETOR numeros){
	int i, menor = numeros[0];
	LOOP(i, MAX_NUMERO)
		menor = MIN(menor, numeros[i]);
	return menor;
}

int procurarMaiorValor(VETOR numeros){
	int i, maior = numeros[0];
	LOOP(i, MAX_NUMERO)
		maior = MAX(maior, numeros[i]);
	return maior;
}

float calcularMediaValor(VETOR numeros){
	int i, media = 0;
	LOOP(i, MAX_NUMERO)
		media += numeros[i];
	return media / (float)MAX_NUMERO;
}

int main (int argc, char* argv[]) {
	int i;
	VETOR numeros;
	LOOP(i, MAX_NUMERO){
	    printf("Digite o numero [%d/%d]: ", i+1, MAX_NUMERO);
		scanf("%d", &numeros[i]);
	}

	EXIBIR_D("Menor: ", procurarMenorValor(numeros));
	EXIBIR_D("Maior: ", procurarMaiorValor(numeros));
	EXIBIR_F("Media: ", calcularMediaValor(numeros));

	return EXIT_SUCCESS;
}
