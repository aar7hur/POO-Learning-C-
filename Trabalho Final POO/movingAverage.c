#include <iostream>
#include <cstdlib>
#include <ctime>

int movingAverage(int *, int);																									//Protótipo da função Média Móvel Simples

using namespace std;

int main(int argc, char** argv){

	int seed = time(0);
	int priceCloseWeek[200];
	int period = 9;																																//Variável Período cuja sua função é estabelecer o período da média móvel --> Valor deve ser setado pelo programada como 9 e 20
	int aux;																																			//Tendência será feita a partir do cruzamento entre as médias de 9 e 20 períodos

	srand(seed);
	for(int i = 0; i < 200; i++){																									//Laço de Repetição exclusivo para obter 200 dados randomicos, no código o vetor priceCloseWeek[] deverá ser alimentado
		priceCloseWeek[i] = rand()%50;																							//pelos dados obtidos de uma tabela do excel (Preço de Fechamento Semanal)
	}
	for(aux = period-1; aux < 200; aux++){
		movingAverage(&priceCloseWeek[aux], period);
	}

	return 0;
}
/*******************************************************************************
 *	Função: movingAverage
 *	----------------------
 * 	Função dedicada ao cálculo da média móvel dos dados.
 *	recebe: vetor de Preços de Fechamento Semanal e o Período p/ cálculo 
 *	retorna: inteiro com o Preço da Média Móvel
 OBS: Essa função será chamada duas vezes pois o algoritmo exige 2 médias móveis
 com períodos de 9 e 20.
 ******************************************************************************/
int movingAverage(int *x, int t){

	int aux, sum;
	sum = 0;
	for(aux = t; aux > 0; aux--){
		sum += *x;
		x--;
	}
	return sum/t;
}
