#ifndef DECISION_HEADER_GUARD
#define DECISION_HEADER_GUARD

#define MAX_STOCHASTIC_PURCHASE 20
#define MAX_STOCHASTIC_SALE 80

#include "readcsv.h"
#include "movingAverage.h"
#include "stochastic.h"

enum calculation
{
    WAITING_FOR_CALCULATION,
    CALCULATION_IS_OVER,
};

class Decision
{
	private:
		bool purchaseAction;
        float userMoney;
		struct dataForDecision {
			float closeWeek;
			float average_20;
			float average_50;
			float stochastic_8;
            float highDaily;
			float lowDaily;
		} decisionData;

    MovingAverage movingAverage;
    Stochastic stochastic;
    bool isPurchaseAction(void);
    bool isSaleAction(void);
    void managmentRisk(void);
    void populateStochastic(std::string ativo);
    void populateAverage(std::string ativo);
    void populateCloseWeek(std::string ativo);

	public:
        enum calculation calculation_process;
        struct userData {
            float stopLoss;
            float trigger;
            float target;
            float qtdStocks;
            std::string message;
        } outputUser;

        float getUserMoney(void);
        void setUserMoney(float);
		void populateData(std::string);
        calculation doDecision(void);
        userData getUserData(void);
		Decision();
		~Decision();	
};

#endif