// Aluna: Helena Regina Salomé D'Espindula
// GRR: 20161445

#include <math.h>
#include "lcrandom.h"

// Declaração de variaveis globais e valores default
long seed = 0;
long multiplier=40692;
long increment=127;
long modulus=10000000;

// calcula e devolve um valor pseudoaleatório
long lcrandom ()
{
	long x;
	x = (multiplier * seed + increment) % modulus;
	seed = x;
	return(x);
}

// define o valor inicial (semente) da sequência de aleatórios
void lcrandom_seed (long s)
{
	seed = s;
}

// informa o valor máximo que pode ser gerado (mínimo é zero)
long lcrandom_max ()
{
	return(modulus-1);
} 


// modifica os parâmetros da equação do gerador; por default
// devem ser usados: A=40692, C=127 e M=10000000
void lcrandom_parms (long A, long C, long M)
{
	multiplier = A;
	increment = C;
	modulus = M;
}

