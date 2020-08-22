//============================================================================
// Name        : Introdu��o a heran�a simples
// Author      : Arthur Amaral
// Version     :
// Description : Introdu��o a heran�a simples C++, Ansi-style
//============================================================================

/*
 *  Crie uma classe Empresa capaz de armazenar os dados de uma empresa (nome,
 *	endere�o, cidade, estado, CEP e telefone). Inclua um construtor sem argumentos e um que
 *	receba os dados como argumentos e os inicialize. Escreva duas fun��es, uma para fazer a
 *	interface com o usu�rio da entrada de dados, getdata(), e outra para imprimir os dados,
 *	putdata().
 *	Use a classe Empresa como base para criar a classe Restaurante. Inclua o tipo de comida,
 *	o pre�o m�dio de um prato, duas fun��es construtoras, a interface de entrada de dados,
 *	getdata(), e a fun��o que imprima os dados, putdata(). Construa um programa para
 *	testar a classe Restaurante.
**/
#include <string>
#include <iostream>
#include "Classe.h"
#include <new>
#include <cstdlib>
#include "Classe.cpp"

int testa_construtor_empresa(void);
int testa_getdata_empresa(void);
int testa_classe_restaurante(void);

std::string *dados =  new(std::nothrow) std::string[8];


int main() {
	
	if (!dados) {            
    	std::cout << "Falha em alocar a mem�ria!\n";
    	exit(EXIT_FAILURE);
  	};

	// Atribui valor aos dados de teste
	dados[0] = "UFPR";
	dados[1] = "Curitiba";
	dados[2] = "Parana";
	dados[3] = "81940-040";
	dados[4] = "3265-1216";
	dados[5] = "Comida Italiana";
	dados[6] = "25,90";

	std::cout << "*****************************************\n";
	std::cout << "Testando passando parametros para o construtor!\n";
	testa_construtor_empresa();
	std::cout << "\n*****************************************\n";
	std::cout << "Testando chamando a funcao get data \n";
	testa_getdata_empresa();
	std::cout << "\n*****************************************\n";
	return 0;
}


int testa_getdata_empresa(void)
{
	
	/** Testa a classe empresa recebendo os dados pelo
	**	metodo getdata.
	**/
	Empresa* obj = new(std::nothrow) Empresa(); 
	if (!obj) {            
    	std::cout << "Falha em alocar a mem�ria!\n";
    	exit(EXIT_FAILURE);
  	}	 			
  	
	obj->getdata();						
	obj->putdata();							
	obj->~Empresa();
	delete obj;
	
	return 0;
}

int testa_construtor_empresa(void)
{
	/** Testa a classe empresa passando parametros no construtor **/
	  	 	
	Empresa* obj = new Empresa(dados);
	if (!obj) {            
    	std::cout << "Falha em alocar a mem�ria!\n";
    	exit(EXIT_FAILURE);
  	}	 	
	obj->putdata();
	obj->~Empresa();		
	delete obj;	
}
	

int testa_construtor_restaurante(void)
{
	/** Testa a classe empresa passando parametros no construtor **/
	
	Empresa* obj = new Restaurante(dados);
	if (!obj) {            
    	std::cout << "Falha em alocar a mem�ria!\n";
    	exit(EXIT_FAILURE);
  	}	 	
	obj->putdata();
	obj->~Empresa();		
	delete obj;		
}


