#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int numerador, denominador;
}num;

void cabecalho (void);
void leituraNumeros (void);
int mdc (num mdc);
int mmC (num mmcA, num mmcB);
void exibe (num exibeA, num exibeB, int xA, int xB);
void soma (num somaA, num somaB);
void sub (num subA, num subB);
void mult (num multA, num multB);
void divisao (num divA, num divB);

int main(int argc, char *argv[]) 
{
	cabecalho();
	leituraNumeros();
	return 0;
}
void leituraNumeros (void)
{
	num numA, numB;
	int mdcA, mdcB, mmc;
		
	printf("Numero Racional A\n");
	printf("Numerador A: ");
	scanf("%d", &numA.numerador);
	printf("Denominador A: ");
	scanf("%d", &numA.denominador);
	printf("\n");
	printf("Numero Racional B\n");
	printf("Numerador B: ");
	scanf("%d", &numB.numerador);
	printf("Denominador B: ");
	scanf("%d", &numB.denominador);
	printf("\n");
	
	printf("Numerador A: %d || Denominador A: %d\n", numA.numerador, numA.denominador);
	printf("Numerador B: %d || Denominador B: %d\n", numB.numerador, numB.denominador);
	printf("\n");
	
	mdcA = mdc(numA);
	mdcB = mdc(numB); 
	mmc = mmC(numA, numB);
	
	//printf("MMC: %d\n", mmc);

	exibe(numA, numB, mdcA, mdcB);
	soma(numA, numB);
	sub(numA, numB);
	mult(numA, numB);
	divisao(numA, numB);
	
	return;
}
void exibe (num exibeA, num exibeB, int xA, int xB)
{
	printf("A = %d/%d = %d/%d = %f\n", exibeA.numerador, exibeA.denominador, exibeA.numerador/xA, exibeA.denominador/xA, (float)exibeA.numerador/exibeA.denominador);
	printf("B = %d/%d = %d/%d = %f\n", exibeB.numerador, exibeB.denominador, exibeB.numerador/xB, exibeB.denominador/xB, (float)exibeB.numerador/exibeB.denominador);
	return;
}
void soma (num somaA, num somaB)
{
	num equacao;
	int x;
	
	equacao.denominador = somaA.denominador * somaB.denominador;
	somaA.numerador = (equacao.denominador / somaA.denominador) * somaA.numerador;
	somaB.numerador = (equacao.denominador / somaB.denominador) * somaB.numerador;
	equacao.numerador = somaA.numerador + somaB.numerador;
	x = mdc(equacao);
	
	printf("A + B = %d/%d = %d/%d = %f\n", equacao.numerador, equacao.denominador, equacao.numerador/x, equacao.denominador/x, (float)equacao.numerador/equacao.denominador);
}
void sub (num subA, num subB)
{
	num equacao;
	int x;
	
	equacao.denominador = subA.denominador * subB.denominador;
	subA.numerador = (equacao.denominador / subA.denominador) * subA.numerador;
	subB.numerador = (equacao.denominador / subB.denominador) * subB.numerador;
	equacao.numerador = subA.numerador - subB.numerador;
	x = mdc(equacao);
	
	printf("A - B = %d/%d = %d/%d = %f\n", equacao.numerador, equacao.denominador, equacao.numerador/x, equacao.denominador/x, (float)equacao.numerador/equacao.denominador);
}
void mult (num multA, num multB)
{
	num equacao;
	int x;
	
	equacao.numerador = multA.numerador * multB.numerador;
	equacao.denominador = multA.denominador * multB.denominador;
	x = mdc(equacao);
	
	printf("A * B = %d/%d = %d/%d = %f\n", equacao.numerador, equacao.denominador, equacao.numerador/x, equacao.denominador/x, (float)equacao.numerador/equacao.denominador);
}
void divisao (num divA, num divB)
{
	num equacao;
	int x;
	
	equacao.numerador = divA.numerador * divB.denominador;
	equacao.denominador = divB.numerador * divA.denominador;
	x = mdc(equacao);
	
	printf("A / B = %d/%d = %d/%d = %f", equacao.numerador, equacao.denominador, equacao.numerador/x, equacao.denominador/x, (float)equacao.numerador/equacao.denominador);	
}
int mdc (num mdc)
{
	int resto; 
	
	do
	{
		resto = mdc.numerador % mdc.denominador;
		mdc.numerador = mdc.denominador;
		mdc.denominador = resto;
	}while (resto != 0);
	return mdc.numerador;
}
int mmC (num mmcA, num mmcB)
{
	int resto, a, b;
	
	a = mmcA.denominador;
	b = mmcB.denominador;
	
	do
	{
		resto = a % b;
		a = b;
		b = resto;
	}while (resto != 0);
	
	return (mmcA.denominador * mmcB.denominador) * a;
}
void cabecalho (void)
{
	printf("TE353 - Programacao Orientada a Objetos *\n");
	printf("Professora: Giselle Lopes Ferrari       *\n");
	printf("Nome: Vinicius Tertulino Parede         *\n");
	printf("GRR: 20172137                           *\n");
	printf("*****************************************\n");
	printf("OPERACOES ARITMETICAS COM NUMEROS RACIONAIS\n"); 
	printf("\n");
	printf("\n");
}
