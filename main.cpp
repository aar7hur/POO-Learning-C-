#include <iostream>
#include <string>
#include "Classe.h"

void head (void);

int main ()
{	
	head();
	Restaurante rest;
	rest.getdata();
	rest.putdata();
}
void head (void)
{
	std::cout << "TE353 - Programacao Orientada a Objetos  *\n";
	std::cout << "Profesorra: Giselle Lopes Ferrari        *\n";
	std::cout << "Nome: Vinicius Tertulino Parede          *\n";
	std::cout << "GRR: 20172137                            *\n";
	std::cout << "******************************************\n";
	std::cout << "         Exercicio 01 --> Aula 06";
	std::cout << "\n";
	std::cout << "\n";
	return;
}
