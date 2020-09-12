#include "decision.h"


//@parede comentar --> funcao para escrever nas variaveis com os dados de excel @eder @godoy
void Decision::populateData(){
	/*********************************************************************************************************************************************************************************************************************************************
	Parede eu e o �deru criamos uma classezinha pra armazenar os dados do CSV. Ai s� pra voc� j� saber, ela funciona assim:

	Chega pra voc� uma variavel da classe Tabela. Ai voc� pega e chama ela tipo assim:

	Tabela["Close"](array)
	
	No lugar do Close ali voc� coloca a coluna que vai precisar, pode ser Min, M�x, Close, etc. No lugar da array ali 
	voc� coloca um ponteiro pro tipo que voc� vai querer. Ele aceita string, int, float e double, tanto faz. A fun��o retorna o tamanho da array que � criada, ent�o se quiser jogar um If pra ver se est� tudo certo.

	double *array; size_t arraySize;
	arraySize = Tabela["Close"](array)

	string *array; size_t arraySize;
	arraySize = Tabela["Close"](array)

	Os dois s�o validos, s� tratar do jeito que voc� acha melhor, ent�o se voc� decidir mudar de um tipo pra outro t� suave. Ai o retorno da fun��o � o tamanho da array e da pra por um parametro opcional pra limitar a array se voc� quiser. 
	Tipo: 

	Tabela["Close"](array, 20) => vai limitar o tamanho da array a no m�ximo 20

	**********************************************************************************************************************************************************************************************************************************************/
	
	
}

Decision::Decision(){}
Decision::~Decision(){}
