#include <string>

using namespace std;
 

class Empresa
{
	private:
		string nome;
		string endereco;
		string cidade;
		string estado;
		string cep;
		string telefone;
	public:
		Empresa();
		Empresa(string nome, string endereco, string cidade, 
				string estado, string cep, string telefone);
		void getdata();
		void putdata();
		~Empresa();	
};
class Restaurante : public Empresa
{
	private:
		string comida;
		string preco;
	public:
		Restaurante();
		Restaurante(string nome, string endereco, string cidade, 
					string estado, string cep, string telefone,
					string comida, string preco);
		void getdata();
		void putdata();
		~Restaurante();	
};
