/*
 * main.c
 *
 *  Created on: 01/03/2015
 *      Author: Marcelo Odir
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double expRec(int valor, int potencia) {

	if(potencia==0)
		return 1;
	if(potencia==1)
		return valor;

	if(potencia%2==0) {
		return expRec(valor,potencia/2) * expRec(valor,potencia/2);
	}else{
		return valor * expRec(valor,(potencia-1)/2) * expRec(valor,(potencia-1)/2);
	}
}

double expDefault(int valor, int potencia) {
	double saida;
	int i;

	if(potencia==0)
		return 1;
	if(potencia==1)
		return valor;

	saida = valor * valor;
	for(i=2;i<potencia;i++)
		saida = saida * valor;

	return saida;
}


int main(int argc, char **argv) {
	int valor = 2;
	int potencia = 10000;
	double resultado;
	double tempo01, tempo02,ini;

	ini = clock();
	resultado  = expRec(valor,potencia);
	tempo01 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
	printf("Modo RECURSIVO resultado: %.0lf, \ntempo de execução: %lf\n\n",resultado,tempo01);

	ini = clock();
	resultado  = expDefault(valor,potencia);
	tempo02 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
	printf("Modo INTERATIVO resultado: %.0lf, \ntempo de execução: %lf",resultado,tempo02);
	return EXIT_SUCCESS;
}



