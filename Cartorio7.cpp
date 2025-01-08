#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocações de texto por região - inserção de assentos e caracteres de cada local
#include <string.h>//biblioteca responsável por cuidar das strings

int registro()//funcao responsavel por cadastrar usuarios no sistema
{
	//inicio de criacao de variaveis/strings
	char arquivo[40]; //criação da variável arquivo com até 40 caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando info do usuario
	scanf("%s", cpf); //escaneia a string 
	
	strcpy(arquivo, cpf);//como o nome do arquivo vai ser o cpf, copiou-se o cpf na variavel do arquivo. strcpy é reponsável por copiar os valores das strings
	
	FILE *file; //chamando o programa pra achar o FILE (função que jã está pronta pelo sistema) em algum lugar do computador para criar o arquivo file. O conjunto da linha cria o arquivo no banco de dados, que aqui é o computador
	file = fopen(arquivo, "w");	//agora aqui a gente fala do que o file é composto. fopen aber arquivos
	fprintf(file, cpf); //fprintf está salvando algo dentro do arquivo - salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" é pra atualizar o arquivo e não criar um novo
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
	setlocale(LC_ALL, "Portuguese"); //indicação de que o nosso idioma será o português
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" de ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //fget quer dizer "buscar no arquivo"
	{
		printf("\nEssas são as informações do ususário: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
			
	}
			
}


int main () //os parentesis indicam que é uma função
{
	int opcao=0; //foi colocado valor 0 para atribuir um lugar na memório. Significa que ela não está livre. Estamos definindo as variáveis

	int laco=1;
	
	for(laco=1; laco=1;)
	
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //indicação de que o nosso idioma será o português

		printf("### Cartório da EBAC ###\n\n"); // \n é pra pular linha e ";" é pra encerrar o comando. Aqui é o início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n"); //o \t dá um certo espaço do início da linha	
		printf("\t3 - Deletar nomes\n"); 
		printf("Opção: ");//tanto faz usar um só ou vários printf. Aqui é o fim do menu

		scanf("%d", &opcao); // scanf vai escanear o que a pessoa escreveu e, nesse caso, armazenar escolha do usuário na variavel opcao através do %d
	
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
			printf("Essa opção não está disponível!\n");
			system("pause");
				
				
		}
	}
}
	
