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
	
	FILE *file; 
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); 
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
    return 0;
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	char c[40], nome[40], sobrenome[40], cargo[40];

	printf("Digite o CPF para consulta: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL) {
		printf("CPF não encontrado!\n");
	} else {
		fgets(conteudo, 200, file);
		fclose(file);

		// Separando os campos por vírgula e exibindo com rótulos
		sscanf(conteudo, "%[^,],%[^,],%[^,],%s", c, nome, sobrenome, cargo);

		printf("CPF: %s\n", c);
		printf("Nome: %s\n", nome);
		printf("Sobrenome: %s\n", sobrenome);
		printf("Cargo: %s\n", cargo);
	}

	system("pause");
	return 0;
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	system("pause");	
	return 0;
}

int main()
{
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");

		setlocale(LC_ALL, "Portuguese"); 
			
		printf("### Cartorio da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");
				
		scanf("%d", &opcao); 
		
		system("cls");
	
		switch(opcao) 
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} 	
	}	
}

