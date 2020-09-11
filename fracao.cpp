#include <iostream>
#include "fracao.h"

int mdc (int i, int j);
int mmc (int i, int j);

fracao::fracao()
{
	std::cout << "Numerador: ";
	std::cin >> numerador;
	std::cout << "Denominador: ";
	std::cin >> denominador;
}
fracao::fracao(int n, int d)
{
	numerador = n;
	denominador = d;
}
void fracao::imprime()
{
	float resultado = (float)numerador/denominador;
	
	std::cout << "Resultado: " << numerador << "/" << denominador << "\n";
	std::cout << "Resultado: " << resultado;
	return;
}
fracao fracao::operator + (fracao X)
{
	fracao resultado (0,0);
	
	resultado.denominador = mmc(denominador, X.denominador);
	resultado.numerador = (((resultado.denominador/denominador) * numerador) + ((resultado.denominador/X.denominador) * X.numerador));
	return resultado; 	
}
fracao fracao::operator - (fracao X)
{
	fracao resultado (0,0);
	
	resultado.denominador = mmc(denominador, X.denominador);
	resultado.numerador = (((resultado.denominador/denominador) * numerador) - ((resultado.denominador/X.denominador) * X.numerador));
	return resultado; 	
}  
fracao fracao::operator * (fracao X)
{
	fracao resultado(0,0);
	
	resultado.numerador = numerador * X.numerador;
	resultado.denominador = denominador * X.denominador;
	return resultado;
}
fracao fracao::operator / (fracao X)
{
	fracao resultado (0,0);
	
	resultado.numerador = numerador * X.denominador;
	resultado.denominador = denominador * X.numerador;
	return resultado;
}
int mdc (int i, int j)
{
	while(j != 0)
	{
		int resto = i % j;
		i = j;
		j = resto;
	}
	return i;
}
int mmc (int i, int j)
{
	return i * (j / mdc(i, j));
}
fracao::~fracao(){}
