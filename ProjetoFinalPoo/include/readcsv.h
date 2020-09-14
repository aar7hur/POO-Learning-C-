#ifndef READCSV_HEADER_GUARD
#define READCSV_HEADER_GUARD

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

std::vector<std::string> quebrarLinha(const std::string linha, char virgula=',');

class Coluna{
    private:
    std::string header;
    std::vector <std::string> dados;

    public:
    Coluna(std::string headerEntrada);
    
    std::string getHeader() const;

    Coluna& operator<<(std::string entrada);

    template <class Tipo, class Func>
    size_t jogarPraArray(Tipo *&array, Func converter, size_t limite=0);
    
    std::string topo();
    
};

class Coluna_Interface{
    private: Coluna * coluna;
    public: size_t requestSize;
    
    public:
    Coluna_Interface(Coluna *origem, size_t size=0);
    Coluna_Interface & operator()(size_t size);
    size_t operator>>(std::string *&array);
    size_t operator>>(int *&array);
    size_t operator>>(float *&array);
    size_t operator>>(double *&array);
    
    std::string topo();
    template<class T> T topo();
};

// Functor helpers
struct _transparente;
struct _stoi;
struct _stof;
struct _stod;

class Tabela{

protected:
    std::vector<std::string> headers;
    std::vector<Coluna> colunas;
    Tabela(); // Construtor vazio, penas para heranças.
        
public:
 
    Tabela(std::string arquivo);
    
    virtual Tabela& open(std::string arquivo);
    
    Tabela& operator<<(std::vector<std::string> linha);
   
    Coluna_Interface operator[](std::string header);
};


class Ativo: public Tabela{

public:
    
    Ativo(std::string acao, std::string tipo="d");
    Ativo& open(std::string acao, std::string tipo="d");
    
    // Operadores precisam ser redefinidos em uma herança
    Ativo& operator<<(std::vector<std::string> linha);
    Coluna_Interface operator[](std::string header);
    
};

#endif
