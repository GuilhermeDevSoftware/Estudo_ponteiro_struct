#include<stdio.h>
#include<malloc.h>


typedef struct {
	char nome[30];
	struct No * outro;
}No;

void mostra(No pessoa){
	printf("\nMeu nome eh: %s", pessoa.nome);
	if(pessoa.outro != NULL){
		No * amigo = (No*) pessoa.outro;
		printf(" e meu amigo eh: %s", amigo->nome);
	}
}

int main(){
	No pessoa1 = {"Guilherme", NULL};
	No pessoa2 = {"Silvia", NULL};
	No pessoa3 = {"Gabriel", NULL};
    No pessoa4 = {"Wesley", NULL};
	
	pessoa1.outro = (struct No*) &pessoa2;
	pessoa2.outro = (struct No*) &pessoa3;
	pessoa3.outro = (struct No*) &pessoa1;
    pessoa4.outro = (struct No*) &pessoa2;
	
	mostra(pessoa1);
	mostra(pessoa2);
	mostra(pessoa3);
    mostra(pessoa4);
	
	return 0;
}