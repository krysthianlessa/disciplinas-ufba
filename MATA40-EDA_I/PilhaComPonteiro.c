#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilhaInt {
	int chave;
	struct NoPilhaInt *prox;
} NoPilhaInt;

typedef struct {
	NoPilhaInt *topo, *ultm;
} PilhaInt;

void inicializa (PilhaInt *p);
_Bool empilha (PilhaInt *p, int x);
_Bool desempilha (PilhaInt *p, int *x);
void imprpilha (PilhaInt *p);

int main(){
	PilhaInt Pilha;
	int parada = 9;
	
	while (parada != 0){
		printf ("\n1. Inicializar Pilha\n");
		printf ("2. Empilhar\n");
		printf ("3. Desempilhar\n");
		printf ("4. Imprimir Pilha\n\n");
		printf ("Digite sua opcao: ");
		scanf ("%d", &parada);
		
		if (parada==1){
			inicializa (&Pilha);
			printf ("Pilha iniciada.\n");
		}
		if (parada==2){
			int numero;
			
			printf ("Digite o número para empilhar: ");
			scanf ("%d", &numero);
			if (empilha (&Pilha, numero))
				printf ("Sucesso na insercao de %d.\n", numero);
			else
				printf ("Erro na insercao de %d. Nao ha espaço para alocar.\n", numero);
		}
		if (parada==3){
			int numero;
			
			if (desempilha (&Pilha, &numero))
				printf ("Sucesso na retirada. Numero retirado: %d.\n", numero);
			else
				printf ("Pilha vazia.\n");
		}
		if (parada==4)
			imprpilha (&Pilha);
	}
	return 0;
}

void inicializa (PilhaInt *p){
	p->topo = NULL;
}

_Bool empilha (PilhaInt *p, int x){
	NoPilhaInt *q;
	
	if (!(q=(NoPilhaInt*)malloc(sizeof(NoPilhaInt))))
		return false;
	q->chave = x;
	q->prox = p->topo;
	p->topo = q; 
	return true;
}

_Bool desempilha (PilhaInt *p, int *x){
	NoPilhaInt *q;
	
	if (!(q=p->topo))
		return false;
	p->topo = p->topo->prox;
	*x = q->chave;
	free (q);
	return true;
}


void imprpilha (PilhaInt *p){
	NoPilhaInt *q;
	
	for (q=p->topo; q; q = q->prox)
		printf ("%d\n", q->chave);
}
