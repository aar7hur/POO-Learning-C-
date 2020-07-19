#include <stdio.h>
#include <stdbool.h>

//Variaveis Globais
char board[9][2] = {" "," "," "," "," "," "," "," "," "}; 

int finish = 0;
//########################################################

void printBoard(char board[9][2]){ //função pra imprimir o tabuleiro
	
	printf("  %s  |  %s  |  %s  \n", board[0], board[1], board[2]);
	printf("-----------------\n");
	printf("  %s  |  %s  |  %s  \n", board[3], board[4], board[5]);
	printf("-----------------\n");
	printf("  %s  |  %s  |  %s  \n", board[6], board[7], board[8]);
	return;
}

int pedeJogada(bool turn){ //funçao que pede a lacuna que o jogador quer colocar um X ou um O;
	
	int pos, jogada;
	jogada = 0;
	
	if (turn == 0){
		while(jogada == 0){
			printf("Escolha a posicao(de 0 a 8) onde deseja colocar um X: ");
			scanf("%d", &pos);
			jogada = verificaJogada(pos);
		}
		return pos;
	}
	if (turn == 1){
		while(jogada == 0){
			printf("Escolha a posicao(de 0 a 8) onde deseja colocar um O: ");
			scanf("%d", &pos);
			jogada = verificaJogada(pos);			
		}
		return pos;
	}
}

void atualizaBoard(int pos, bool turn){ //função que atualiza o tabuleiro, coloca o X ou o O na lacuna desejada pelo jogador
	
	if (turn == false){
		board[pos][0] = 'X';
		return;
	}
	else{
		board[pos][0] = 'O';
		return;
	}
}

int verificaJogada(int pos){ //função para verificar se a jogada é válida
	
	if(board[pos][0] != ' '){
		printf("Jogada invalida, essa posicao ja esta preenchida. Escolha outra posicao.\n");
		return 0;	
	}
	else if(pos<0 || pos>8){
		printf("Jogada invalida, a posicao selecionada deve ser de 0 a 8.\n");
		return 0;
	}
	else{
		return 1;
	}
}

int verificaJogo(char board[9][2]){ //função que verifica se o jogo acabou ou não
	
	int count = 0;
	int i;
	
	if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[3][0] == 'X' && board[4][0] == 'X' && board[5][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[6][0] == 'X' && board[7][0] == 'X' && board[8][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[0][0] == 'X' && board[3][0] == 'X' && board[6][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[1][0] == 'X' && board[4][0] == 'X' && board[7][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[2][0] == 'X' && board[5][0] == 'X' && board[8][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[0][0] == 'X' && board[4][0] == 'X' && board[8][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[2][0] == 'X' && board[4][0] == 'X' && board[6][0] == 'X'){
		printf("FIM DE JOGO. O jogador X venceu!\n");
		return 1;
	}
	else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[3][0] == 'O' && board[4][0] == 'O' && board[5][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[6][0] == 'O' && board[7][0] == 'O' && board[8][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[0][0] == 'O' && board[3][0] == 'O' && board[6][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[1][0] == 'O' && board[4][0] == 'O' && board[7][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[2][0] == 'O' && board[5][0] == 'O' && board[8][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[0][0] == 'O' && board[4][0] == 'O' && board[8][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else if(board[2][0] == 'O' && board[4][0] == 'O' && board[6][0] == 'O'){
		printf("FIM DE JOGO. O jogador O venceu!\n");
		return 1;
	}
	else{
		for(i=0; i<9; i++){
			if(board[i][0] == ' '){
				count = count + 1;
			}
		}
		
		if(count > 0){
			printf("Jogo em andamento\n");
			return 0;
		}
		else{
			printf("Sem mais jogadas possiveis. Jogo empatado. DEU VELHA!\n");
			return 1;
		}
	}
	
	
}

bool iniciaJogo(){ //função do inicio do jogo, abre menu com opções de começar um jogo, ou para ver as regras
	int opcao;
	char boardRegra[9][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
	bool chooseOption = false;
	printf("\nBEM VINDO AO JOGO DA VELHA!\n\n");
	
	while(chooseOption == false){
		printf("Se deseja iniciar um jogo, digite 1;\n");
		printf("Se deseja ler as regras do jogo, digite 2;\n");
		scanf("%d", &opcao);
		if(opcao==1 || opcao==2){
			chooseOption = true;
		}
	}
	if(opcao == 1){
		return true;
	}
	
	if(opcao == 2){
		printf("\nREGRAS:\n");
		printf(" - O tabuleiro eh uma matriz de tres linhas por tres colunas;\n");
		printf(" - Dois jogadores escolhem uma marcacao cada um, geralmente um circulo (O) e um xis (X);\n");
		printf(" - Os jogadores jogam alternadamente, uma marcacao por vez, numa lacuna que esteja vazia;\n");
		printf(" - Neste jogo as posicoes a serem escolhidades vao de 0 a 8, sendo 0 a lacuna da esquerda e do topo, e 8 a lacuna mais a direita de baixo;\n");
		printf(" - O objetivo eh conseguir tres circulos ou tres xis em linha, quer horizontal, vertical ou diagonal, e ao mesmo tempo, quando possivel, impedir o adversario de ganhar na proxima rodada;\n");
		printf(" - Se nao exixtir mais lacunas vazias, e nenhum dos jogadores atingiu o objetivo, o jogo é dado como empadatado, e dizemos que DEU VELHA.\n");
		printf(" - O tabuleiro do jogo com as suas posicoes esta representado abaixo: \n");
		printBoard(boardRegra);
		return false;
	}	
}


int main(){
	
	int pos, player;
	bool turn = false;
	bool inicio = false;
	bool choosePlayer = false;
	
	while(inicio == false){
		inicio = iniciaJogo();
	}
	
	while(choosePlayer == false){
		printf("O jogador que ira iniciar quer ser X ou O? 1 para X ou 2 para O: ");
		scanf("%d", &player);
		if(player==1 || player==2){
			choosePlayer = true;
		}	
	}

	
	if(player == 1){
		turn = false;
	}
	if(player == 2){
		turn = true;
	}

	printBoard(board);

	
	while(finish == 0){
		pos = pedeJogada(turn);
		atualizaBoard(pos, turn);
		printBoard(board);
		finish = verificaJogo(board);
		turn =	!turn;	
	}	
	return 0;
}
