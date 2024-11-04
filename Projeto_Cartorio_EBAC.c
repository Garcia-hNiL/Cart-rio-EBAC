#include <stdio.h> //Biblioteca de Comunica��o com o Usu�rio
#include <stdlib.h> //Biblioteca de Aloca��o de Espa�o em Mem�ria
#include <locale.h> //Biblioteca de Aloca��es de Texto por Regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis
	
	printf("\nDigite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se �s strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo - "w" significa escrever (write)
	fprintf(file, cpf); //salva o valor da vari�vel
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
		printf("\nCPF N�o Cadastrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio ");
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
	   
	printf("\nDigite o CPF do usu�rio � ser deletado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nUsu�rio N�o Encontrado!\n\n");
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
			printf("\nUsu�rio Deletado!\n\n");
			system("pause");
		}
	}

	fclose(file);

}

int main()
{			
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio EBAC ###\n\n");
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
			
		printf("\n\n\t\t ### Seja Bem Vindo ao Cart�rio da EBAC! ###\n\n\n"); //In�cio do Menu
		printf("\t     ...este Software� foi reproduzido por um dos alunos...\n\n\n\n");
		printf("\t - Selecione a Op��o Desejada:\n\n");
		printf("\t 1. Registrar Nomes,\n");
		printf("\t 2. Consultar Nomes,\n");
		printf("\t 3. Deletar   Nomes,\n");
		printf("\t 4. Sair.\n\n");
		printf("\tOp��o: ");//Fim do Menu
		
		scanf("%d", &opcao);//Armazenando a Escolha do Usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)//In�cio da Sele��o do menu
			{
				case 1:
				registro();//chamada de fun��es
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
				printf("\nOp��o N�o Dispon�vel.\n\n");
				system("pause");
				break;
							
			}//Fim da Sele��o	
		}
	}
	
	else
	printf("Senha incorreta!");
	
}
