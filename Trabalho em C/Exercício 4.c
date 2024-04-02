#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

void abertura()
{
	printf("********************\n");
	printf("*CADASTRO DE FRUTAS*\n");
	printf("********************\n\n");
}

typedef struct
{

	char nome[100];
	float valor;
	float peso;
	bool refrigerar;
	int dia, mes, ano;

} cdstr;

int main()
{

	setlocale(LC_ALL, "Portuguese");

	int n, i;

	float pmin, pmax;

	char resp, busca[100], *res;

	abertura();

	printf("Quantas frutas deseja cadastrar: ");
	scanf("%d", &n);

	cdstr cadastro[n];

	system("cls");

	for (i = 0; i < n; i++)
	{
		abertura();
		printf("VO�E EST� CADASTRANDO A %d FRUTA DE %d\n\n", i + 1, n);
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
		printf("A fruta precisa de refrigera��o? (0 - N�o/ 1 - Sim): ");
		scanf("%d", &cadastro[i].refrigerar);
		system("cls");
	}

	abertura();

	fflush(stdin);

	for (i = 0; i < n; i++)
	{
		printf("\nFRUTAS CADASTRADAS %d DE %d\n", i + 1, n);
		printf("\nNome da fruta: %s\n", cadastro[i].nome);
		printf("Valor do/a %s: %.2f R$\n", cadastro[i].nome, cadastro[i].valor);

		if (cadastro[i].peso > 999)
		{
			printf("Peso do/a %s: %.2f Kg\n", cadastro[i].nome, cadastro[i].peso);
		}
		else
		{
			printf("Peso do/a %s: %.2f g\n", cadastro[i].nome, cadastro[i].peso);
		}

		printf("Validade do/a %s: %02d/%02d/%04d\n", cadastro[i].nome, cadastro[i].dia, cadastro[i].mes, cadastro[i].ano);

		if (cadastro[i].refrigerar)
		{
			printf("O/a %s precisa de refrigera��o? : Sim\n", cadastro[i].nome);
		}
		else
		{
			printf("O/a %s precisa de refrigera��o? : N�o\n", cadastro[i].nome);
		}
	}

	printf("\n\nDeseja vizualizar alguma faixa de pre�o espec�fica? (s/n): ");
	scanf(" %c", &resp);

	if (resp == 's')
	{
		printf("\n\nQual faixa de pre�o que gostaria de ver??\n");
		printf("Digite o valor MINIMO: ");
		scanf("%f", &pmin);
		printf("\nDigite o valor MAXIMO: ");
		scanf("%f", &pmax);

		for (i = 0; i < n; i++)
		{
			if (cadastro[i].valor >= pmin && cadastro[i].valor <= pmax)
			{
				printf("\nMOSTRANDO VALORES NA FAIXA DE PRECO DE %.2f A %.2f:\n", pmin, pmax);
				printf("\nNome da fruta: %s\n", cadastro[i].nome);
				printf("Valor do/a %s: %.2f R$\n", cadastro[i].nome, cadastro[i].valor);

				if (cadastro[i].peso > 999)
				{
					printf("Peso do/a %s: %.2f Kg\n", cadastro[i].nome, cadastro[i].peso);
				}
				else
				{
					printf("Peso do/a %s: %.2f g\n", cadastro[i].nome, cadastro[i].peso);
				}

				printf("Validade do/a %s: %02d/%02d/%04d\n", cadastro[i].nome, cadastro[i].dia, cadastro[i].mes, cadastro[i].ano);

				if (cadastro[i].refrigerar)
				{
					printf("O/a %s precisa de refrigera��o? : Sim\n", cadastro[i].nome);
				}
				else
				{
					printf("O/a %s precisa de refrigera��o? : Não\n", cadastro[i].nome);
				}
			}
		}
	}

	printf("\n\nDigite uma busca: ");
	fflush(stdin);
	fgets(busca, 100, stdin);
	
	system("cls");
	
	busca[strcspn(busca, "\n")] = '\0';

	bool encontrado = false;

	for (i = 0; i < n; i++)
	{
		res = strstr(cadastro[i].nome, busca);

		if (res != NULL)
		{
			printf("\nOs nomes correspondentes s�o: %s\n", cadastro[i].nome);
			encontrado = true;
		}
	}

	if (!encontrado)
	{
		printf("Nenhum resultado encontrado.\n");
	}

	return 556;
}
