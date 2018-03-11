/*
 
 Para : Professor Carlos Eduardo - FRB 2016

 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese");
    void acessarFile1(FILE *arquivo_copia,float copia_massa);
    void acessarFile2(FILE *arquivo_copia,int copia_idade);
    void acessarFile3(FILE *arquivo_copia,char copia_nome[100],char copia_sexo,int j_copia);
    void definirEstado(char copia_sexo,float copia_imc);

    // DeclaraÃ§Ã£o das variÃ¡veis
    FILE *Arquivo; // cria variÃ¡vel ponteiro para o arquivo
     int i, j;
     printf("Quantas Pessoas você quer calcular o 'IMC': ");

    scanf("%d", &i);
    
    printf("\n\n");
    struct Cadastrar { // struct para cadastrar as informaÃ§Ãµes necessarias do usuario;
        char nome[100];
        float peso ;
        float altura;
        int idade;
        char sexo;
        float imc; // obtem a massa corporea em uma variÃ¡vel;
    };
    struct Cadastrar pessoas[i];
   

   
    
    for (j = 0; j < i; j++) { // LOOPING PARA CALCULAR QUANTAS PESSOAS O USUARIO PEDIU
        #ifdef _WIN32
        fflush(stdin);
        #endif

        #ifdef __linux__
        __fpurge(stdin);
        #endif
        printf("INFORME O NOME DA %dº PESSOA:\n",j+1);
        gets(pessoas[j].nome); // guarda o nome da pessoa com base na valor do looping



        printf("Sexo: M-masculino ou F-feminino\n");

        #ifdef _WIN32
        fflush(stdin);
        #endif

        #ifdef __linux__
        __fpurge(stdin);
        #endif

        scanf("%c", &pessoas[j].sexo); // guarda o sexo da pessoa com base na valor do looping
        
            // chama metodo para jogar no Arquivo
        acessarFile3(Arquivo,pessoas[j].nome,pessoas[j].sexo,(j+1));

        #ifdef _WIN32
        fflush(stdin);
        #endif

        #ifdef __linux__
        __fpurge(stdin);
        #endif

        printf("Qual o peso da pessoa:\n");
        scanf("%f",&pessoas[j].peso);
         
        printf("Qual a altura da pessoa:\n");
        scanf("%f",&pessoas[j].altura); 
        // guarda o nome da pessoa com base na valor do looping

        pessoas[j].imc =(pessoas[j].peso/(pessoas[j].altura*pessoas[j].altura));
            // chama metodo para jogar no Arquivo dnv
        acessarFile1(Arquivo,pessoas[j].imc);
        
        #ifdef _WIN32
        fflush(stdin);
        #endif

        #ifdef __linux__
        __fpurge(stdin);
        #endif
        printf("Qual a idade da pessoa\n");

        scanf("%d",&pessoas[j].idade); // guarda o nome da pessoa com base na valor do looping
        acessarFile2(Arquivo,pessoas[j].idade);

        printf("\n\n");
        printf("IMC DE %s é %.1f\n",pessoas[j].nome,pessoas[j].imc);
        definirEstado(pessoas[j].sexo,pessoas[j].imc);
        
        printf("Pessoa cadastrada com sucesso!\n\n");
        #ifdef _WIN32
        system("pause");
        system("cls");
        #endif

        #ifdef __linux__
        getchar();
        system("clear");
        #endif
    }
    printf("\t-------Create by----------\n");
    printf("\tLuiz Eduardo(161052088)\n");
   
    system("pause");
    
    return (0);
}

void acessarFile3(FILE *arquivo_copia,char copia_nome[100],char copia_sexo,int j_copia) {
    //abrindo o arquivo com 'write' w

    arquivo_copia = fopen("Arquivo.txt", "a");

    //testando se o arquivo foi realmente criado
    if (arquivo_copia == NULL) {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }


    fprintf(arquivo_copia,"CADASTRO DA %dº PESSOA\n\n",j_copia);
    //usando fprintf para armazenar para escrever no arquivo
    fprintf(arquivo_copia, "NOME: %s\nSEXO: %c\n",copia_nome,copia_sexo);

    //usando fclose para fechar o arquivo
    fclose(arquivo_copia);



}
void acessarFile2(FILE *arquivo_copia,int copia_idade) { // SOBREESCREVER PARAMETRO PARA INT
    //abrindo o arquivo com 'write' w
    arquivo_copia = fopen("Arquivo.txt", "a");

    //testando se o arquivo foi realmente criado
    if (arquivo_copia == NULL) {
        printf("Erro na abertura do arquivo!");
       exit(0);
    }



    //usando fprintf para armazenar para escrever no arquivo
    fprintf(arquivo_copia, "IDADE : %d\n",copia_idade);
    fprintf(arquivo_copia, "-----------------------");
    fprintf(arquivo_copia, "\n\n");
    //usando fclose para fechar o arquivo
    fclose(arquivo_copia);



}
void acessarFile1(FILE *arquivo_copia,float copia_massa) { // SOBREESCREVER PARAMETRO PARA FLOAT
    //abrindo o arquivo com 'write' w
    arquivo_copia = fopen("Arquivo.txt", "a");

    //testando se o arquivo foi realmente criado
    if (arquivo_copia == NULL) {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }



    //usando fprintf para armazenar para escrever no arquivo
    fprintf(arquivo_copia, "IMC: %.1f\n",copia_massa);

    //usando fclose para fechar o arquivo
    fclose(arquivo_copia);



}
void definirEstado(char copia_sexo,float copia_imc){

if(copia_sexo == 'm' || copia_sexo == 'M'){
	if(copia_imc <= 20.7){
	printf("Abaixo do peso\n");
	}else if(copia_imc > 20.7 && copia_imc <= 26.4){
	printf("No peso ideal\n");
	}else if(copia_imc > 26.4 && copia_imc <= 27.8){
	printf("Um pouco acima do peso\n");
	}else if(copia_imc > 27.8 && copia_imc <= 31.1){
	printf("Acima do peso\n");
	}else{
	printf("Obeso\n");
	}
}else if(copia_sexo == 'f' || copia_sexo == 'F'){
	if(copia_imc <= 19.1){
	printf("Abaixo do peso\n");
	}else if(copia_imc > 19.1 && copia_imc <= 25.8){
	printf("No peso ideal\n");
	}else if(copia_imc > 25.8 && copia_imc <= 27.3){
	printf("Um pouco acima do peso\n");
	}else if(copia_imc > 27.3 && copia_imc <= 32.3){
	printf("Acima do peso\n");
	}else{
	printf("Obeso\n");
	}
}else{
    printf("Incapaz de calcular o IMC\n");
}

}
