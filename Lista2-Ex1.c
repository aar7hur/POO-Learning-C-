#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NCONTAS 15	//numero total de contas que podem ser cadastradas

typedef struct{
	char numeroConta[5];
	float saldo;
	char nome[100];
}Contas;
Contas contas[15]; 

int num;

bool verificaNumero(char numeroConta[5]){
	int i, results, cont;
	cont = 0;
	
	for(i=0; i<NCONTAS; i++){
		results = strcmp(numeroConta, contas[i].numeroConta);
		if(results == 0){
			cont = cont + 1;
		}
	}
	if (cont ==1){
		return true;
	}
	else{
		printf("Numero de conta ja esta sendo utilizada. Por favor digite outra numero de 5 digitos.\n");
		return false;
	}
}

void cadastro(int num){
	
	char more;
	bool again = true;
	bool retorna;

	retorna = false;
	printf("Voce selecionou a opcao para realizar um novo cadastro.\n\n");
	printf("Digite o nome do cliente: ");
	scanf("%s%*c", &contas[num].nome);
	
	while(retorna == false){
		printf("Digite o numero da conta (5 digitos): ");
		scanf("%s%*c", &contas[num].numeroConta);
		retorna = verificaNumero(contas[num].numeroConta);
	}
			
	printf("Digite o saldo atual dessa conta: ");
	scanf("%f%*c", &contas[num].saldo);
	printf("Cliente cadastrado.");
	return;
}

void mostrarContas(char clienteConsulta[100]){
	int i, results;
	char escolha;

	for(i=0; i<NCONTAS; i++){
		results = strcmp(clienteConsulta, contas[i].nome);
		if(results == 0){
			printf("Cliente encontrado com sucesso.\n");
			printf("Nome do cliente: %s\n", contas[i].nome);
			printf("Numero da conta: %s\n", contas[i].numeroConta);
			printf("Saldo da conta: %.2f\n\n", contas[i].saldo);
		}
	}
	return;
	
}

void excluirMenor(){
	
	int k;
	float menor;
	menor = contas[0].saldo;
	for(k=1; k<NCONTAS; k++){
		if(contas[k].saldo < menor && contas[k].saldo > 0){
			menor = contas[k].saldo;
		}
	}
	
	printf("O menor saldo dentre todas as contas cadastradas eh de: %.2f\n", menor);
	
	for(k=0; k<NCONTAS; k++){
		if(contas[k].saldo == menor){
			printf("A conta que tem o menor saldo e sera excluida eh a conta de numero %s, do cliente %s.\n", contas[k].numeroConta, contas[k].nome);
			strcpy(contas[k].nome, "NULL");
			contas[k].saldo = 0.0;
			strcpy(contas[k].numeroConta, "NULL");
		}
	}
	return;
}


bool menu(){
	
	int opcao;
	bool chooseOption = false;
	
	while(chooseOption == false){
		printf("MENU\n\n");
		printf("Selecione a opcao desejada com:\n");
		printf("1 -> Cadastrar nova conta bancaria;\n");
		printf("2 -> Vizualizar todas as contas bancarias de um determinado cliente;\n");
		printf("3 -> Excluir a conta com menor saldo;\n");
		printf("4 -> Sair;\n");	
		scanf("%d", &opcao);
		if(opcao == 1 || opcao == 2 || opcao == 3 || opcao ==4){
			chooseOption = true;
		}
	}
	
	if(opcao == 1){
		char maiscadastro;
		bool stop = false;
		while(stop == false){
		
			cadastro(num);
			printf("Deseja fazer mais algum cadastro? [s] para sim, ou [n] para nao: ");
			scanf("%c", &maiscadastro);
			if(maiscadastro == 's'){
				stop = false;
				num = num +1;
			}
			if(maiscadastro == 'n'){
				stop = true;
				num = num + 1;
			}
		}
		return false;
		
	}
	
	if(opcao == 2){
		
		char clienteConsulta[100], escolha;
		bool parar = false;
		printf("Voce selecionou a opcao para consultar as contas de um cliente.\n");
		
		printf("Digite o nome do cliente que deseja: ");
		scanf("%s", &clienteConsulta);
		mostrarContas(clienteConsulta);
	
		return false;
	}
	
	if(opcao == 3){
		printf("Voce selecionou a opcao para excluir a conta de menor saldo.\n");
		excluirMenor();
		printf("A conta de menor saldo foi excluida com sucesso.\n");
		
		return false;
	}
	
	if(opcao == 4){
		return true;
	}
}




int main(){
	
	int i, j, opcao, count;
	bool flag = true;
	bool inicio = false;
	num = 0;
	
	for(i=0; i<NCONTAS; i++){
		strcpy(contas[i].nome, "NULL");
		contas[i].saldo = 0.0;
		strcpy(contas[i].numeroConta, "NULL");
	}

	while(inicio==false){
		inicio = menu();
	}
		
	
	return 0;
}
