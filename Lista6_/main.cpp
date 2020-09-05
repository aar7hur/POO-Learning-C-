//============================================================================
// Name        : Introdu??o a heran?a simples
// Author      : Arthur Amaral
// Version     :
// Description : Introdu??o a heran?a simples C++, Ansi-style
//============================================================================

/*
 *  Crie uma classe Empresa capaz de armazenar os dados de uma empresa (nome,
 *	endere?o, cidade, estado, CEP e telefone). Inclua um construtor sem argumentos e um que
 *	receba os dados como argumentos e os inicialize. Escreva duas fun??es, uma para fazer a
 *	interface com o usu?rio da entrada de dados, getdata(), e outra para imprimir os dados,
 *	putdata().
 *	Use a classe Empresa como base para criar a classe Restaurante. Inclua o tipo de comida,
 *	o pre?o m?dio de um prato, duas fun??es construtoras, a interface de entrada de dados,
 *	getdata(), e a fun??o que imprima os dados, putdata(). Construa um programa para
 *	testar a classe Restaurante.
**/
#include <string>
#include <iostream>
#include "Classe.h"

using namespace std;

int main() {
	
	// Atribui valor aos dados de teste
	string nome = "UFPR";
	string endereco = "R. Alberto vilas, 12";
	string cidade = "Curitiba";
	string estado = "Paraná";
	string cep = "81940-040";
    string telefone = "3265-1216";
	string tipo_comida = "comida italiana";
	string preco = "25,90";

	std::cout << "*****************************************\n";
	std::cout << "Testando classe Restaurante passando parametros para o construtor!\n\n";
	
	Restaurante test_construtor(nome, endereco, cidade,
								estado, cep, telefone,
								tipo_comida, preco);
	test_construtor.putdata();
	
	Restaurante test_getData;
	std::cout << "\n*****************************************\n";
	std::cout << "Testando classe Restaurante chamando a funcao get data!\n\n";
	test_getData.getdata();
	test_getData.putdata();
	std::cout << "\n*****************************************\n";

}

