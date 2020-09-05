#include <iostream>
#include <string>
#include "Classe.h"

Motor::Motor()
{
	this->NumCilindro = 0;
	this->Potencia = 0;	
}

Motor::Motor(int NumCilindro, int Potencia)
{
	this->NumCilindro = NumCilindro;
	this->Potencia = Potencia;	
}

void Motor::getdata()
{
	std::cout << "Numero de Cilindros do Motor: ";
	std::cin >> this->NumCilindro;
	std::cout << "Potencia do Motor: ";
	std::cin >> this->Potencia;
}

void Motor::putdata()
{
	std::cout << "\n\tOs dados do Motor sao: \n" << std::endl;
	std::cout << "\t\tO numero de Cilindros do Motor usado: " << this->NumCilindro << std::endl;
	std::cout << "\t\tA potencia do Motor usado: " << this->Potencia << std::endl;
}

Veiculo::Veiculo()
{
	this->Peso = 0;
	this->VelocMax = 0;
}

Veiculo::Veiculo(int Peso, int VelocMax)
{
	this->Peso = Peso;
	this->VelocMax = VelocMax;	
}

void Veiculo::getdata()
{
	std::cout << "Peso do veiculo: ";
	std::cin >> this->Peso;
	std::cout << "Velocidade maxima do veiculo: ";
	std::cin >> this->VelocMax;
}

void Veiculo::putdata()
{
	std::cout << "\n\tOs dados do Veiculo sao: \n" << std::endl;
	std::cout << "\t\tO peso do veiculo: " << this->Peso << std::endl;
	std::cout << "\t\tA velocidade maxima do veiculo: " << this->VelocMax << std::endl;
}

CarroPasseio::CarroPasseio():Motor(), Veiculo()
{
	
	this->Cor = "0";
	this->Modelo = "0";
	
}

CarroPasseio::CarroPasseio(int NumCilindro, int Potencia, 
							int Peso, int VelocMax, 
							string Cor, string Modelo)
				:Motor(NumCilindro, Potencia), Veiculo(Peso, VelocMax)
{
	this->Cor = Cor;
	this->Modelo = Modelo;
}

void CarroPasseio::getdata()
{
	Motor::getdata();
	Veiculo::getdata();

	std::cout << "A Cor do veiculo: ";
	std::cin >> this->Cor;	
	std::cout << "O Modelo do veiculo: ";
	std::cin >> this->Modelo;
}

void CarroPasseio::putdata()
{
	Motor::putdata();
	Veiculo::putdata();
	std::cout << "\n\tOs dados do Carro Passeio sao: \n" << std::endl;
	std::cout << "\t\tA Cor do veiculo: " << this->Cor << std::endl;
	std::cout << "\t\tO Modelo do veiculo: " << this->Modelo << std::endl;
}

Caminhao::Caminhao():Motor(), Veiculo()
{
	this->Toneladas = 0;
	this->AlturaMax = 0;
	this->Comprimento = 0;
}

Caminhao::Caminhao(int NumCilindro, int Potencia, int Peso, 
					int VelocMax, int Toneladas, int AlturaMax, int Comprimento)
					:Motor(NumCilindro, Potencia), Veiculo(Peso, VelocMax)
{
	this->Toneladas = Toneladas;
	this->AlturaMax = AlturaMax;
	this->Comprimento = Comprimento;
}

void Caminhao::getdata()
{
	Motor::getdata();
	Veiculo::getdata();
	std::cout << "A Carga Maxima do Caminhao: ";
	std::cin >> this->Toneladas;
	std::cout << "A Altura Maxima do Caminhao: ";
	std::cin >> this->AlturaMax;
	std::cout << "O Comprimento do Caminhao: ";
	std::cin >> this->Comprimento;
}

void Caminhao::putdata()
{
	Motor::putdata();
	Veiculo::putdata();
	std::cout << "\n\tOs dados do Caminhao sao: \n" << std::endl;
	std::cout << "\t\tA Carga Maxima do Caminhao: " << this->Toneladas << std::endl;
	std::cout << "\t\tA Altura Maxima do Caminhao: " << this->AlturaMax << std::endl;
	std::cout << "\t\tO Comprimento do Caminhao: " << this->Comprimento << std::endl;

}

Motor::~Motor(){}
Veiculo::~Veiculo(){}
CarroPasseio::~CarroPasseio(){}
Caminhao::~Caminhao(){}
