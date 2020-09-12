
class Stochastic
{
    private:
    float stochasticResult;
    float lowPriceDaily;
    float highPriceDaily;
    float kcurve;
    struct stochasticData {
        float priceCloseDaily[200];
        float priceHighDaily[200];
        float priceLowDaily[200];
        float Kcurve[200];
        float KcurveAverage[202]; 
        float price[216];
    } stochasticData;

    public:
        Stochastic();
        ~Stochastic();
        void setLowDailyPrice(void);
        void setHighDailyPrice(void);
        void setPrice(float *);
        void getKcurve(void);
        void averageKcurve(void);
        float getResult(void);
        float getLowDailyPrice(void);
        float getHighDailyPrice(void);

};