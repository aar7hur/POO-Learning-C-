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
		char Cor[100];
		char Modelo[100];
	public:
		CarroPasseio();
		CarroPasseio(int NumCilindro, int Potencia, int Peso, int VelocMax, char Cor, char Modelo);
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
		Caminhao(int NumCilindro, int Potencia, int Peso, int VelocMax, char Cor, char Modelo, int Toneladas, int AlturaMax, int Comprimento);
		void getdata();
		void putdata();
		~Caminhao();	
};
