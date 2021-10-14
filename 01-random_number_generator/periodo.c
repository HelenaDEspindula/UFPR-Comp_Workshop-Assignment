// Aluna: Helena Regina Salomé D'Espindula
// GRR: 20161445

#include <stdio.h>
#include "lcrandom.h"
#define MAX 2147483650 //Valor escolhido devido ao M do glibc

unsigned char vetor[MAX]; //Vetor de char para ocupar menos espaço de memoria

// Função responsavel por "zerar" o vetor (preencher com 0s)

void zera_vetor ()
{
	long i;
	printf("Zerando vetor... \n");
		for ( i = 0; i < MAX; i++)
		{
			vetor[i] = 0;
		}
}

// Função responsavel por gerar os numeros randomicos e marcar (com 1) no vetor quais os valores já obtidos. Para quando o primeiro número repete (encontra um 1 no vetor) e imprime o periodo

void testa_random ()
{
	printf("Calculando periodo... ");
	long x;
	long periodo = 0;
	unsigned long i = 0;
	while (periodo == 0)
	{
	   	x = lcrandom();
		if (vetor[x] == 0)
		{
			vetor[x] = 1;
		}
		else if (vetor[x] == 1)
		{
			periodo = i;
		}
		i++;	
	}
	printf ("Periodo obtido: %ld \n", periodo);
}

// MAIN

int main()
{
	// Valores do glibc
	long A = 1103515245;
	long C = 12345;
	long M = 2147483648;
	
	// Periodo com valores default

	printf("\n1o Calculo de periodo - com valores default \n");
	zera_vetor();
	testa_random();
	
	// Perido com valores do glibc

	printf("\n2o Calculo de periodo - com valores do glibc (utilizados pelo GCC):\n");
	printf("A = %ld, C = %ld, M = %ld e Seed = 0.\n", A, C, M);
	zera_vetor();
	lcrandom_parms (A, C, M);
	testa_random();
	
	return(0);
}
