#include "decision.h"


//@parede comentar --> funcao para escrever nas variaveis com os dados de excel @eder @godoy
void Decision::populateData(){
	/*********************************************************************************************************************************************************************************************************************************************
	Parede eu e o Éderu criamos uma classezinha pra armazenar os dados do CSV. Ai só pra você já saber, ela funciona assim:

	Chega pra você uma variavel da classe Tabela. Ai você pega e chama ela tipo assim:

	Tabela["Close"](array)
	
	No lugar do Close ali você coloca a coluna que vai precisar, pode ser Min, Máx, Close, etc. No lugar da array ali 
	você coloca um ponteiro pro tipo que você vai querer. Ele aceita string, int, float e double, tanto faz. A função retorna o tamanho da array que é criada, então se quiser jogar um If pra ver se está tudo certo.

	double *array; size_t arraySize;
	arraySize = Tabela["Close"](array)

	string *array; size_t arraySize;
	arraySize = Tabela["Close"](array)

	Os dois são validos, só tratar do jeito que você acha melhor, então se você decidir mudar de um tipo pra outro tá suave. Ai o retorno da função é o tamanho da array e da pra por um parametro opcional pra limitar a array se você quiser. 
	Tipo: 

	Tabela["Close"](array, 20) => vai limitar o tamanho da array a no máximo 20

	**********************************************************************************************************************************************************************************************************************************************/
	
	
}

Decision::Decision(){}
Decision::~Decision(){}
