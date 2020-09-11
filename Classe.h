class Empresa
{
	private:
		char nome[100];
		char endereco[100];
		char cidade[100];
		char estado[100];
		int cep;
		int telefone;
	public:
		Empresa();
		Empresa(char nome, char endereco, char cidade, char estado, int cep, int telefone);
		void getdata();
		void putdata();
		~Empresa();	
};
class Restaurante : public Empresa
{
	private:
		char comida[100];
		int preco;
	public:
		Restaurante();
		Restaurante(char comida, int preco);
		void getdata();
		void putdata();
		~Restaurante();	
};
