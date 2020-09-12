#include <iostream>
#include <ctime>
#include <cstdlib>

bool decision(float *, float *, float *, float *, float *, float *, float *);							//Funcao de Decisao de COMPRA ou VENDA
float managementRisk(float *, float *, bool);															//Funcao de Gerenciamento de Risco

using namespace std;

int main(int argc, char** argv){
/********************************************************************************************** 
*	Definicao de Dados e Fun��es para funcioanento da Decis�o e Gerenciamento de Risco
	
*	Dados: Fechamento do Dia, Preco Fechamento da Semana, M�xima do Dia, M�nima do Dia
* 	Funcoes: M�dia M�vel de 20 Per�odos, M�dia M�vel de 50 Per�odos e Estoc�stico de 8 per�odos
* 	OBS: Dados devem ser enviados em formato de arrays
* 		 Fun��es devem retornar n�meros inteiros
*	Exemplo: priceCloseWeek[] = array de dados do pre�o de fechamento semanal 						@eder @godoy
*			 movingAverage_20[] = movingAverage(array de precos semanal, periodo da m�dia)			@jefferson
			 movingAverage_20[] = movingAverage(closeWeek, 20)
**********************************************************************************************/
	float priceCloseWeek[200], priceCloseDaily[100], priceHighDaily[200], priceLowDaily[200];
	float movingAverage_20[200], movingAverage_50[200], stochastic_8[200];
/*********************************************************************************************/
	int seed = time(0);
		
	srand(seed);
/**********************************************************************************************
*	Trecho do c�digo focado apenas p/ gerar n�meros ale�torios para as vari�veis, fazendo com 
*	que determine-se a a��o que o algoritmo deve realizar e o gerenciamento de risco 
**********************************************************************************************/
	for(int i =0; i < 200; i++){
		priceCloseWeek[i] = rand()%30 + 1;
		priceCloseDaily[i] = rand()%30 + 1;
	volta:
		priceHighDaily[i] = rand()%30 + 1;
		priceLowDaily[i] = rand()%30 + 1;
		if(priceCloseDaily[i] > priceHighDaily[i]){
			goto volta;
		}
		if(priceCloseDaily[i] < priceLowDaily[i]){
			goto volta;
		}
		else{
			movingAverage_20[i] = rand()%30 + 1;
			movingAverage_50[i] = rand()%30 + 1;
			stochastic_8[i] = rand()%100 + 1;	
		}
	}
/**********************************************************************************************/	
	decision(priceCloseWeek, priceCloseDaily, priceHighDaily, priceLowDaily, movingAverage_20, movingAverage_50, stochastic_8);		//Chamada da funcao de Decisao
	return 0;
}
/**********************************************************************************************/
bool decision(float *closeWeek, float *closeDaily, float *highDaily, float *lowDaily, float *average_20, float *average_50, float *stochastic_8){
	for(int i = 0; i < 200; i ++){
		if((closeWeek[i] >= average_20[i]) && (average_20[i] >= average_50[i]) && (stochastic_8[i] <= 20)){
			bool action = true;
			cout << "COMPRA ! " << "Preco Semanal: " << closeWeek[i] << " " << "Preco Diario: " << closeDaily[i] << " " << "Media (20): " << average_20[i] << " " << "Media (50): " << average_50[i] << " " << "Estocastico (8): " << stochastic_8[i] << endl;
			cout << "Quantidade de acoes: " << managementRisk(&highDaily[i], &lowDaily[i], action) << endl;		//SAIDA DE DADOS PARA O USUARIO @arthur
			
			return true;	//DECISAO COMPRA ! --> a funcao decision() retorna 'true' p/ a decis�o de compra
			
		}
		else if((closeWeek[i] < average_20[i]) && (average_20[i] < average_50[i]) && (stochastic_8[i] > 80)){
			bool action = false;
			cout << "VENDA  ! " << "Preco Semanal: " << closeWeek[i] << " " << "Preco Diario: " << closeDaily[i] << " " << "Media (20): " << average_20[i] << " " << "Media (50): " << average_50[i] << " " << "Estocastico (8): " << stochastic_8[i] << endl;
			cout << "Quantidade de acoes: " << managementRisk(&highDaily[i], &lowDaily[i], action) << endl;		//SAIDA DE DADOS P/ USUARIO @arthur
	
			return false;	//DECISAO VENDA ! --> a funcao decision() retorna 'false' p/ a decis�o de venda
			//OBS: Pode-se ser que ao compilar esse programa e o mesmo retornar a decis�o de venda
			// 	   a compra Take fique negativa por conta dos dados aleatorios gerados, isso n�o ir�
			//	   acontecer na pr�tica pois a discrep�ncia de dados do mercado financeiro n�o segue
			//     o mesmo m�dulo da aleatoriedade gerada no trecho de dados.	
		}
		else{
			cout << "NADA   ! " << "Preco Semanal: " << closeWeek[i] << " " << "Preco Diario: " << closeDaily[i] << " " << "Media (20): " << average_20[i] << " " << "Media (50): " << average_50[i] << " " << "Estocastico (8): " << stochastic_8[i] << endl;
			
			//return 0;			//DECISAO DE NAO REALIZAR NENHUMA ACAO !
			//Caso queira rodar o c�digo s/ ficar compilando toda vez apenas comentar o return
			//EXEMPLO: //return 0;
		}
	}
}
/**********************************************************************************************/
float managementRisk(float *highDaily, float *lowDaily, bool action){
/***********************************************************************************************
	Vari�veis p/ realiazar o controle de Risco
	riskTrade = Risco financeiro do Trade
	stopLoss = Momento de Sa�da Negativo do Trade
	trigger = Entrada do Trade
	target = Relacao Risco/Retorno do Trade (Alvo do Trade) --> Momento de Sa�da Positiva do Trade
	capital = Input do Usu�rio --> Montante que ele deseja investir @arthur
	qtdStocks = Quantidade de A��es necess�ria p/ Trade
***********************************************************************************************/
	float stopLoss, trigger, riskTrade;
	int target;
	float capital = 100000;
	int qtdStocks = 1;
/**********************************************************************************************/	
	if(action == true){
		stopLoss = *lowDaily;
		trigger = *highDaily;
	
		target = ((trigger - stopLoss) * 3) + trigger;
		while(riskTrade < (0.01*capital)){
			riskTrade = (trigger - stopLoss) * qtdStocks;
			qtdStocks++;	
		}
		cout << endl << "Compra: " << trigger << endl;	//output p/usu�rio @arthur
		cout << "Venda Stop: " << stopLoss << endl;		//output p/usu�rio @arthur
		cout << "Venda Take: " << target << endl;		//output p/usu�rio @arthur
		return qtdStocks;	
	}
	else if (action == false){
		stopLoss = *highDaily;
		trigger = *lowDaily;
	
		target = trigger - ((stopLoss - trigger) * 3);
		while(riskTrade < (0.01*capital)){
			riskTrade = (stopLoss - trigger) * qtdStocks;
			qtdStocks++;	
		}
		cout << endl << "Venda: " << trigger << endl;	//output p/usu�rio @arthur
		cout << "Compra Stop: " << stopLoss << endl;	//output p/usu�rio @arthur
		cout << "Compra Take: " << target << endl;		//output p/usu�rio @arthur	
		return qtdStocks;								//RETORNA FUNCAO -> QUANTIDADE DE ACOES output @arhtur
	}
}
/**********************************************************************************************/
