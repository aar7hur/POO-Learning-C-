#include <iostream>
#include "fracao.h"

void head (void);
void escolhaOperacao (void);

int main(int argc, char** argv) 
{
	head();
	escolhaOperacao();
	return 0;
}
void head (void)
{
	std::cout << "TE353 - Programacao Orientada a Objetos  *\n";
	std::cout << "Profesorra: Giselle Lopes Ferrari        *\n";
	std::cout << "Nome: Vinicius Tertulino Parede          *\n";
	std::cout << "GRR: 20172137                            *\n";
	std::cout << "******************************************\n";
	std::cout << "           Operacoes com Fracao";
	std::cout << "\n";
	std::cout << "\n";
	
	return;	
}
void escolhaOperacao (void)
{
	fracao A;
	std::cout << "\n";
	fracao B;
	fracao C(0,0);
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
			//soma
			C = A + B;
			C.imprime();
			break;
		case 2:
			C = A - B;
			C.imprime();
			break;
		case 3:
			C = A * B;
			C.imprime();
			break;
		case 4:	
			C = A / B;
			C.imprime();
			break;
		default: 
			std::cout << "Valor de operacao invalido\n";
			break;
	}	
	return;
}

