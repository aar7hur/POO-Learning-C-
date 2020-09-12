#include "../include/decision.h"
#include "../include/readcsv.h"
#include "../include/movingAverage.h"
#include <string>

/*******************************************************************************
 *	Função: populateData
 *	----------------------
 * 	Função dedicada popular as structs com os dados necessários
 *	recebe: nada
 *	retorna: nada. Apenas popula os atributos da classe
 * OBS: Essa função será chamada uma vez apenas
 ******************************************************************************/
void Decision::populateData(std::string ativo){

    try{

        this->populateAverage(ativo);
        this->populateCloseWeek(ativo);
        this->populateStochastic(ativo);
    }
    catch(...)
    {
        std::cout << "Erro! Não existe esse ativo no sistema";
        exit(-1);
    }
}
void Decision::populateAverage(std::string ativo){

    
    Tabela meuAtivo(ativo, "d");
    float *array;
    meuAtivo["Close"] >> array;
    std::cout << ativo;

    this->movingAverage.setmovingAverage(array, 20);
    this->decisionData.average_20 = this->movingAverage.getAverage();

    this->movingAverage.setmovingAverage(array, 50);
    this->decisionData.average_50 = this->movingAverage.getAverage();
    std::cout << "ok pupulate average";

}
void Decision::populateCloseWeek(std::string ativo)
{
    Tabela meuAtivoClosed(ativo, "w");
    float *arrayClose;
    meuAtivoClosed["Close"] >> arrayClose; //ver quantas posições retorna no array
    this->decisionData.closeWeek = arrayClose[0];

}

void Decision::populateStochastic(std::string ativo)
{
    Tabela meuAtivoSto(ativo, "d");
    float *arraySto;

    meuAtivoSto["Close"] >> arraySto; //ver quantas posições retorna no array
    this->stochastic.setPrice(arraySto);
    this->stochastic.getHighDailyPrice();
    this->stochastic.getLowDailyPrice();
    this->stochastic.getKcurve();
    this->stochastic.averageKcurve();
    this->decisionData.stochastic_8 = this->stochastic.getResult();
    this->decisionData.highDaily = this->stochastic.getHighDailyPrice();
    this->decisionData.lowDaily = this->stochastic.getLowDailyPrice();
}

/*******************************************************************************
 *	Função: doDecision
 *	----------------------
 * 	Função dedicada a fazer a decisão de compra e de venda
 *	recebe: nada
 *	retorna: nada. apensa seta o booleano "isPurchaseAction
 * OBS: Essa função será chamada uma vez apenas após pupulateData()
 ******************************************************************************/

calculation Decision::doDecision(void)
{   
    this->calculation_process = WAITING_FOR_CALCULATION;

    if(this->isPurchaseAction() == true)
    {
        this->purchaseAction = true;
    }
    else if(this->isSaleAction() == true)
    {
        this->purchaseAction = false;
    }

    this->managmentRisk();
    this->calculation_process = CALCULATION_IS_OVER;

    return this->calculation_process;
    
}

/*******************************************************************************
 *	Função: isSaleDecision
 *	----------------------
 * 	Função dedicada a a verificar se a ação deve ser vendida dentro da regra
 *  de negócios estiplada
 *	recebe: nada
 *	retorna: booleano se a ação deve ser vendida
 ******************************************************************************/
bool Decision::isSaleAction(void)
{
    if(this->decisionData.closeWeek < this->decisionData.average_20)
    {
         if(this->decisionData.average_20 < this->decisionData.average_50)
         {
            if(this->decisionData.stochastic_8 > MAX_STOCHASTIC_SALE) 
            {
                return true;
            }
         }
    }
}

/*******************************************************************************
 *	Função: isPurchasecision
 *	----------------------
 * 	Função dedicada a a verificar se a ação pode ser comprada dentro da regra
 *  de negócios estiplada
 *	recebe: nada
 *	retorna: booleano se a ação deve ser comprada.
 ******************************************************************************/
bool Decision::isPurchaseAction(void)
{
    if(this->decisionData.closeWeek >= this->decisionData.average_20)
    {
         if(this->decisionData.average_20 >= this->decisionData.average_50)
         {
            if(this->decisionData.stochastic_8 <= MAX_STOCHASTIC_PURCHASE) 
            {
                return true;
            }
         }
    }
}

/*******************************************************************************
 *	Função: isPurchasecision
 *	----------------------
 * 	Função fazer o gerenciamento de risco estipulando quantidade de ações de compra
 *  ou venda. Popula uma struct de retorno para a classe principal
 *	recebe: nada
 *	retorna: nada
 ******************************************************************************/

void Decision::managmentRisk()
{
    int target, qtdStocks = 1;
    float stopLoss, trigger, riskTrade;
    

    stopLoss = this->decisionData.lowDaily;
	trigger = this->decisionData.highDaily;

    if(this->purchaseAction = true)
    {
        target = ((trigger - stopLoss) * 3) + trigger;
	    while(riskTrade < (0.01*this->userMoney)){
                
            riskTrade = (trigger - stopLoss) * qtdStocks;
            qtdStocks++;	
        }
        this->outputUser.message  = "Compra";
	}

    else if(this->purchaseAction = false)
    {
        target = trigger - ((stopLoss - trigger) * 3);
		while(riskTrade < (0.01*this->userMoney)){
			riskTrade = (stopLoss - trigger) * qtdStocks;
			qtdStocks++;	
		}
		this->outputUser.message  = "Venda";
    }

    this->outputUser.stopLoss = stopLoss;
    this->outputUser.trigger = trigger;
    this->outputUser.qtdStocks = qtdStocks;
}

/*******************************************************************************
 *	Função: getUserMoney
 *	----------------------
 * 	Retorna variavel privada chamada UserMOney
 *  de negócios estiplada
 *	recebe: nada
 *	retorna: float 
 ******************************************************************************/	
float Decision::getUserMoney(void)
{
    return this->userMoney;
}

/*******************************************************************************
 *	Função: setUserMoney
 *	----------------------
 * 	Dá acesso à variavel privada userMoney a classes externas
 *  de negócios estiplada
 *	recebe: float
 *	retorna: nada
 ******************************************************************************/	
void Decision::setUserMoney(float money)
{
    this->userMoney = money;
}

/*******************************************************************************
 *	Função: getUserData
 *	----------------------
 * 	Retorna struct privada chamada outputUser
 *	recebe: nada
 *	retorna: struct outputUser 
 ******************************************************************************/
Decision::userData Decision::getUserData(void)
{
    return this->outputUser;
}


Decision::Decision(){}
Decision::~Decision(){}