#include <iostream>
#include <math.h>
#include <string.h>
#include "complexo.h"

#define PI 3.14159265359

Complexo::Complexo(double x, double y, double i, double j)
{
	this->x = x;
	this->y = y;
	this->i = i;
	this->j = j;	
}
void Complexo::numero(void)
{
	double z1, z2, fi1, fi2;
	
	z1 = sqrt(pow(x,2) + pow(y,2));
	z2 = sqrt(pow(i,2) + pow(j,2));
	fi1 = atan((y/x)) * 180 / PI;
	fi2 = atan((j/i)) * 180 / PI;
	
	std::cout << "Numero [1]: ";
	std::cout << "\n";
	std::cout << "Numero Complexo Retangular [1]: " << x << " + " << "i*" << y;
	std::cout << "\n";
	std::cout << "Numero Complexo Polar [1]: " << z1 << "|" << fi1;
	std::cout << "\n";
	std::cout << "\n";
	
	std::cout << "Numero [2]: ";
	std::cout << "\n";
	std::cout << "Numero Complexo Retangular [2]: " << i << " + " << "i*" << j;
	std::cout << "\n";
	std::cout << "Numero Complexo Polar [2]: " << z2 << "|" << fi2;
	std::cout << "\n";
	std::cout << "\n"; 
}
void Complexo::exibeSoma(void)
{
	double somaX = x + i;
	double somaY = y + j;
	double z, fi;
	
	z = sqrt(pow(somaX,2) + pow(somaY,2));
	fi = atan((somaY/somaX)) * 180 / PI;
	
	std::cout << "Numero Soma: ";
	std::cout << "\n";	
	std::cout << "Numero Complexo Retangular: " << somaX << " + " << "i*" << somaY;
	std::cout << "\n";
	std::cout << "Numero Complexo Polar: " << z << "|" << fi;
	std::cout << "\n";
	std::cout << "\n";
}
void Complexo::exibeSubtracao(void)
{
	double subtracaoX = x - i;
	double subtracaoY = y - j;
	double z, theta, fi;
	
	z = sqrt(pow(subtracaoX,2) + pow(subtracaoY,2));
	fi = atan((subtracaoY/subtracaoX)) * 180 / PI;
	
	std::cout << "Numero Subtracao: ";
	std::cout << "\n";
	std::cout << "Numero Complexo Retangular: " << subtracaoX << " + " << "i*" << subtracaoY;
	std::cout << "\n";
	std::cout << "Numero Complexo Polar: " << z << "|" << fi;
	std::cout << "\n";
	std::cout << "\n";
}
void Complexo::exibeMultiplicacao(void)
{
	double z1, z2, fi1, fi2;
	double multiplicacaoX, multiplicacaoY, retangularX, retangularY;
	
	z1 = sqrt(pow(x,2) + pow(y,2));
	z2 = sqrt(pow(i,2) + pow(j,2));
	fi1 = atan((y/x));
	fi2 = atan((j/i)); 
	
	multiplicacaoX = fabs(z1)*fabs(z2);
	multiplicacaoY = fi1+fi2;
	
	retangularX = multiplicacaoX * cos(multiplicacaoY);
	retangularY = multiplicacaoX * sin(multiplicacaoY);
	
	std::cout << "Numero Multiplicacao: ";
	std::cout << "\n";
	std::cout << "Numero Complexo Retangular: " << retangularX << " + " << "i*" << retangularY;
	std::cout << "\n";
	std::cout << "Numero Complexo Polar: " << multiplicacaoX << "|" << multiplicacaoY * (180/PI);
	std::cout << "\n";
	std::cout << "\n";
}
void Complexo::exibeDivisao(void)
{
	double z1, z2, theta1, theta2, fi1, fi2;
	double divisaoX, divisaoY, retangularX, retangularY;
	
	z1 = sqrt(pow(x,2) + pow(y,2));
	z2 = sqrt(pow(i,2) + pow(j,2));
	theta1 = y/x;
	theta2 = j/i;
	fi1 = atan(theta1);
	fi2 = atan(theta2);
	
	divisaoX = fabs(z1)/fabs(z2);
	divisaoY = fi1-fi2;
	
	retangularX = divisaoX * cos(divisaoY);
	retangularY = divisaoX * sin(divisaoY);
	
	std::cout << "Numero Divisao: ";
	std::cout << "\n";
	std::cout << "Numero Complexo Retangular: " << retangularX << " + " << "i*" << retangularY;
	std::cout << "\n";
	std::cout << "Numero Complexo Polar: " << divisaoX << "|" << divisaoY * (180/PI);
	std::cout << "\n";
	std::cout << "\n";	
}
Complexo::~Complexo()
{
	std::cout << "Objeto Destruido\n";
}

