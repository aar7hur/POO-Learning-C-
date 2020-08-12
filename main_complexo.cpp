#include <iostream>
#include <math.h>
#include <string.h>
#include "complexo.h"

void leituraDados(void);
void cabecalho(void);
void escolhaOperacao(double a, double b, double c, double d);

int main(int argc, char** argv) 
{	
	cabecalho();
	leituraDados();
	return 0;
}
void leituraDados(void)
{
	double a, b, c, d;
	int escolha;
	
	std::cout << "Digite um numero real : ";
	std::cin >> a;
	std::cout << "Digite um numero imaginario : ";
	std::cin >> b;
	std::cout << "\n";
	std::cout << "Digite um numero real : ";
	std::cin >> c;
	std::cout << "Digite um numero imaginario : ";
	std::cin >> d;
	std::cout << "\n";
	
		Complexo dados(a,b,c,d);
		Complexo operacao(a,b,c,d);
	
		dados.numero();
		escolhaOperacao(a,b,c,d);
}
void escolhaOperacao (double a, double b, double c, double d)
{
	Complexo operacao(a,b,c,d);
	int i;
	
	std::cout << "1 - Soma\n";
	std::cout << "2 - Subtracao\n";
	std::cout << "3 - Multiplicacao\n";
	std::cout << "4 - Divisao\n";
	std::cout << "\n";
	
	std::cout << "Digite o numero de escolha da operacao: ";
	std::cin >> i;
	std::cout << "\n";
		
	switch (i)
	{
		case 1:
			operacao.exibeSoma();
			break;
		case 2:
			operacao.exibeSubtracao();
			break;
		case 3:
			operacao.exibeMultiplicacao();
			break;
		case 4:	
			operacao.exibeDivisao();
		default: 
			break;
	}	
	return;
}
void cabecalho (void)
{
	std::cout << "TE353 - Programacao Orientada a Objetos  *\n";
	std::cout << "Profesorra: Giselle Lopes Ferrari        *\n";
	std::cout << "Nome: Vinicius Tertulino Parede          *\n";
	std::cout << "GRR: 20172137                            *\n";
	std::cout << "******************************************\n";
	std::cout << "      Operacoes com Numeros Complexos";
	std::cout << "\n";
	std::cout << "\n";
	
	return;

}
