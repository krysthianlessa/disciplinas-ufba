#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoFilaInt{
	int chave;
	struct NoFilaInt *prox;
}NoFilaInt;

typedef struct {
	NoFilaInt *prim, *ult;
} FilaInt;

void inicializa (FilaInt *f);
_Bool enfileira (FilaInt *f, int x);
_Bool desenfileira (FilaInt *f, int *x);

int main(){
	FilaInt Fila;
	int parada = 9;
	
	while (parada != 0){
		printf ("\n1. Inicializar Fila\n");
		printf ("2. Enfileirar Fila\n");
		printf ("3. Desenfileirar Fila\n");
		printf ("4. Imprimir Fila\n\n");
		printf ("Digite sua opcao: ");
		scanf ("%d", &parada);
		
		if (parada==1){
			inicializa (&Fila);
			printf ("Fila iniciada.\n");
		}
		if (parada==2){
			int numero;
			
			printf ("Digite o número para enfileirar: ");
			scanf ("%d", &numero);
			if (enfileira (&Fila, numero))
				printf ("Sucesso na insercao de %d.\n", numero);
			else
				printf ("Erro na insercao de %d.\n", numero);
		}
		if (parada==3){
			int numero;
			
			if (desenfileira (&Fila, &numero))
				printf ("Sucesso na retirada. Numero retirado: %d.\n", numero);
			else
				printf ("Erro na retirada.");
		}	
	}
	return 0;
}

void inicializa (FilaInt *f){
	f->prim = NULL;
}

_Bool enfileira (FilaInt *f, int x){
	NoFilaInt *p;
	
	if (!(p=(NoFilaInt *)malloc(sizeof(NoFilaInt))))
		return false;
	p->chave = x;
	p->prox = NULL;
	if (f->prim)
		f->ult->prox = p;
	else
		f->prim = p;
	f->ult = p;
	return true;
}

_Bool desenfileira (FilaInt *f, int *x){
	NoFilaInt *p;
	
	if (!(p=f->prim))
		return false;
	f->prim = p->prox;
	*x = p->chave;
	free (p);
	return true;
}
