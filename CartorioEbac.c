#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro()// Função responável por cadastrar usuário
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");// coletando informação do usuário.
	scanf("%s", cpf); //%s refer-se armazenar strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo; W significa escrever write
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//atualizar informação A entre aspas
	fprintf(file,","); //criando virgula atenção virgula entre aspas Danielly
	fclose(file);//entao essas 3 linhas para separar as informaçoes com virgula.
	
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
	
	file = fopen(arquivo, "a");//função para buscar aquivo e abrir 
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()//função consultar dados usuarios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado:");//função que pede o dado do usuario
	scanf("%s", cpf); //funão arquivo string, nesse caso o cpf
	
	FILE *file; //função buscar arquivo
	file= fopen(cpf, "r"); //função abrir o aquivo, nesse caso o cpf; e ler a função "r"
	
	if(file == NULL)//se(if) o aquivo(file) for nulo ou inexistente(null)atenção sinal de comparação (==)
	{
		printf("não foi possível abrir o aquivo, não localizado!. \n ");//resposta ao usuario
	}
		
	while(fgets(conteudo, 200, file) != NULL)//laço de repeticão(enquanto)buscar no arq.conteudo os 200caract	
	{
		printf("\n Essas são as informações do usuário:"); //salvando conteudo da variavel
		printf("%s", conteudo);//salva conteundo na string
		printf("\n\n");
	}
	
	system("pause"); //comando para pausar a tela na resposta
}

int deletar()//função para deletar usuario
{
	
	
	char cpf[40];
	
	printf("digite o cpf do usuário a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema!.\n");
		system ("pause");
		
	}
		
}


	
int main()
	{
	int opcao=0; //Definindo variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //comando para limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema. \n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário.
		
		system("cls");
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro(); //chamada de funões
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
			printf("Essa opcão não esta disponível!\n");
			system("pause");
			break;
		} //fim da seleção.
			
	}	
}
