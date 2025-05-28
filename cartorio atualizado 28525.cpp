#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <string.h> 

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); 
	
	FILE *file = fopen(arquivo, "w");
	if (file == NULL) {
		printf("Erro ao criar o arquivo!\n");
		return 1;
	}

	fprintf(file, "%s,", cpf);
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, "%s,", nome);
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file, "%s,", sobrenome);
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, "%s", cargo);
	fclose(file);	

	printf("Usu�rio cadastrado com sucesso!\n");

	printf("\nPressione qualquer tecla para voltar ao menu...");
	getchar(); // consome o \n
	getchar(); // espera o Enter

	return 0;
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	char c[40], nome[40], sobrenome[40], cargo[40];

	printf("Digite o CPF para consulta: ");
	scanf("%s", cpf);

	FILE *file = fopen(cpf, "r");

	if (file == NULL) {
		printf("CPF n�o encontrado!\n");
	} else {
		fgets(conteudo, 200, file);
		fclose(file);

		sscanf(conteudo, "%[^,],%[^,],%[^,],%s", c, nome, sobrenome, cargo);

		printf("\n--- Dados encontrados ---\n");
		printf("CPF: %s\n", c);
		printf("Nome: %s\n", nome);
		printf("Sobrenome: %s\n", sobrenome);
		printf("Cargo: %s\n", cargo);
	}

	printf("\nPressione qualquer tecla para voltar ao menu...");
	getchar(); getchar();

	return 0;
}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF para deletar: ");
	scanf("%s", cpf);

	if (remove(cpf) == 0) {
		printf("Registro deletado com sucesso!\n");
	} else {
		printf("Erro ao deletar. CPF n�o encontrado.\n");
	}

	printf("\nPressione qualquer tecla para voltar ao menu...");
	getchar(); getchar();

	return 0;
}

int main()
{
	int opcao = 0;
	int laco = 1;

	setlocale(LC_ALL, "Portuguese");

	while (laco == 1)
	{
		system("cls");

		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t0 - Sair\n\n");
		printf("Op��o: ");
		scanf("%d", &opcao);

		system("cls");

		switch (opcao)
		{
			case 1:
				registro(); // cadastra apenas um usu�rio e volta ao menu
				break;

			case 2:
				consulta();
				break;

			case 3:
				deletar();
				break;

			case 0:
				printf("Saindo do sistema...\n");
				laco = 0;
				break;

			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				printf("Pressione qualquer tecla para voltar ao menu...");
				getchar(); getchar();
				break;
		}
	}
	return 0;
}

