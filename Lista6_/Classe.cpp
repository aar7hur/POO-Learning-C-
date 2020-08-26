/*
 * Classe.cpp
 *
 *  Created on: 21 de ago de 2020
 *      Author: amaralA
 */


#include "Classe.h"
#include <iostream>
#include <stdio.h>
	

/*
 * Classe.h
 *
 *  Created on: 21 de ago de 2020
 *      Author: amaralA
 *      nome,
 *	endereco, cidade, estado, CEP e telefone)
 */

Empresa::Empresa(void)
{}

Restaurante::Restaurante(void)
{
    Empresa();
}

Empresa::Empresa(std::string *dados)
	:nome(*dados),
	cidade(*(++dados)),
	estado(*(++dados)),
	cep(*(++dados)),
	telefone((*++dados))
{}

Restaurante::Restaurante(std::string *dados)
	:Empresa(dados)
	{
		tipo_comida = *(++dados);
		preco_medio = *(++dados);
	};

void Empresa::putdata(void)
{
	std::cout << "nome: " << this->nome << std::endl;
	std::cout << "cidade: " << this->cidade << std::endl;
	std::cout << "estado: " << this->estado << std::endl;
	std::cout << "telefone: " << this->telefone << std::endl;
	std::cout << "cep: " << this->cep << std::endl;
}

void Empresa::getdata(void)
{	

	std::cout << "Digite os dados para empresa " << std::endl;
	std::cout << "Nome: ";
	std::cin >> nome;
	std::cout << "Estado: ";
	std::cin >> estado;
	std::cout << "Telefone: ";
	std::cin >> telefone;
	std::cout << "Cep: ";
	std::cin >> cep;
	std::cout << "Cidade: ";
	std::cin >> cidade;
}




	
void Restaurante::getdata(void)
{
    Empresa::getdata();
	std::cout << "Digite o os dados do restaurante " << std::endl;
	std::cout << "Tipo de comida: ";
	std::cin >> tipo_comida;
	std::cout << "Preco medio: ";
	std::cin >> preco_medio;
}

void Restaurante::putdata(void)
{
	Empresa:putdata();
	std::cout << "Tipo de comida: " << this->tipo_comida << std::endl;
	std::cout << "Preco medio do prato: " << this->preco_medio << std::endl;
}