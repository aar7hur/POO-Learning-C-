/**
 * • Receba a data de nascimento do usuário;
 *   •   Faça a validação da data;
 *   •   Imprima: Data por extenso, signo e se o ano é bissexto.
 *   Os dados da classe devem ser privados.
 * 
 * Author: Arthur Munhoz Amaral
 * Date: 27/07/2020
 * GRR20177243
 * Language: C
 * Programação Orientada a Objeto
 * 
 * Purpose: Learning c++ language
 **/

#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef enum total_days
{
    int jan = 
    int fev = 
    int march = 
    int april = 
    int m
}

/*********************************************************
 * 
 *              Class declarations
 * 
 * ******************************************************/
class User {
    private:
        std::string date_of_birth;
        std::string signo;
        bool bissextile_year;
        Datetime date;
        Horoscope horoscope;
    
    public:
        User(string);
        std::string get_date_of_birth(void);
        void set_date_of_birth(string date);
        bool get_bissextile_year(void);
        void set_bissextile_year(void);
        int run_api(void);
};

class Datetime {
    private:;
        int day;
        int month;
        int year;

    public:
        bool validates_parse_date(std::string);
        int converts_date(std::string);
        void get_day(void);
        void get_month(void);
        void get_year(void);
};

class Horoscope {
    private:
        std::string sign;
    public:
        void set_sign(string);
        std::string get_sign(void);
};

/*********************************************************
 * 
 *              User Class methods
 * 
 * ******************************************************/
User::User(string date)
{
    this->set_date_of_birth(date);
}

bool User::get_bissextile_year()
{
    return bissextile_year;
}

std::string User::get_date_of_birth()
{
    return date_of_birth;
}
/*********************************************************
 * 
 *              Datetime Class methods
 * 
 * ******************************************************/

bool Datetime::validates_parse_date(const std::string date)
{
    std::string day = date.substr(0,2);
    std::string month = date.substr(2,2);
    std::string year = date.substr(4,4);

    
}