#include <iostream>
#include <string>
#include "Classe.h"

void intro (void);
void escolhaVeiculo(void);
void carro(void);
void caminhao(void);

int main(int argc, char** argv) 
{	
	intro();
	escolhaVeiculo();
	return 0;
}
void intro (void)
{
	std::cout << "TE353 - Programacao Orientada a Objetos  *\n";
	std::cout << "Profesorra: Giselle Lopes Ferrari        *\n";
	std::cout << "Nome: Vinicius Tertulino Parede          *\n";
	std::cout << "GRR: 20172137                            *\n";
	std::cout << "******************************************\n";
	std::cout << "  Exercicio Heranca Multipla --> Aula 07";
	std::cout << "\n";
	std::cout << "\n";
	return;
}
void escolhaVeiculo (void)
{
	int veiculo;
	
	std::cout <<"  1 -> Carro de Passeio || 2 -> Caminhao \n\n";
	std::cout << "Digite o tipo de veiculo para cadastro no sistema: "; 
	std::cin >> veiculo;
	
	switch (veiculo)
	{
		case 1:
			carro();
			break;
		case 2:
			caminhao();
			break;
		default:
			system("cls");
			intro();
			std::cout << "Numero invalido... \n";
			break;	
	}
		
}
void carro (void)
{
	CarroPasseio carro;
	carro.getdata();
	
	int teste;
	std::cout << "1 --> Exibicao dos dados do Motor \n";
	std::cout << "2 --> Exibicao dos dados do Veiculo \n";
	std::cout << "3 --> Exibicao dos dados de Carro de Passeio \n";
	std::cout << "4 --> Exibicao dos dados de um Caminhao \n";
	std::cout << "Digite o numero do exercio p/ teste: ";
	std::cin >> teste;
	
	switch (teste)
	{
		case 1:
			system("cls");
			intro();
			carro.Motor::putdata();
			break;
		case 2:
			system("cls");
			intro();
			carro.Veiculo::putdata();
			break;
		case 3:
			system("cls");
			intro();
			carro.putdata();
			break;
		case 4:
			system("cls");
			intro();
			std::cout << "Nao e possivel realizar o teste, devido a escolha do veiculo para cadastro ser o 'CARRO DE PASSEIO'...\n";
			std::cout << "Para realizar esse teste, escolha o veiculo 'CAMINHAO'...\n";
			break;
		default:
			system("cls");
			intro();
			std::cout << "Numero de teste invalido...";
			break;
	}	
}
void caminhao (void)
{
	Caminhao caminhao;
	caminhao.getdata();
	
	int teste;
	std::cout << "\n1 --> Exibicao dos dados do Motor \n";
	std::cout << "2 --> Exibicao dos dados do Veiculo \n";
	std::cout << "3 --> Exibicao dos dados de Carro de Passeio \n";
	std::cout << "4 --> Exibicao dos dados de um Caminhao \n";
	std::cout << "Digite o numero do exercio p/ teste: ";
	std::cin >> teste;
	
	switch (teste)
	{
		case 1:
			system("cls");
			intro();
			caminhao.Motor::putdata();
			break;
		case 2:
			system("cls");
			intro();
			caminhao.Veiculo::putdata();
			break;
		case 3:
			system("cls");
			intro();
			std::cout << "Nao e possivel realizar o teste, devido a escolha do veiculo para cadastro ser o 'CAMINHAO'...\n";
			std::cout << "Para realizar esse teste, escolha o veiculo 'CARRO DE PASSEIO'...\n";
			break;
		case 4:
			system("cls");
			intro();
			caminhao.putdata();
			break;
		default:
			system("cls");
			intro();
			std::cout << "Numero de teste invalido...";
			break;
	}
}
