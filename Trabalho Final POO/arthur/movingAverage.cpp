#include "movingAverage.h"

/*******************************************************************************
 *	Fun��o: movingAverage
 *	----------------------
 * 	Fun��o dedicada ao c�lculo da m�dia m�vel dos dados.
 *	recebe: vetor de Pre�os de Fechamento Semanal e o Per�odo p/ c�lculo 
 *	retorna: inteiro com o Pre�o da M�dia M�vel
 OBS: Essa fun��o ser� chamada duas vezes pois o algoritmo exige 2 m�dias m�veis
 com per�odos de 20 e 50.
 ******************************************************************************/
void MovingAverage::setmovingAverage(float *priceCloseWeek, int period){

	float aux, sum;
	sum = 0;
	for(aux = period; aux > 0; aux--){
		sum += *priceCloseWeek;
		priceCloseWeek--;
	}
	this->average = (sum)/period;
}

float MovingAverage::getAverage(void){
	return this->average;
}

MovingAverage::MovingAverage(float *priceCloseWeek, int period){}
MovingAverage::~MovingAverage(){}
