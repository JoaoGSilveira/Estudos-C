#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

void abertura(){
	printf("********************\n");
	printf("*CADASTRO DE FRUTAS*\n");
	printf("********************\n\n");
}

typedef struct{
	
	char nome[100];
	float valor;
	float peso;
	bool refrigerar;
	int dia, mes, ano;
	
}cdstr;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int n, i;
	
	abertura();
	
	printf("Quantas frutas deseja cadastrar: ");
	scanf("%d", &n);
	
	cdstr cadastro[n];
	
	system("cls");
	
	for(i=0; i<n; i++){
		abertura();
		printf("VOCÊ ESTÁ CADASTRANDO A %dª FRUTA DE %d\n\n", i+1, n);
		fflush(stdin);
		printf("Digite o nome da fruta: ");
		fgets(cadastro[i].nome, 100, stdin);
		cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';
		printf("Digite o valor da fruta: ");
		scanf("%f", &cadastro[i].valor);
		printf("Digite o peso da fruta: ");
		scanf("%f", &cadastro[i].peso);
		printf("Digite a validade da fruta (dd/mm/aaaa): ");
		scanf("%d%d%d", &cadastro[i].dia, &cadastro[i].mes, &cadastro[i].ano);
		printf("A fruta precisa de refrigeração (0 - não/ 1 - sim): ");
		scanf("%i", &cadastro[i].refrigerar);
		system("cls");
	}
	
	return 556;
}
