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
	NumCilindro = NumCilindro;
	Potencia = Potencia;	
}
void Motor::getdata()
{
	std::cout << "\nMotor getdata()... \n";
	std::cout << "Numero de Cilindros do Motor: ";
	std::cin >> NumCilindro;
	std::cout << "Potencia do Motor[cv]: ";
	std::cin >> Potencia;
}
void Motor::putdata()
{
	std::cout << "\nMotor putdata()... \n";
	std::cout << "Numero de Cilindros do Motor: " << NumCilindro << "\n";
	std::cout << "Potencia do Motor: " << Potencia << "cv" << "\n";
}
Veiculo::Veiculo()
{
	this->Peso = 0;
	this->VelocMax = 0;
}
Veiculo::Veiculo(int Peso, int VelocMax)
{
	Peso = Peso;
	VelocMax = VelocMax;	
}
void Veiculo::getdata()
{
	std::cout << "\nVeiculo getdata()... \n";
	std::cout << "Peso do veiculo[kg]: ";
	std::cin >> Peso;
	std::cout << "Velocidade maxima do veiculo[km/h]: ";
	std::cin >> VelocMax;
}
void Veiculo::putdata()
{
	std::cout << "\nVeiculo putdata()... \n";
	std::cout << "Peso do veiculo: " << Peso << "kg" << "\n";
	std::cout << "Velocidade Maxima do veiculo: " << VelocMax << "km/h" << "\n";
}
CarroPasseio::CarroPasseio():Motor(), Veiculo()
{
	for(int i = 0; i < 100; i++)
	{
		this->Cor[i] = 0;
		this->Modelo[i] = 0;
	}	
}
CarroPasseio::CarroPasseio(int NumCilindro, int Potencia, int Peso, int VelocMax, char Cor, char Modelo):Motor(NumCilindro, Potencia), Veiculo(Peso, VelocMax)
{
	Cor = Cor;
	Modelo = Modelo;
}
void CarroPasseio::getdata()
{
	Motor::getdata();
	Veiculo::getdata();
	std::cout << "\nCarro de Passeio getdata()... \n";
	std::cout << "Cor do veiculo: ";
	std::cin.getline(Cor,100);
	std::cin.getline(Cor, 100);	
	std::cout << "Modelo do veiculo: ";
	std::cin.getline(Modelo, 100);
	std::cout << "\n";
	
}
void CarroPasseio::putdata()
{
	Motor::putdata();
	Veiculo::putdata();
	std::cout << "\nCarro de Passeio putdata()... \n";
	std::cout << "Cor do veiculo: " << Cor << "\n";
	std::cout << "Modelo do veiculo: " << Modelo << "\n";
}
Caminhao::Caminhao():Motor(), Veiculo()
{
	this->Toneladas = 0;
	this->AlturaMax = 0;
	this->Comprimento = 0;
}
Caminhao::Caminhao(int NumCilindro, int Potencia, int Peso, int VelocMax, char Cor, char Modelo, int Toneladas, int AlturaMax, int Comprimento):Motor(NumCilindro, Potencia), Veiculo(Peso, VelocMax)
{
	Toneladas = Toneladas;
	AlturaMax = AlturaMax;
	Comprimento = Comprimento;
}
void Caminhao::getdata()
{
	Motor::getdata();
	Veiculo::getdata();
	std::cout << "\nCaminhao getdata()... \n";
	std::cout << "Carga Maxima do Caminhao[T]: ";
	std::cin >> Toneladas;
	std::cout << "Altura Maxima do Caminhao[m]: ";
	std::cin >> AlturaMax;
	std::cout << "Comprimento do Caminhao[m]: ";
	std::cin >> Comprimento;
}
void Caminhao::putdata()
{
	Motor::putdata();
	Veiculo::putdata();
	std::cout << "\nCaminhao putdata()... \n";
	std::cout << "Carga Maxima do Caminhao: " << Toneladas << " Toneladas" << "\n";
	std::cout << "Altura Maxima do Caminhao: " << AlturaMax << "m" << "\n";
	std::cout << "Comprimento do Caminhao: " << Comprimento << "m" << "\n";
}
Motor::~Motor(){}
Veiculo::~Veiculo(){}
CarroPasseio::~CarroPasseio(){}
Caminhao::~Caminhao(){}
