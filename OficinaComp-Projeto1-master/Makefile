# Regra default

all: histograma periodo

# Regras de ligação

histograma: histograma.c lcrandom.c
	gcc histograma.c lcrandom.c -o histograma -Wall

periodo: periodo.c lcrandom.c
	gcc periodo.c lcrandom.c -o periodo -Wall

# Regras de compilação

histograma.o: histograma.c random.h
	gcc -c histograma.c -Wall
 
periodo.o: periodo.c random.h
	gcc -c periodo.c -Wall
 
lcrandom.o: lcrandom.c lcrandom.h
	gcc -c lcrandom.c -Wall
