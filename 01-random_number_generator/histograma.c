// Aluna: Helena Regina Salomé D'Espindula
// GRR: 20161445

#include <stdio.h>
#include "lcrandom.h"
#define MAX_VETOR 100
#define MAX_TESTES 1000000

// Função responsavel por "zerar" (preencher com 0s) o vetor
void zera_vetor(int v[])
{
	printf("Zerando vetor... \n");
	int i;
	for ( i = 0; i < MAX_VETOR; i++)
	{
		v[i] = 0;
	}

}

// Função responsavel por achar o maior numero randomico gerado

long acha_maior (int v[])
{
	int i;
	long m = v[0];
	for (i=0; i< MAX_VETOR; i++)
	{
		if ( v[i] > m )
		{
			m = v[i];
		}
	}
	
	return(m);
}

// Função responsavel pela impressão do grafico

void plot_histograma (int v[], long *maior)
{
	int i, j, max_j;
	max_j = 5;

	printf("Gerando histograma...\n");

	// Impressão da primeira linha - numeros da escala

	printf("   ");
	
	for ( i = 0; i <= MAX_VETOR; i=i+5)
	{
		printf ("%d", i);
		if (i>9)
		{
			max_j = 4;
		}
		for ( j = 0; j < max_j; j++)
		{
			printf(" ");
		}
	}

	printf("\n");

	// Impressão da segunda linha - ("-" e "+") da escala

	printf("   ");
	
	max_j = 5;
        for ( i = 0; i <= MAX_VETOR; i=i+5)
        {
                printf ("+");
                if (i < MAX_VETOR)
		{
			for ( j = 0; j < max_j; j++)
	                {
        	                printf("-");
                	}
		}
        }

	printf("\n");

	// Impresão das linhas seguintes utilizando os valores no vetor

	for ( i = 0; i < MAX_VETOR; i++)
        {
		if (i<10)
		{
			printf(" ");
		}
	        printf ("%d |", i);
		max_j = v[i] * MAX_VETOR / (*maior); // normatização
                if (i < MAX_VETOR)
                {
                        for ( j = 0; j < max_j; j++)
                        {
                                printf("*");
				if ((j+1) % 5 == 0)
				{
					printf(" ");
				}
                        }
                }
		printf ("\n");
        }

	// Impressão da legenda	

	printf("Legenda: \n");
	printf(" A maior contagem obtida foi %ld que equivale a 100 no histograma e foi utilizada para normatizar as demais \n", *maior);
	printf(" O espaço entre os arteriscos marca 5 unidades e seve para facilitar a visulização \n");
	printf("\n");
}

// Função responsevel por gerar um numero randomico e utilizar seus ultimos dois digitos

void gera_random (int v[])
{
	long i, x;
	for (i=0; i<MAX_TESTES ; i++)
        {
                x = lcrandom();
                v[x%100]++;
        }

}

// Função responsavel pro chamar todas as demais funções necessarias para obter o histograma

void realiza_teste (int vetor[], long *maior)
{
        zera_vetor(vetor);
        gera_random (vetor);
        *maior = acha_maior(vetor); // será usado para normatizar
        plot_histograma(vetor, maior);
}

int main()
{
	int vetor[MAX_VETOR];
	long maior;

	// Valores do glibc

	long A = 1103515245;
	long C = 12345;
	long M = 2147483648;

	printf("\nAVISO: Os histogramas são melhor visualizados se o terminal estiver em tela cheia\n");

	// Teste com valores default

	printf("\n1o Histograma - com valores default \n");
	realiza_teste(vetor, &maior);

	// Teste com outros valores, no caso os do glibc
	
	printf("\n2o Histograma - com valores do glibc (utilizados pelo GCC):\n A = %ld, C = %ld, M = %ld e Seed = 0.\n", A, C, M);
	lcrandom_parms (A, C, M);
        realiza_teste(vetor, &maior);
	

	return(0);
}
