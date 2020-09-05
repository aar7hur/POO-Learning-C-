#include <iostream>
#include <string>
#include "Classe.h"

Empresa::Empresa()
{}

Empresa::Empresa(string nome, string endereco, string cidade, 
				string estado, string cep, string telefone)
{
	this->nome = nome;
	this->endereco = endereco;
	this->cidade = cidade;
	this->estado = estado;
	this->cep = cep;
	this->telefone = telefone;
}
Restaurante::Restaurante(string nome, string endereco, string cidade, 
					string estado, string cep, string telefone,
					string comida, string preco)
	:Empresa(nome, endereco, cidade, estado, cep, telefone)
	{
		this->comida = comida;
		this->preco = preco;
	}

Restaurante::Restaurante() : Empresa(){}

void Restaurante::getdata()
{
	std::cout << "\nParametros do Restaurante: \n";
	Empresa::getdata();
	std::cout << "\tTipo de comida: ";
	std::getline(std::cin, comida);
	std::cout << "\tPreco medio da comida: ";
	std::getline(std::cin, preco);
}
void Empresa::getdata()
{
	std::cout << "\tNome: ";
	std::getline(std::cin, nome);	
	std::cout << "\tEndereco: ";
	std::getline(std::cin, endereco);
	std::cout << "\tCidade: ";
	std::getline(std::cin, cidade);
	std::cout << "\tEstado: ";
	std::getline(std::cin, estado);
	std::cout << "\tCEP: ";
	std::getline(std::cin, cep);
	std::cout << "\tTelelefone: ";
	std::getline(std::cin, telefone);
}
void Restaurante::putdata()
{
	std::cout << "\nAtributos do restaurante: \n";
	Empresa::putdata();
	std::cout << "Tipo da comida: " << this->comida << "\n";
	std::cout << "Preco medio da comida: " << this->preco << "\n";
}
void Empresa::putdata()
{
	std::cout << "\nNome: " << this->nome << "\n";
	std::cout << "Endereco: " << this->endereco << "\n";
	std::cout << "Cidade: " << this->cidade << "\n";
	std::cout << "Estado: " << this->estado << "\n";
	std::cout << "CEP: " << this->cep << "\n";
	std::cout << "Telefone: " << this->telefone << "\n"; 
}
Empresa::~Empresa(){}
Restaurante::~Restaurante(){}
