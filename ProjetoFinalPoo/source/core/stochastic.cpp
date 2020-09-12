#include "../include/stochastic.h"

Stochastic::Stochastic(){}
Stochastic::~Stochastic(){}

void Stochastic::setHighDailyPrice(void)
{
    float priceCloseDaily[200], price[200+16];
    float  bestprice;
    float priceHighDaily[200];
    int n = 8; // n = intervalo que deseja analisar

    // 200 = len(std::<vector>)
    for(int i = 0; i < 200; i ++) {
        priceCloseDaily[i] = price[i];
    }

    for(int i = 0; i < 200; i++) {
        if(i > 8) {
            n++;
        }
        bestprice = price[i];

        for(int j = i; j < i + n; j++) {
            if(price[j] > bestprice) {
                bestprice = price[j];
            }
        }
        this->stochasticData.priceHighDaily[i] = bestprice;
        //ver sentido dos dados, Primeiro mais recente ou mais antigo
    }
    this->highPriceDaily = priceHighDaily[0];
}

void Stochastic::setLowDailyPrice(void)
{
    int n = 8;
    float worstprice;
    float priceLowDaily[200];

    for(int i = 0; i < 200; i++) {
        if(i > 8) {
            n++;
        }
        worstprice = this->stochasticData.price[i];
        for(int j = i; j < i + n; j++) {
            if(this->stochasticData.price[j] < worstprice) {
                worstprice = this->stochasticData.price[j];
            }
        }
        this->stochasticData.priceLowDaily[i] = worstprice;
    }
    this->lowPriceDaily = priceLowDaily[0];

}

void Stochastic::getKcurve(void)
{
    float Kcurve[200];

    for(int i = 0; i < 200+ 2; i++) {
        this->stochasticData.Kcurve[i] = 100 * 
        ((this->stochasticData.price[i] - this->stochasticData.priceLowDaily[i])
        /(this->stochasticData.priceLowDaily[i]-this->stochasticData.priceLowDaily[i]));
    }
}

void Stochastic::averageKcurve(void)
{
    for(int i = 0; i < 200; i++) {
        this->stochasticData.KcurveAverage[i] = this->stochasticData.Kcurve[i] + 
        this->stochasticData.Kcurve[i + 1] + this->stochasticData.Kcurve[i + 2];
    }
}

void Stochastic::setPrice(float* price)
{
    for(int i = 0; i < 216; i++)
    {
        this->stochasticData.price[i] = price[i];
    }
}

float Stochastic::getResult(void)
{
    this->stochasticResult = this->stochasticData.Kcurve[0];
    return this->stochasticResult;
}


float Stochastic::getLowDailyPrice(void)
{
    return this->lowPriceDaily;
}
float Stochastic::getHighDailyPrice(void)
{
    return this->highPriceDaily;
}

