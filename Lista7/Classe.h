#include <string>

using namespace std;

class Motor
{
	private:
		int NumCilindro;
		int Potencia;
	public:
		Motor();
		Motor(int NumCilindro, int Potencia);
		void getdata();
		void putdata();
		~Motor();	
};
class Veiculo
{
	private:
		int Peso;
		int VelocMax;
	public:
		Veiculo();
		Veiculo(int Peso, int VelocMax);
		void getdata();
		void putdata();
		~Veiculo();
};
class CarroPasseio:public Motor, public Veiculo
{
	private:
		string Cor;
		string Modelo;
	public:
		CarroPasseio();
		CarroPasseio(int NumCilindro, int Potencia, int Peso, 
						int VelocMax, string Cor, string Modelo);
		void getdata();
		void putdata();
		~CarroPasseio();
};
class Caminhao:public Motor, public Veiculo
{
	private:
		int Toneladas;
		int AlturaMax;
		int Comprimento;
	public:
		Caminhao();
		Caminhao(int NumCilindro, int Potencia, int Peso, 
					int VelocMax,int Toneladas, int AlturaMax, int Comprimento);
		void getdata();
		void putdata();
		~Caminhao();	
};
