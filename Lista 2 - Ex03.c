#include <stdio.h>
#include <stdbool.h>

//######################################################################################################
//Definição da estrutura
typedef struct{
	int numerador;
	int denominador;
}racionalNumber;
racionalNumber numA, numB;
racionalNumber numAux;
//######################################################################################################

//######################################################################################################
//Inicializando as funções
void criaRacional();
void imprimeRacional();
void soma();
void simplifica();
float divisao(int n, int d);
void subtracao();
void multiplicacao();
void divideRacionais();
bool verificaEntrada(int numero);

//######################################################################################################

//######################################################################################################
//Função que pede para o usuario entrar com os numeros do numerador e denominador
void criaRacional(){	
	
	bool check = false;
	printf("Criando o numero racional A.\n");
	printf("Digite o numerador: ");
	scanf("%d", &numA.numerador);
	
	while(check==false){
		printf("Digite o denominador: ");
		scanf("%d", &numA.denominador);
		check = verificaEntrada(numA.denominador);
	}
	
	check = false;
	printf("\n\nAgora vamos criar o numero racional B.\n");
	printf("Digite o numerador: ");
	scanf("%d", &numB.numerador);
	
	while(check == false){
		printf("Digite o denominador: ");
		scanf("%d", &numB.denominador);
		check = verificaEntrada(numB.denominador);
	}
	
	return;
}
//######################################################################################################

//######################################################################################################
//Função para imprimir os dois numeros racionais A e B, em sua forma "crua", simplificada e em ponto flutuante
void imprimeRacional(){		
	
	float resDivisao;
	numAux.numerador = numA.numerador;
	numAux.denominador = numA.denominador;
	simplifica();
	resDivisao = divisao(numAux.numerador, numAux.denominador);
	
	if(numA.numerador == numAux.numerador && numA.denominador==numAux.denominador){
		printf("\n\nNumero racional A = %d/%d = %f\n", numA.numerador, numA.denominador, resDivisao);	
	}
	else{
		printf("\n\nNumero racional A = %d/%d = %d/%d = %f\n", numA.numerador, numA.denominador, 
											numAux.numerador, numAux.denominador, resDivisao);
	}
	
	
	numAux.numerador = numB.numerador;
	numAux.denominador = numB.denominador;
	simplifica();
	resDivisao = divisao(numAux.numerador, numAux.denominador);
	
	if(numB.numerador==numAux.numerador && numB.denominador==numAux.denominador){
		printf("Numero racional B = %d/%d = %f\n", numB.numerador, numB.denominador, resDivisao);
	}
	else{
		printf("Numero racional B = %d/%d = %d/%d = %f\n", numB.numerador, numB.denominador, 
										numAux.numerador, numAux.denominador, resDivisao);
	}
	
	return;
}
//######################################################################################################

//######################################################################################################
//Função de soma de A com B
void soma(){	

	float resDiv;
	printf("A + B = ");
	numAux.numerador = (numA.numerador*numB.denominador) + (numB.numerador*numA.denominador);
	numAux.denominador = numA.denominador * numB.denominador;
	simplifica();
	resDiv = divisao(numAux.numerador, numAux.denominador);
	printf("%d/%d = %d/%d = %f", (numA.numerador*numB.denominador) + (numB.numerador*numA.denominador),
					numA.denominador * numB.denominador, numAux.numerador, numAux.denominador, resDiv);
	return;
}
//######################################################################################################

//######################################################################################################
//Função de subtração
void subtracao(){	
	
	float resDiv;
	printf("\nA - B = ");
	numAux.numerador = (numA.numerador*numB.denominador) - (numB.numerador*numA.denominador);
	numAux.denominador = numA.denominador*numB.denominador;
	simplifica();
	resDiv = divisao(numAux.numerador, numAux.denominador);
	printf("%d/%d = %d/%d = %f", (numA.numerador*numB.denominador) - (numB.numerador*numA.denominador),
					numA.denominador * numB.denominador, numAux.numerador, numAux.denominador, resDiv);
	return;
}
//######################################################################################################

//######################################################################################################
//Função de multiplicação
void multiplicacao(){	
	
	float resDiv;
	printf("\nA * B = ");
	numAux.numerador = numA.numerador * numB.numerador;
	numAux.denominador = numA.denominador * numB.denominador;
	simplifica();
	resDiv = divisao(numAux.numerador, numAux.denominador);
	printf("%d/%d = %d/%d = %f", numA.numerador * numB.numerador, numA.denominador * numB.denominador,
														 numAux.numerador, numAux.denominador, resDiv);
	return;
}
//######################################################################################################

//######################################################################################################
//Função de divisao
void divideRacionais(){		
	
	int aux;
	float resDiv;
	aux = numB.numerador;
	numB.numerador = numB.denominador;
	numB.denominador = aux;
	
	if(numB.denominador==0){
		printf("\nA divisao nao pode ser realizada, pois ficará com 0 no denominador.");
		return;
	}
	else{
		printf("\nA / B = ");
		numAux.numerador = numA.numerador * numB.numerador;
		numAux.denominador = numA.denominador * numB.denominador;
		simplifica();
		resDiv = divisao(numAux.numerador, numAux.denominador);
		printf("%d/%d = %d/%d = %f", numA.numerador * numB.numerador, numA.denominador * numB.denominador, 
														numAux.numerador, numAux.denominador, resDiv);
		return;
	}
	
	
}
//######################################################################################################

//######################################################################################################
//Função que faz a simplificação da fraçao
void simplifica(){		
	
	if(numAux.numerador % numAux.denominador == 0){
		printf("%d", numAux.numerador/numAux.denominador);
	}
	else{
		if(numAux.numerador>numAux.denominador){
			
			int i;
			for(i=numAux.denominador-1; i>1; i--){
				
				if((numAux.numerador % i)== 0 && (numAux.denominador % i)==0){
					numAux.numerador = numAux.numerador / i;
					numAux.denominador = numAux.denominador / i;
				}
			}
		}
		
		else if (numAux.numerador<numAux.denominador && numAux.numerador>0){
			
			int j;
			for(j=numAux.numerador-1; j>1; j--){
				
				if((numAux.numerador % j)==0 && (numAux.denominador %j)==0){
					numAux.numerador = numAux.numerador / j;
					numAux.denominador = numAux.denominador / j;
				}
			}
		}
		
		else if(numAux.numerador < 0){
			
			numAux.numerador = -numAux.numerador;
			int k;
			for(k=numAux.numerador-1; k>1; k--){
				
				if((numAux.numerador % k)==0 && (numAux.denominador %k)==0){
					numAux.numerador = numAux.numerador / k;
					numAux.denominador = numAux.denominador / k;
				}
			}
			numAux.numerador = -numAux.numerador;
		}
	}
	return;
	
}
//######################################################################################################

//######################################################################################################
//Função que faz a divisao pra se ter um resultado de ponto flutuante
float divisao(int n, int d){	
	
	float resDiv;      
	resDiv = (float)n/d;
	return resDiv;
}
//######################################################################################################

//######################################################################################################
//Função para verificar se a entrada do denominador é 0
bool verificaEntrada(int numero){

		if(numero == 0){
			printf("O denominador deve ser diferente de 0, por favor digite outro numero.\n");
			return false;
		}
		else{
			return true;
		}
}
//######################################################################################################

//######################################################################################################

int main(){
	criaRacional();
	imprimeRacional();
	soma();
	subtracao();
	multiplicacao();
	divideRacionais();
	return 0;
}
//######################################################################################################
