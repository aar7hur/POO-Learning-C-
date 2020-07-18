#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/****************************************************/
void limpaTela (void);
void cabecalho (void);
char jogadorA (char matriz[3][3]);
char jogadorB (char matriz[3][3]);
char regrasA (char matriz[3][3]);
char regrasB (char matriz[3][3]);
void leituraDados (char matriz[3][3]);
char tabuleiro (char matriz[3][3]);
/****************************************************/

/********************Função Principal****************/
int main(int argc, char *argv[]) 
{
	int linha, coluna;
	char matriz[3][3];
	int i, j;
	
	cabecalho();
	for (i = 0; i < 3; i ++)
	{
		for(j = 0; j < 3; j ++)
		{
			matriz[i][j] = '*';
		}
	}
	for(;;)
	{
		limpaTela();
		cabecalho();
		tabuleiro (matriz);
		leituraDados(matriz);
	}	
	return 0;
}
char regrasA(char matriz[3][3])
{
	if ((matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X') || 
	    (matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR A VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	if ((matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X') || 
	    (matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR A VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	if ((matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X') || 
	    (matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR A VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	if ((matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X') || 
	    (matriz[2][0] == 'X' && matriz[1][1] == 'X' && matriz[0][2] == 'X'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR A VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	return (**matriz);
}
char regrasB (char matriz[3][3])
{
	if ((matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O') || 
	    (matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR B VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	if ((matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O') || 
	    (matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR B VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	if ((matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O') || 
	    (matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR B VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	if ((matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O') || 
	    (matriz[2][0] == 'O' && matriz[1][1] == 'O' && matriz[0][2] == 'O'))
	    {
	    	limpaTela();
	    	cabecalho();
	    	tabuleiro(matriz);
	    	printf("JOGADOR B VENCEU !!!\n");
	    	system("pause");
	    	exit(0);
		}
	return (**matriz);
}
void leituraDados (char matriz[3][3])
{	
	jogadorA(matriz);
	jogadorB(matriz);
}
char jogadorA (char matriz[3][3])
{
	int contadorA = 0;
	int i, j;
	int lA, cA;
	
	printf("Jogador A, digite a linha da jogada L: ");
	scanf("%d", &lA);
	if ((lA < 1) || (lA > 3))
	{
		printf("Jogada Invalida\n\n");
		jogadorA(matriz);
	}
	else
	{
		printf("Jogador A, digite a coluna da jogada C: ");
		scanf("%d", &cA);
		if ((cA < 1) || (cA > 3))
		{
			printf("Jogada Invalida\n\n");
			jogadorA(matriz);
		}
		else
		{
			if(matriz[lA - 1][cA - 1] == 'O')
			{
				printf("Jogada Invalida\n\n");
				jogadorA(matriz);		
			}
			else if	(matriz[lA - 1][cA - 1] == 'X')
			{
				printf("Jogada Invalida \n\n");
		        jogadorA(matriz);	
			}
			else
			{
				matriz[lA - 1][cA - 1] = 'X';	
			}	
		}	
	}		
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if(matriz[i][j] == 'X')
			{
				contadorA++;		
			}		
		}	
	}
	if (contadorA == 5)
	{
		limpaTela();
		cabecalho();
		tabuleiro(matriz);
		printf("EMPATE !!!\n");
		system("pause");
		exit(0);		
	}
	else if (contadorA < 5)
	{
		limpaTela();
		cabecalho();
		tabuleiro(matriz);
		regrasA(matriz);
		return(**matriz);	
	}
}
char jogadorB (char matriz[3][3])
{
	int i, j;
	int contadorB = 0;
	int lB, cB;
	
	printf("Jogador B, digite a linha da jogada L: ");
	scanf("%d", &lB);
	if ((lB < 1) || (lB > 3))
	{
		printf("Jogada Invalida\n\n");
		jogadorB(matriz);
	}
	else
	{
		printf("Jogador B, digite a coluna da jogada C: ");
		scanf("%d", &cB);
		if ((cB < 1) || (cB > 3))
		{
			printf("Jogada Invalida\n\n");
			jogadorB(matriz);
		}
		else
		{
			if (matriz[lB - 1][cB - 1] == 'X')
			{
				printf("Jogada Invalida\n\n");
				jogadorB(matriz);	
			}
			else if (matriz[lB - 1][cB - 1] == 'O')
			{
				printf("Jogada Invalida\n\n");
				jogadorB(matriz);	
			}
			else
			{
				matriz[lB - 1][cB - 1] = 'O';		
			}	
		}	
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if(matriz[i][j] == 'O')
			{
				contadorB++;		
			}		
		}	
	}
	if (contadorB == 5)
	{
		limpaTela();
		cabecalho();
		tabuleiro(matriz);
		printf("EMPATE !!!\n");
		system("pause");
		exit(0);		
	}
	else if (contadorB < 5)
	{
		limpaTela();
		cabecalho();
		tabuleiro(matriz);
		regrasB(matriz);
		return(**matriz);	
	}
}
char tabuleiro (char matriz[3][3])
{
	printf("         C1          C2          C3\n");
	printf("\n");
	printf("    L1    %c     |     %c     |     %c\n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("\n");
	printf("    L2    %c     |     %c     |     %c\n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("\n");
	printf("    L3    %c     |     %c     |     %c\n", matriz[2][0], matriz[2][1], matriz[2][2]);
	printf("\n");
	printf("Jogador A: X\n");
	printf("Jogador B: O\n");
	printf("\n");
	return (**matriz);
}
void limpaTela (void)
{
	system ("cls");
}
void cabecalho (void)
{
	printf("TE353 - Programacao Orientada a Objetos *\n");
	printf("Professora: Giselle Lopes Ferrari       *\n");
	printf("Nome: Vinicius Tertulino Parede         *\n");
	printf("GRR: 20172137                           *\n");
	printf("*****************************************\n");
	printf("                JOGO DA VELHA\n"); 
	printf("\n");
	printf("\n");
}
