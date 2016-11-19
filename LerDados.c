#include <stdio.h>
#include <stdlib.h>

int main (void){
FILE *Arquivo; // declaração do ponteiro arquivo

Arquivo = fopen("Arquivo.txt","r");
char palavra[1000];
if(Arquivo == NULL){
    printf("Arquivo n�o encontrado!\n");
    system("pause");
    exit(0);
}

while((fgets(palavra,1000,Arquivo)) != NULL){
printf("%s",palavra);
}
system("pause");
return 0;
}
