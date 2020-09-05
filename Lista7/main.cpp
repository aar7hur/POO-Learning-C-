#include <iostream>
#include <string>
#include "Classe.h"

using namespace std;

void testa_carro_passeio(void);
void testa_caminhao(void);
void testa_motor(void);
void testa_veiculo(void);

const int NumCilindro = 10;
const int Potencia = 200;
const int Peso = 4000;
const int VelocMax = 80;
const string Cor = "azul";
const string Modelo = "V12";
const int Toneladas = 4; 
const int AlturaMax = 4;
const int Comprimento = 24;

int main(int argc, char** argv) 
{	
	testa_motor();
	testa_veiculo();
	testa_caminhao();
	testa_carro_passeio();
	return 0;
}

void testa_motor(void)
{
	int num_cilindros = 10;
	int potencia = 150;
	Motor testa_construtor(10, 150);
	
	std::cout << "\n*****************************************\n";
	cout << "---->Testando a classe Motor atraves do construtor!" << endl;
	testa_construtor.putdata();
	
	Motor testa_getdata;
	cout << "\n\n--->Testando a classe Motor atraves metodo getData! \n\n" << endl;
	testa_getdata.getdata();
	testa_getdata.putdata();
	
}

void testa_veiculo(void)
{
	int peso = 900;
	int VelocMax = 180;
	Veiculo testa_construtor(900, 180);
	std::cout << "\n*****************************************\n";
	cout << "--->Testando a classe Veiculo atraves do construtor! \n" << endl;
	testa_construtor.putdata();
	
	Veiculo testa_getdata;
	std::cout << "\n\n*****************************************\n";
	cout << "\n--->Testando a classe Veiculo atraves metodo getData! \n\n" << endl;
	testa_getdata.getdata();
	testa_getdata.putdata();
}

void testa_caminhao(void)
{	
	Caminhao testa_construtor(NumCilindro, Potencia, Peso,
								VelocMax, Toneladas,
								AlturaMax, Comprimento);
	
	std::cout << "\n*****************************************\n";
	cout << "--->Testando a classe Caminhao atraves do construtor! \n" << endl;
	testa_construtor.putdata();
	
	Caminhao testa_getdata;
	std::cout << "\n\n*****************************************\n";
	cout << "\n--->Testando a classe Caminhao atraves metodo getData! \n\n" << endl;
	testa_getdata.getdata();
	testa_getdata.putdata();
}

void testa_carro_passeio(void)
{	
	CarroPasseio testa_construtor(NumCilindro, Potencia, Peso,
								VelocMax, Cor, Modelo);
	
	std::cout << "\n*****************************************\n";
	cout << "--->Testando a classe Carro Passeio atraves do construtor! \n" << endl;
	testa_construtor.putdata();
	
	CarroPasseio testa_getdata;
	std::cout << "\n\n*****************************************\n";
	cout << "\n--->Testando a classe Carro Passeio atraves metodo getData! \n\n" << endl;
	testa_getdata.getdata();
	testa_getdata.putdata();
}


