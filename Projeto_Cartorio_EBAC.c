#include <stdio.h> //Biblioteca de Comunicação com o Usuário
#include <stdlib.h> //Biblioteca de Alocação de Espaço em Memória
#include <locale.h> //Biblioteca de Alocações de Texto por Região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis
	
	printf("\nDigite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se às strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo - "w" significa escrever (write)
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ": Nome - ");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, "; Sobrenome - ");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, "; Cargo - ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nCPF Não Cadastrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	   
	printf("\nDigite o CPF do usuário à ser deletado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nUsuário Não Encontrado!\n\n");
		system("pause");
				
	}

	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("\nUsuário Deletado!\n\n");
			system("pause");
		}
	}

	fclose(file);

}

int main()
{			
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	int opcao=0; //Definindo Variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório EBAC ###\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
			
		printf("\n\n\t\t ### Seja Bem Vindo ao Cartório da EBAC! ###\n\n\n"); //Início do Menu
		printf("\t     ...este Software® foi reproduzido por um dos alunos...\n\n\n\n");
		printf("\t - Selecione a Opção Desejada:\n\n");
		printf("\t 1. Registrar Nomes,\n");
		printf("\t 2. Consultar Nomes,\n");
		printf("\t 3. Deletar   Nomes,\n");
		printf("\t 4. Sair.\n\n");
		printf("\tOpção: ");//Fim do Menu
		
		scanf("%d", &opcao);//Armazenando a Escolha do Usuário
		
		system("cls"); //responsável por limpar a tela
		
		switch(opcao)//Início da Seleção do menu
			{
				case 1:
				registro();//chamada de funções
				break;
			
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("\nOpção Não Disponível.\n\n");
				system("pause");
				break;
							
			}//Fim da Seleção	
		}
	}
	
	else
	printf("Senha incorreta!");
	
}
