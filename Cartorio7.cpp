#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o - inser��o de assentos e caracteres de cada local
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registro()//funcao responsavel por cadastrar usuarios no sistema
{
	//inicio de criacao de variaveis/strings
	char arquivo[40]; //cria��o da vari�vel arquivo com at� 40 caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando info do usuario
	scanf("%s", cpf); //escaneia a string 
	
	strcpy(arquivo, cpf);//como o nome do arquivo vai ser o cpf, copiou-se o cpf na variavel do arquivo. strcpy � repons�vel por copiar os valores das strings
	
	FILE *file; //chamando o programa pra achar o FILE (fun��o que j� est� pronta pelo sistema) em algum lugar do computador para criar o arquivo file. O conjunto da linha cria o arquivo no banco de dados, que aqui � o computador
	file = fopen(arquivo, "w");	//agora aqui a gente fala do que o file � composto. fopen aber arquivos
	fprintf(file, cpf); //fprintf est� salvando algo dentro do arquivo - salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" � pra atualizar o arquivo e n�o criar um novo
	fprintf(file,","); //coloca uma virgula dentro do arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//linhas 46 a 49 para colocar outra virgula no arquivo 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //indica��o de que o nosso idioma ser� o portugu�s
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" de ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //fget quer dizer "buscar no arquivo"
	{
		printf("\nEssas s�o as informa��es do usus�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
			
	}
			
}


int main () //os parentesis indicam que � uma fun��o
{
	int opcao=0; //foi colocado valor 0 para atribuir um lugar na mem�rio. Significa que ela n�o est� livre. Estamos definindo as vari�veis

	int laco=1;
	
	for(laco=1; laco=1;)
	
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //indica��o de que o nosso idioma ser� o portugu�s

		printf("### Cart�rio da EBAC ###\n\n"); // \n � pra pular linha e ";" � pra encerrar o comando. Aqui � o in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n"); //o \t d� um certo espa�o do in�cio da linha	
		printf("\t3 - Deletar nomes\n"); 
		printf("Op��o: ");//tanto faz usar um s� ou v�rios printf. Aqui � o fim do menu

		scanf("%d", &opcao); // scanf vai escanear o que a pessoa escreveu e, nesse caso, armazenar escolha do usu�rio na variavel opcao atrav�s do %d
	
		system("cls"); //sistema vai apagar a tela que havia antes
		
		switch(opcao)
		
		{
			case 1:
			registro();
			break; //encerra o case1
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
				
				
		}
	}
}
	
