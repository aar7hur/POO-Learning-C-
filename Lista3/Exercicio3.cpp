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
#include <ctime>
#include <vector>

using namespace std;

/*********************************************************
 * 
 *              Class declarations
 * 
 * ******************************************************/

class Datetime {
    private:;
        int day;
        string month;
        int year;
        bool bissextile_year;
        void set_month_name(int);
        void set_day(int);
        void set_year(int);
        
    public:
        bool validates_parse_date(std::string);
        int converts_date(std::string);
        int get_day(void);
        std::string get_month(void);
        int get_year(void);
};

class Horoscope {
    private:
        std::string sign;
    public:
        void set_sign(string);
        std::string get_sign(void);
};

class User {
    private:
        Datetime date;
        Horoscope horoscope;
        void print_user(void);
    public:
        int run_api(string);
};


/*********************************************************
 * 
 *              User Class methods
 * 
 * ******************************************************/
int User::run_api(string date)
{
    this->date.validates_parse_date(date);
    this->print_user();
} 

void User::print_user(void)
{
    cout << this->date.get_day() << " de " << this->date.get_month();
    cout << " de " << this->date.get_year() << "\n";
}

/*********************************************************
 * 
 *              Datetime Class methods
 * 
 * ******************************************************/
void Datetime::set_year(int year)
{
    time_t t = time(NULL);
    struct tm* tPtr = localtime(&t);

    if ((year > 1800) && (year < (tPtr->tm_year + 1900)))
    {
        this->year = year;
       
    }
    else
    {
        cout << "The year must be a number betwee 1800 and 2020!!";
        exit(EXIT_FAILURE);
    }

    if (((year % 4 == 0) && (year %100 != 0)) || (year % 400 == 0))
    {
        this->bissextile_year = true;
    }
}

void Datetime::set_month_name(int month)
{
    const std::vector<std::string> months_of_year = {
        "Janeiro","Fevereiro","Março",
        "Abril","Maio","Junho","Julho",
        "Agosto","Setembro","Outubro",
        "Novembro","Dezembro",
    };

    if ((month > 0) && (month <= 12))
    {
        this->month = months_of_year[month-1];
    }
    else
    {
        cout << "The month must be a number betwee 1 and 12!!";
        exit(EXIT_FAILURE);
    }
}

void Datetime::set_day(int day)
{
    std::map<std::string, int> months_dict;

    months_dict["Janeiro"] = 31;  
    months_dict["Fevereiro"] = 28;
    months_dict["Março"] = 31;  
    months_dict["Abril"] = 30;
    months_dict["Maio"] = 31;
    months_dict["Junho"] = 30;
    months_dict["Julho"] = 31;
    months_dict["Agosto"] = 30;
    months_dict["Setembro"] = 30;
    months_dict["Outubro"] = 31;
    months_dict["Novembro"] = 30;
    months_dict["Dezembro"] = 31;

    if (this->bissextile_year)
    {
        months_dict["Fevereiro"] = 29;
    }

    if ((day >= 1) && (day <= months_dict[this->month]))
    {
        this->day = day;
    }
    else
    {
        cout << "Please enter with a valid day!";
        exit(EXIT_FAILURE);
    } 
}

int Datetime::get_year(void)
{
    return this->year;
}

std::string Datetime::get_month(void)
{
    return this->month;
}

int Datetime::get_day(void)
{
    return this->day;
}

bool Datetime::validates_parse_date(const std::string date)
{

    std::size_t delimiter_first_of = date.find('/');
    std::size_t delimiter_last_of = date.rfind('/');
  
    if (delimiter_first_of == std::string::npos)
    {
        cout << "Please enter with date in format dd/mm/AAAA";
        exit(EXIT_FAILURE);
    }
    if (delimiter_last_of == std::string::npos)
    {
        cout << "Please enter with date in format dd/mm/AAAA";
        exit(EXIT_FAILURE);
    }

    int day = stoi(date.substr(0, delimiter_first_of));
    int month = stoi(date.substr(delimiter_first_of+1, 2));
    int year = stoi(date.substr(delimiter_last_of+1, 4));

    this->set_month_name(month);
    this->set_year(year);
    this->set_day(day);
}


int main()
{
    std::string str;

    cout << "Please enter with yout birthday date: ";
    getline(cin, str);
    User User;
    User.run_api(str);
}
