#include "../include/main.h"
#include "../include/decision.h"
#include <iostream>



int main(int argc, char * argv[])
{
	UserInterface *user = new UserInterface(&argc, &argv);
	user->run_window();
}

/*
int main(int argc, char* argv[])
{
	float user_money = 100000;
	std::string action_ = "WEGE3";

	Decision decision;
	decision.setUserMoney(user_money);

    // Popula os dados necessários para fazer os calculos.
    // Ver documentação do metodo na classe em: Decision.cpp
    decision.populateData(action_);

    // Faz a decisão de vender, comprar, ou aguardar.
    while(decision.doDecision() != CALCULATION_IS_OVER);

    // Cria uma struct para guardar os dados a serem mostrados
    // para o usuário
    struct userData user;

    // Pega os dados privados da classe Decision para mostrar ao
    // usuário
    user = decision.getUserData();

    // Converte os dados de float para string
    std::string stopLoss = std::to_string(user.stopLoss);
    std::string trigger = std::to_string(user.trigger); 
    std::string target = std::to_string(user.target);
    std::string qtdStocks = std::to_string(user.qtdStocks);

    // Printa os dados para o usuário no terminal
    std::string outputUser = user.message + "!!\n" + "stopLoss:" + stopLoss +
                            "!\nTrigger: " + trigger + "!\nTarget: " + target +
                            "!\nQtdStocks: " + qtdStocks;

	std::cout << outputUser;

}
*/