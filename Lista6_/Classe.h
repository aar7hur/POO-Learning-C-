/*
 * Classe.h
 *
 *  Created on: 21 de ago de 2020
 *      Author: amaralA
 *      nome,
 *	endere�o, cidade, estado, CEP e telefone)
 */


#ifndef CLASSE_H_
#define CLASSE_H_

#include <string>
#include <iostream>

class Empresa{
	protected:
		std::string nome;
		std::string cidade;
		std::string estado;
		std::string cep;
		std::string telefone;
	public:
		Empresa();
		Empresa(std::string *dados);
		virtual ~Empresa();
		virtual void getdata(void);
		virtual void putdata(void);
};

class Restaurante : public Empresa
{
	protected:
		std::string preco_medio;
		std::string tipo_comida;
	public:
		Restaurante();
		Restaurante(std::string *dados);
		void getdata(void);
		void putdata(void);
};


#endif /* CLASSE_H_ */

