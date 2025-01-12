#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro()// Fun��o respon�vel por cadastrar usu�rio
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");// coletando informa��o do usu�rio.
	scanf("%s", cpf); //%s refer-se armazenar strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo; W significa escrever write
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//atualizar informa��o A entre aspas
	fprintf(file,","); //criando virgula aten��o virgula entre aspas Danielly
	fclose(file);//entao essas 3 linhas para separar as informa�oes com virgula.
	
	printf("Digite o nome a ser cadastrado: ");//criando nome usuario
	scanf("%s",nome);//salvando na string dado do usuario
	
	file = fopen(arquivo, "a");//aqui salvando, atualizando dado do usuario no ARQUIVO
	fprintf(file,nome);//salvando conteudo da variavel nome dentro do Arq.
	fclose(file);
	
	file = fopen(arquivo, "a");//NOVAMENTE...
	fprintf(file,",");//tudo separado por virgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//salvando SOBRENOME
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//VIRGULA NO SOBRENOME
	fprintf(file,",");//VIRGULA NO SOBRENOME
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//CARGO
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//fun��o para buscar aquivo e abrir 
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()//fun��o consultar dados usuarios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado:");//fun��o que pede o dado do usuario
	scanf("%s", cpf); //fun�o arquivo string, nesse caso o cpf
	
	FILE *file; //fun��o buscar arquivo
	file= fopen(cpf, "r"); //fun��o abrir o aquivo, nesse caso o cpf; e ler a fun��o "r"
	
	if(file == NULL)//se(if) o aquivo(file) for nulo ou inexistente(null)aten��o sinal de compara��o (==)
	{
		printf("n�o foi poss�vel abrir o aquivo, n�o localizado!. \n ");//resposta ao usuario
	}
		
	while(fgets(conteudo, 200, file) != NULL)//la�o de repetic�o(enquanto)buscar no arq.conteudo os 200caract	
	{
		printf("\n Essas s�o as informa��es do usu�rio:"); //salvando conteudo da variavel
		printf("%s", conteudo);//salva conteundo na string
		printf("\n\n");
	}
	
	system("pause"); //comando para pausar a tela na resposta
}

int deletar()//fun��o para deletar usuario
{
	
	
	char cpf[40];
	
	printf("digite o cpf do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system ("pause");
		
	}
		
}


	
int main()
	{
	int opcao=0; //Definindo vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //comando para limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema. \n\n"); 
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu�rio.
		
		system("cls");
	
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registro(); //chamada de fun�es
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utlizar os sistema!\n");
			return 0;
			break;
		
			default:
			printf("Essa opc�o n�o esta dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o.
			
	}	
}
