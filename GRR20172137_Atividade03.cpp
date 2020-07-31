#include <iostream>

/*******************************/
void cabecalho(void);
void leituraDados(void);
/*******************************/

class dataNascimento
{
	private:
		int dia, mes, ano;
	public:
		bool validacaoDados(int d, int m, int a, bool b)
		{
			dia = d; mes = m; ano = a;
			
			if (dia > 31 || dia < 1)
			{
				if (dia > 31)
				{
					std::cout << "Valor do dia de nascimento invalido: " <<dia <<" > " <<"31";
					std::cout <<"\n";
					return false;	
				}
				else
				{
					std::cout << "Valor do dia de nascimento invalido: " <<dia <<" < " <<"1";
					std::cout <<"\n";
					return false;	
				}
			}
			else if (mes > 12 || mes < 1)
			{
				if (mes > 12)
				{
					std::cout << "Valor do mes de nascimento invalido: " <<mes <<" > " <<"12";
					std::cout <<"\n";
					return false;	
				}
				else
				{
					std::cout << "Valor do mes de nascimento invalido: " <<mes <<" < " <<"1";
					std::cout <<"\n";
					return false;	
				}
			}
			else if (ano > 2020 || ano < 1900)
			{
				if (ano > 2020)
				{
					std::cout << "Valor do mes de nascimento invalido: " <<ano <<" > " <<"2020";
					std::cout <<"\n";
					return false;	
				}
				else
				{
					std::cout << "Valor do mes de nascimento invalido: " <<ano <<" < " <<"1900";
					std::cout <<"\n";
					return false;	
				}
			}
			else if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
			{
				std::cout << "Valor do dia de nascimento invalido " << dia << " > " << "30";
				std::cout <<"\n";
				return false;
			}
			else if (dia > 28 && b == false && mes == 2)
			{
				std::cout << "Valor do dia de nascimento invalido " << dia << " > " << "28";
				std::cout << "\n";
			}
			else if (dia > 29 && b == true && mes == 2)
			{
				std::cout << "Valor do dia de nascimento invalido " << dia << " > " << "29";
				std::cout <<"\n";
			}
			else
			{
				return true;
			}
		}
		bool bissexto (int a)
		{
			ano = a;
			
			if (ano % 4 == 0)
			{
				if (ano % 100 != 0)
				{
					return true;
				}
			}
			else if (ano % 4 != 0)
			{
				if (ano % 400 != 0)
				{
					return false;
				}
			}
		}
		int signo (int d, int m, int a, bool b)
		{
			dia = d; mes = m; ano = a;
			
			if((dia >= 21 && mes == 1) || (dia <= 18) && (mes == 2))
			{
				return 0;
			}
			else if ((dia >= 19 && mes == 2) || (dia <= 20) && (mes == 3))
			{
				return 1;	
			}
			else if ((dia >= 21 && mes == 3) || (dia <= 20) && (mes == 4))
			{
				return 2;	
			}
			else if ((dia >= 21 && mes == 4) || (dia <= 20) && (mes == 5))
			{
				return 3;	
			}
			else if ((dia >= 21 && mes == 5) || (dia <= 20) && (mes == 6))
			{
				return 4;	
			}
			else if ((dia >= 21 && mes == 6) || (dia <= 22) && (mes == 7))
			{
				return 5;	
			}
			else if ((dia >= 23 && mes == 7) || (dia <= 22) && (mes == 8))
			{
				return 6;	
			}
			else if ((dia >= 23 && mes == 8) || (dia <= 22) && (mes == 9))
			{
				return 7;	
			}
			else if ((dia >= 23 && mes == 9) || (dia <= 22) && (mes == 10))
			{
				return 8;	
			}
			else if ((dia >= 23 && mes == 10) || (dia <= 21) && (mes == 11))
			{
				return 9;	
			}
			else if ((dia >= 22 && mes == 11) || (dia <= 21) && (mes == 12))
			{
				return 10;	
			}
			else if ((dia >= 22 && mes == 12) || (dia <= 20) && (mes == 1))
			{
				return 11;	
			}	
		}
		 
		void imprimeSaida(bool b, int s)
		{
			char vetorMes[12][10] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
			char vetorSigno[12][12] = {"Aquario", "Peixes", "Aries", "Touro", "Gemeos", "Cancer", "Leao", "Virgem", "Libra", "Escorpiao", "Sagitario", "Capricornio"};
			if (b == true)
			{
				std::cout <<"Data de nascimento: " <<dia <<" de " <<vetorMes[mes-1] << " de " <<ano << "\n";
				std::cout <<"Signo: " << vetorSigno[s] << "\n";
				std::cout << "Ano bissexto\n";
			}
			else
			{
				std::cout <<"Data de nascimento: " <<dia <<" de " <<vetorMes[mes-1] << " de " <<ano << "\n";
				std::cout <<"Signo: " << vetorSigno[s] << "\n";
				std::cout << "Nao e bissexto\n";	
			}
		}
};
int main(void)
{	
	cabecalho();
	leituraDados();
	return 0;
}
void leituraDados(void)
{
	dataNascimento entradaUsuario;
	int dia, mes, ano;
	int signo;
	bool x;
	bool bissexto;
	
	std::cout << "Dia do nascimento: ";
	std::cin >> dia;
	std::cout << "Mes do nascimento: ";
	std::cin >> mes;
	std::cout << "Ano do nascimento: ";
	std::cin >> ano;
	std::cout << "\n"; 	
		
	bissexto = entradaUsuario.bissexto(ano);
	x = entradaUsuario.validacaoDados(dia, mes, ano, bissexto);
		
	if(x == true)
	{
		signo = entradaUsuario.signo(dia, mes, ano, bissexto); 
		entradaUsuario.imprimeSaida(bissexto, signo);	
	}
	else
	{
		exit(0);
	}
	
	return;
	
}
void cabecalho(void)
{
	std::cout << "TE353 - Programacao Orientada a Objetos  *\n";
	std::cout << "Profesorra: Giselle Lopes Ferrari        *\n";
	std::cout << "Nome: Vinicius Tertulino Parede          *\n";
	std::cout << "GRR: 20172137                            *\n";
	std::cout << "******************************************\n";
	std::cout << "\n";
	std::cout << "\n";
	return;	
}
