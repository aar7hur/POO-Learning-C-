/**
 * Autor: Arthur Munhoz Amaral
 * GRR20177243.
 * 
 * 
 * Implemente um programa que realize operações aritméticas em números complexos, mas
dessa vez utilizando uma classe para representar o número complexo. Crie os seguintes
métodos para:
• Construtor que deverá inicializar o valor do número complexo.
• Adição, subtração, multiplicação e divisão de dois números complexos.
• Imprimir o número na forma retangular.
• Imprimir o número na forma polar.
• Crie um destrutor.
• Criar um programa principal para testar a classe.
• Os dados da classe devem ser privados.
• Para entrada e saída de dados utilize o comando cin e cout.
• Criar os arquivos Complexo.h, Complexo.cpp e main.cpp.
**/

#include <iostream>
#include "Complexo.h"

using namespace std;

int run_operations(ComplexNumber& A, ComplexNumber& B);

int main(int argc, char** argv)
{
    double real_part1, imaginary_part1, real_part2, imaginary_part2;

    // Get complex number A
    cout << "Entre com a parte real do número complexo A: ";
    cin >> real_part1;
    cout << "Entre com a parte imaginária do número complexo A: ";
    cin >> imaginary_part1;

    // Get complex number B
    cout << "Entre com a parte real do número complexo B: ";
    cin >> real_part2;
    cout << "Entre com a parte imaginária do número complexo B: ";
    cin >> imaginary_part2;
   
    //Instantiate complex number objects
    ComplexNumber A(real_part1, imaginary_part1);
    cout << "\nNúmero complexo A: " << A; 
    ComplexNumber B(real_part2, imaginary_part2);
    cout << "\nNúmero complexo B: " << B;
    // Do complex numbers operations
    run_operations(A, B);

}

int run_operations(ComplexNumber& A, ComplexNumber& B)
{
    ComplexNumber result_sum = A + B;
    cout << "\nA soma dos números complexos A + B é: " << result_sum;
    result_sum.~ComplexNumber() ;

    ComplexNumber result_subs = A - B;
    cout << "\nA subtração dos números complexos A - B é: " << result_subs; 
    result_subs.~ComplexNumber();

    ComplexNumber result_multiply = A * B;
    cout << "\nA multiplicação dos números complexos é: " << result_multiply; 
    result_multiply.~ComplexNumber();

    ComplexNumber result_divide = A / B;
    cout << "\nA divisão dos números complexos é: " << result_divide; 
    result_divide.~ComplexNumber();
}
