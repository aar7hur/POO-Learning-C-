#include <cstddef>

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
        void setPrice(float *, size_t);
        void getKcurve(void);
        void averageKcurve(void);
        float getResult(void);
        float getLowDailyPrice(void);
        float getHighDailyPrice(void);
        size_t valoresMinimos(float * output, float * inputArray, size_t inputSize);
        size_t valoresMaximos(float * output, float * inputArray, size_t inputSize);
        size_t kValues(float * output, float * arrayMin, float* arrayMax, float* arrayClose, size_t sizeClose);

};
