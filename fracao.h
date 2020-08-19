#include <iostream>

class fracao
{
	private:
		int numerador;
		int denominador;	
	public:
		fracao();
		fracao(int n, int d);
		void imprime();
		fracao operator + (fracao X);
		fracao operator - (fracao X);
		fracao operator * (fracao X);
		fracao operator / (fracao X);
		~fracao();
};
