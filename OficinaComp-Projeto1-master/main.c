// Aluna: Helena Regina Salomé D'Espindula
// GRR: 20161445

#include <stdio.h>
#include "lcrandom.h"
#define MAX 9


int main()
{
	long x, s, A, C, M;
	int i;
	printf("Semente: \n");
	scanf("%ld", &s);
	lcrandom_seed (s);
	printf("Multiplicador(A), Incremento(C) e Modulo(M) - caso usar default colocar  0s: \n");
        scanf("%ld %ld %ld", &A, &C, &M);
	if ( (A>0) && (C>0) && (M>0) )
	{
		lcrandom_parms (A, C, M);
	}
	
	for (i=0; i<MAX; i++)
	{
		x = lcrandom();
		printf("x%d = %ld \n", (i+1) ,x);
	}

	return(0);
}
