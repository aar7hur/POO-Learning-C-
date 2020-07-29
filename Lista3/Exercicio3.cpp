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

struct horoscope_base
{
    const string sign;
    const int date;
};

/*********************************************************
 * 
 *              Class declarations
 * 
 * ******************************************************/

class Datetime {
    private:;
        int day;
        int month_int;
        int year;
        std::string month;
        bool bissextile_year;
    public:
        bool validates_parse_date(std::string);
        int converts_date(std::string);
        int get_day(void);
        std::string get_month(void);
        int get_month_int(void);
        bool get_bissextile_year(void);
        int get_year(void);
        void set_month_name(int);
        void set_day(int);
        void set_year(int);
       
};

class User {
    private:
        Datetime date;
        std::string horoscope;
        void print_user(void);
        void set_horoscope(void);
        std::string get_horoscope(void);
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
    this->set_horoscope();
    this->print_user();
} 

void User::print_user(void)
{
    cout << this->date.get_day() << " de " << this->date.get_month();
    cout << " de " << this->date.get_year() << "\n";
    cout << "Signo: " << this->get_horoscope() << "\n";
    if (this->date.get_bissextile_year() == true)
    {
        cout << "É ano bissexto.";
    }
    else
    {
        cout << "Não é ano bissexto.";
    }
    
}

void User::set_horoscope(void)
{
    vector<horoscope_base>  sign_date {
        {"Aquário", 1020},  
        {"Peixes", 2019},
        {"Áries", 3021},
        {"Touro", 4020},
        {"Gẽmeos", 5021},
        {"Câncer", 6021},
        {"Leão", 7023},
        {"Virgem", 8023},
        {"Libra", 9023},
        {"Escorpião", 10023},
        {"Ságitário", 11022},
        {"Capricórnio", 12022}
    };
    int day = this->date.get_day();
    int month = this->date.get_month_int();
    int payload = 1000*month + day;

    for (int i = 0 ; i < sign_date.size(); i++) 
    {
        if (payload >= sign_date[i].date && payload < sign_date[i+1].date)
        {
            this->horoscope = sign_date[i].sign;
        }
    }
}

std::string User::get_horoscope(void)
{
    return this->horoscope;
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
    else
    {
        this->bissextile_year = false;
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
        this->month_int = month;
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

int Datetime::get_month_int(void)
{
    return this->month_int;
}

int Datetime::get_day(void)
{
    return this->day;
}
bool Datetime::get_bissextile_year(void)
{
    return this->bissextile_year;
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
