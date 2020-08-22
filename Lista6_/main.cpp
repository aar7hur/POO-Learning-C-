//============================================================================
// Name        : Introdução a herança simples
// Author      : Arthur Amaral
// Version     :
// Description : Introdução a herança simples C++, Ansi-style
//============================================================================

/*
 *  Crie uma classe Empresa capaz de armazenar os dados de uma empresa (nome,
 *	endereço, cidade, estado, CEP e telefone). Inclua um construtor sem argumentos e um que
 *	receba os dados como argumentos e os inicialize. Escreva duas funções, uma para fazer a
 *	interface com o usuário da entrada de dados, getdata(), e outra para imprimir os dados,
 *	putdata().
 *	Use a classe Empresa como base para criar a classe Restaurante. Inclua o tipo de comida,
 *	o preço médio de um prato, duas funções construtoras, a interface de entrada de dados,
 *	getdata(), e a função que imprima os dados, putdata(). Construa um programa para
 *	testar a classe Restaurante.
**/
#include <string>
#include <iostream>
#include "Classe.h"
#include <new>
#include <cstdlib>

int testa_construtor_empresa(void);
int testa_getdata_empresa(void);
int testa_classe_restaurante(void);

int main() {
	
	testa_construtor_empresa();
	testa_getdata_empresa();
	return 0;
}


int testa_construtor_empresa(void)
{
	
	/** Testa a classe empresa recebendo os dados pelo
	**	método getdata.
	**/
	Empresa* obj = new(std::nothrow) Empresa(); 
	if (!obj) {            
    	std::cout << "Falha em alocar a memória!\n";
    	exit(EXIT_FAILURE);
  	}	 			
  	
	obj->getdata();						
	obj->putdata();							
	obj->~Empresa();
	delete obj;
	
	return 0;
}

int testa_getdata_empresa(void)
{
	/** Testa a classe empresa passando parametros no construtor **/
	std::string *dados =  new(std::nothrow) std::string[6];
	if (!dados) {            
    	std::cout << "Falha em alocar a memória!\n";
    	exit(EXIT_FAILURE);
  	};
	  	 	
	dados[0] = "UFPR";
	dados[1] = "Curitiba";
	dados[2] = "Paraná";
	dados[3] = "81940-040";
	dados[4] = "3265-1216";
	
	Empresa* obj2 = new Empresa(dados);
	if (!obj2) {            
    	std::cout << "Falha em alocar a memória!\n";
    	exit(EXIT_FAILURE);
  	}	 	
	obj2->putdata();
	obj2->~Empresa();		
	delete obj2;	
}
	


int testa_classe_restaurante(void)
{
	
}


