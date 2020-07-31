#include <iostream>
#include <string>
#include <sstream>

using namespace std;


//##################################################################################################
class Pessoa{
	private:
		string data, dia, mes, ano;
		int day, month, year, signo;
		void atribuiDia(string);
		void atribuiMes(string);
		void atribuiAno(string);
		
	public:
		void atribuiData(string);
		bool checkDia(void);
		bool checkMes(void);
		bool checkAno(void);
		void printExtenso();
		bool isBissexto();
		void printBissexto();
		void checkSigno();
		void printSigno();
		
};
//##################################################################################################

//##################################################################################################
void Pessoa::atribuiData(string data){
	data = data;
	int i = 0;
	string delimiter = "/";
	size_t pos = 0;
	string token;
	while((pos = data.find(delimiter)) != std::string::npos){
		token = data.substr(0, pos);
		if(i==0){
			dia = token;
		}
		else if(i==1){
			mes = token;
		}
		data.erase(0, pos + delimiter.length());
		i++;
	}
	ano = data;
	Pessoa::atribuiDia(dia);
	Pessoa::atribuiMes(mes);
	Pessoa::atribuiAno(ano);
}
//##################################################################################################

//##################################################################################################
void Pessoa::atribuiDia(string d){
	dia = d;
}
//##################################################################################################

//##################################################################################################
void Pessoa::atribuiMes(string m){
	mes = m;
}
//##################################################################################################

//##################################################################################################
void Pessoa::atribuiAno(string a){
	ano = a;
}
//##################################################################################################

//##################################################################################################
bool Pessoa::checkDia(){
	
	bool bissexto = false;
	day = 0;
	stringstream geek(dia);
	geek >> day;
	bissexto = Pessoa::isBissexto();
	
	if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){		//condição dos dias dos meses que vao ate 31
		
		if(day<1 || day>31){
			cout << "\nPor favor entre com um dia valido.";
			return false;
		}
		else{
			return true;
		}
	}
	else if(month==4 || month==6 || month==9 || month==11){		//condição dos dias dos meses que vao ate 30
		
		if(day<1 || day>30){
			cout << "\nPor favor entre com um dia valido.";
			return false;
		}
		else{
			return true;
		}
	}
	else if(month==2){		//condição dos dias de Fevereiro
		
		if(bissexto == true){
			if(day<1 || day>29){
				cout << "\nPor faor entre com um dia valido.";
				return false;
			}
			else{
				return true;
			}
		}
		else{
			if(day<1 || day>28){
				cout << "\nPor favor entre com um dia valido.";
				return false;
			}
			else{
				return true;
			}
		}
	}
}
//##################################################################################################

//##################################################################################################
bool Pessoa::checkMes(){
	
	month = 0;
	stringstream geek(mes);
	geek >> month;
	
	if(month<1 || month>12){
		cout << "\nPor favor entre com um mes valido.";
		return false;
	}
	else{
		return true;
	}
}
//##################################################################################################

//##################################################################################################
bool Pessoa::checkAno(){
	
	year = 0;
	stringstream geek(ano);
	geek >> year;
	return true;
}
//##################################################################################################

//##################################################################################################
void Pessoa::printExtenso(){
	
	char meses[13][20] = {"Start", "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	
	cout << "\n" <<day <<" de " << meses[month] << " de " << year;
}
//##################################################################################################

//##################################################################################################
bool Pessoa::isBissexto(){	
	if(year % 4 == 0){
		if(year % 100 == 0){
			if(year % 400 == 0){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}
}
//##################################################################################################

//##################################################################################################
void Pessoa::printBissexto(){
	bool bissexto = Pessoa::isBissexto();
	if(bissexto == false){
		cout << "\n" << year << " nao eh um ano bissexto";
	}
	else{
		cout << "\n" << year << " eh um ano bissexto";
	}
}
//##################################################################################################

//##################################################################################################
void Pessoa::checkSigno(){
	
	if(month==1){
		if(day<20){
			signo = 11;
		}
		else{
			signo = 0;
		}
	}
	else if(month==2){
		if(day<19){
			signo = 0;
		}
		else{
			signo = 1;
		}
	}
	else if(month==3){
		if(day<21){
			signo = 1;
		}
		else{
			signo = 2;
		}
	}
	else if(month==4){
		if(day<20){
			signo = 2;
		}
		else{
			signo = 3;
		}
	}
	else if(month==5){
		if(day<21){
			signo = 3;
		}
		else{
			signo = 4;
		}
	}
	else if(month==6){
		if(day<22){
			signo = 4;
		}
		else{
			signo = 5;
		}
	}
	else if(month==7){
		if(day<23){
			signo = 5;
		}
		else{
			signo = 6;
		}
	}
	else if(month==8){
		if(day<23){
			signo = 6;
		}
		else{
			signo = 7;
		}
	}
	else if(month==9){
		if(day<23){
			signo = 7;
		}
		else{
			signo = 8;
		}
	}
	else if(month==10){
		if(day<23){
			signo = 8;
		}
		else{
			signo = 9;
		}
	}
	else if(month==11){
		if(day<22){
			signo = 9;
		}
		else{
			signo = 10;
		}
	}
	else if(month==12){
		if(day<22){
			signo = 10;
		}
		else{
			signo = 11;
		}
	}
}
//##################################################################################################

//##################################################################################################
void Pessoa::printSigno(){
	char signos[12][20] = {"Aquario", "Peixes", "Aries", "Touro", "Gemeos", "Cancer", "Leao", "Virgem", "Libra", "Escorpiao", "Sagitario", "Capricornio"};
	
	cout << "\nSigno: " << signos[signo];
}
//##################################################################################################

//##################################################################################################
int main(){
	
	Pessoa User;
	string data;
	string dia;
	string mes;
	string ano;
	bool flagDia, flagMes, flagAno;
	int i = 0;
	
	flagDia = false;
	flagMes = false;
	flagAno = false;
	
	while(flagDia==false || flagMes==false || flagAno==false){
		cout <<"\nEntre com a data de nascimento no formato dd/mm/aaaa: ";
		getline(cin, data);
	
		User.atribuiData(data);
		flagAno = User.checkAno();
		flagMes = User.checkMes();
		flagDia = User.checkDia();

		
	}
	
	User.printExtenso();
	User.checkSigno();
	User.printSigno();
	User.printBissexto();
	
	return 0;
}
//##################################################################################################
