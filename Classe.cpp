#include <iostream>
#include <string>
#include "Classe.h"

Empresa::Empresa()
{
	std::cout << "Digite os Dados da Empresa para o cadastro: \n";
}
Restaurante::Restaurante()
{
	std::cout << "Digite os Dados do Restaurante para o cadastro: \n";
}
Empresa::Empresa(char nome, char endereco, char cidade, char estado, int cep, int telefone)
{
	nome = nome;
	endereco = endereco;
	cidade = cidade;
	estado = estado;
	cep = cep;
	telefone = telefone;
}
Restaurante::Restaurante(char comida, int preco)
{
	comida = comida;
	preco = preco;
}
void Restaurante::getdata()
{
	Empresa::getdata();
	std::cout << "Tipo da comida: ";
	std::cin >> comida;
	std::cout << "Preco medio da comida: ";
	std::cin >> preco;
	std::cout << "--------------------------------------------\n";
}
void Empresa::getdata()
{
	std::cout << "Nome: ";
	std::cin.getline(nome, 100);	
	std::cout << "Endereco: ";
	std::cin.getline(endereco, 100);
	std::cout << "Cidade: ";
	std::cin.getline(cidade, 100);
	std::cout << "Estado: ";
	std::cin.getline(estado, 100);
	std::cout << "CEP: ";
	std::cin >> cep;
	std::cout << "Telelefone: ";
	std::cin >> telefone;
	std::cout << "\n";
}
void Restaurante::putdata()
{
	Empresa::putdata();
	std::cout << "Tipo da comida: " << comida << "\n";
	std::cout << "Preco medio da comida: " << preco << "\n";
}
void Empresa::putdata()
{
	std::cout << "Nome: " << nome << "\n";
	std::cout << "Endereco: " << endereco << "\n";
	std::cout << "Cidade: " << cidade << "\n";
	std::cout << "Estado: " << estado << "\n";
	std::cout << "CEP: " << cep << "\n";
	std::cout << "Telefone: " << telefone << "\n"; 
}
Empresa::~Empresa(){}
Restaurante::~Restaurante(){}
