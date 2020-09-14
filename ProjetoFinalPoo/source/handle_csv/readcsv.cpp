#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "readcsv.h"


/* Functors helpers, pra passar conversãos em um template */
struct _transparente{
    std::string operator()(std::string string){
        return string;
    }
} transparente;

struct _stoi{
    int operator()(std::string string){
        return std::stoi(string);
    }
} stoi;

struct _stof{
    float operator()(std::string string){
        return std::stof(string);
    }
} stof;

struct _stod{
    double operator()(std::string string){
        return std::stod(string);
    }
} stod;


/* Função auxiliar para separar uma string por um limitador */
std::vector<std::string> quebrarLinha(const std::string linha, char virgula){
    std::vector<std::string> array;
    std::string token;
    std::stringstream stringFile(linha);
    while(getline(stringFile, token, virgula)){
        array.push_back(token);
    }

    return array;
};


/* Colunas */

Coluna::Coluna(std::string headerEntrada){
    header = headerEntrada;
}

std::string Coluna::getHeader() const{
    return header;
}
    
Coluna& Coluna::operator<<(std::string entrada){
    dados.push_back(entrada);
    return *this;
}

template <class Tipo, class Func>
size_t Coluna::jogarPraArray(Tipo *&array, Func converter, size_t limite){

    if (dados.empty()){
        array = NULL;
        return 0;
    }
    
    size_t tamanho;
    
    if (limite < dados.size() && limite != 0) {
        tamanho = limite;
    }else{
        tamanho = dados.size();
    }
    
    array = new Tipo[tamanho];
    
    for(size_t i=0; i<tamanho; i++){
        array[i] = converter(dados[i]);
    }
    
    return tamanho;
}

std::string Coluna::topo(){
    return dados.front();
}

/* Interface de Coluna */
Coluna_Interface::Coluna_Interface(Coluna *origem, size_t size){
    coluna = origem;
    requestSize=size;
}

Coluna_Interface& Coluna_Interface::operator()(size_t size){
    requestSize=size;
    return *this;
}

/* Transferir para uma Array */
size_t Coluna_Interface::operator>>(std::string *&array){
    return coluna->jogarPraArray<std::string>(array, transparente, requestSize);
}

size_t Coluna_Interface::operator>>(int *&array){
    return coluna->jogarPraArray<int>(array, stoi, requestSize);
}

size_t Coluna_Interface::operator>>(float *&array){
    return coluna->jogarPraArray<float>(array, stof, requestSize);
}

size_t Coluna_Interface::operator>>(double *&array){
    return coluna->jogarPraArray<double>(array, stod, requestSize);
}

// Função topo
std::string Coluna_Interface::topo() { return coluna->topo(); }
template<> int Coluna_Interface::topo<int>() { return stoi( coluna->topo() ); }
template<> float Coluna_Interface::topo<float>() { return stof( coluna->topo() ); }
template<> double Coluna_Interface::topo<double>() { return stod( coluna->topo() ); }

Tabela::Tabela(){
    /*
     * Classes que herdam da Tabela chamam este construtor
     * O construtor abaixo recebe uma string e dá erro se não achar o arquivo
     * Este construtor vazio deixa a classe derivada fazer a busca
     */
}

Tabela::Tabela(std::string arquivo){
    this->open(arquivo);
}

Tabela& Tabela::open(std::string arquivo){
    std::string buffer;
    std::vector<std::string> linhas;
    
    std::ifstream arquivoCSV(arquivo);

    if(arquivoCSV.fail()){
        std::cerr << "Erro: o arquivo \"" << arquivo << "\" existe?" << std::endl;
        throw "Ação não encontrada!";
    }

    // Le o arquivo e armazena as linhas.
    while(getline(arquivoCSV, buffer)){
        linhas.push_back(buffer);
    }
    
    // Seta os metadados do objeto
    headers = quebrarLinha(linhas[0]);
    for(auto i = headers.begin(); i != headers.end(); i++){
            colunas.push_back( Coluna(*i) );
    }
    
    // Transfere as linhas 
    for(auto i = linhas.rbegin(); i != --linhas.rend(); ++i){
        *this << quebrarLinha(*i);
    }
    
    return *this;
}

Tabela& Tabela::operator<<(std::vector<std::string> linha){
    if (linha.size() != headers.size()) {
        std::cerr << "Tentado inserir uma linha com " << linha.size() << " colunas em uma tabela de " << headers.size() << " colunas." << std::endl;
        throw "Erro ao inserir linha: dimensões invalidas!";
    }

    for(size_t i; i < headers.size(); ++i){
        colunas[i] << linha[i];
    }
    
    return *this;
}

Coluna_Interface Tabela::operator[](std::string header){
    for(auto i = colunas.begin(); i != colunas.end(); i++){
        if (header.compare(i->getHeader()) == 0){
            return Coluna_Interface(&*i);
        }
    }
    
    std::cerr << "Tentado acessar uma coluna chamada \""<< header << "\" de uma Tabela que não tem tal coluna." << std::endl;
    throw "Erro ao acessar uma coluna: coluna inexistente!";
}

Ativo::Ativo(std::string acao, std::string tipo) {
    this->open(acao, tipo);
}

Ativo& Ativo::open(std::string acao, std::string tipo){
    std::string buffer;
    std::vector<std::string> linhas;
    
    // Abre o CSV correspondente a ação
    // Prefixo d_ para diária, w_ para mensal (de weekly)
    if (tipo != "d" && tipo != "w"){
        throw "Falha ao ler o CSV: Tipo de ação invalida!";
    }        

    transform(acao.begin(), acao.end(), acao.begin(), toupper);
    acao = "ativos/" + tipo + "_" + acao + ".SA.csv";
    std::ifstream arquivoCSV(acao.c_str());

    if(arquivoCSV.fail()){
        std::cerr << "Erro: o arquivo \"" << acao << "\" existe?" << std::endl;
        throw "Ação não encontrada!";
    }

    // Le o arquivo e armazena as linhas.
    while(getline(arquivoCSV, buffer)){
        linhas.push_back(buffer);
    }
    
    // Seta os metadados do objeto
    headers = quebrarLinha(linhas[0]);
    for(auto i = headers.begin(); i != headers.end(); i++){
            colunas.push_back( Coluna(*i) );
    }
    
    // Transfere as linhas 
    for(auto i = linhas.rbegin(); i != --linhas.rend(); ++i){
        *this << quebrarLinha(*i);
    }
    
    return *this;
}

Ativo& Ativo::operator<<(std::vector<std::string> linha){
    if (linha.size() != headers.size()) {
        std::cerr << "Tentado inserir uma linha com " << linha.size() << " colunas em uma tabela de " << headers.size() << " colunas." << std::endl;
        throw "Erro ao inserir linha: dimensões invalidas!";
    }

    for(size_t i; i < headers.size(); ++i){
        colunas[i] << linha[i];
    }
    
    return *this;
}

Coluna_Interface Ativo::operator[](std::string header){
    for(auto i = colunas.begin(); i != colunas.end(); i++){
        if (header.compare(i->getHeader()) == 0){
            return Coluna_Interface(&*i);
        }
    }
    
    std::cerr << "Tentado acessar uma coluna chamada \""<< header << "\" de uma Tabela que não tem tal coluna." << std::endl;
    throw "Erro ao acessar uma coluna: coluna inexistente!";
}
