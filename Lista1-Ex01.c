#include <stdio.h>

int main(){
	int h, m, s, segTotal;
	
	
	h = 0;
	m = 0;
	s = 0;
	segTotal = 0;
	
	printf("Entre com o valor das horas:\n");
	scanf("%d", &h);
	printf("Entre com o valor dos minutos:\n");
	scanf("%d", &m);
	printf("Entre com o valor dos segundos:\n");
	scanf("%d", &s);
	
	segTotal = 3600*h + 60*m + s;
	
	printf("O total de segundos eh: %d", segTotal);
	
	return 0;
}
