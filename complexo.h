#include <iostream>

class Complexo
{
	private:
		double x;
		double y;
		double i;
		double j;
	public:
		Complexo(double x, double y, double i, double j);
		~Complexo();
		void numero(void);
		void exibeSoma(void);
		void exibeSubtracao(void);
		void exibeMultiplicacao(void);
		void exibeDivisao(void);
		
};
