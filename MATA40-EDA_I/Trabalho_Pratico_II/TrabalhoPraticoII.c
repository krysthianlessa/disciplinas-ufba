#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NoArvore {
	int chave;
	struct NoArvore *fdir, *fesq;
}NoArvore, *Arvore;

void inicializa (Arvore *k);
_Bool consulta (Arvore k, int x);
void insere (Arvore *k, int x);
void retira (Arvore *k, int x);
void imprime (Arvore k);
void listaemordem (Arvore k, char x);
void imprimenivel(Arvore k, int x, int i);	

int main(){
	Arvore raiz;
	char entrada;
	int cont = 1;
	
	inicializa (&raiz);
	while (entrada != 'e'){
		scanf ("%c", &entrada);
		if (entrada == 'c'){
			int numero;
			
			scanf ("%d", &numero);
			if (consulta (raiz, numero))
				printf ("existe no com chave: %d\n", numero);
			else
				printf ("nao existe no com chave: %d\n", numero);
		}
		if (entrada == 'i'){
			int numero;
			
			scanf ("%d", &numero);
			insere (&raiz, numero);
		}
		if (entrada == 'r'){
			int numero;
			
			scanf ("%d", &numero);
			retira (&raiz, numero);
		}
		if (entrada == 'd')
			imprime (raiz);
		if (entrada == 'p'){
			char ordem;
			
			scanf (" %c", &ordem);
			listaemordem(raiz, ordem);
		}
		if (entrada == 'n'){
			int nivel;
			
			scanf (" %d", &nivel);
			imprimenivel (raiz, nivel, cont);
		}
	}
	return 0;
}

void inicializa (Arvore *k){
	*k = NULL;
}

_Bool consulta (Arvore k, int x){
	NoArvore *w;
	
	w = k;
	while ((w != NULL) && (x != w->chave)){
		if (x < w->chave)
			w = w->fesq;
		else
			w = w->fdir;
	}
	if (w==NULL)
		return false;
	return true;
}

void insere (Arvore *k, int x){
	
	if(*k == NULL) {
    	NoArvore *z;
    	if (!(z=(NoArvore *)malloc(sizeof(NoArvore))))
			return;
    	z->chave = x;
    	z->fdir = z->fesq = NULL;
    	*k = z;
    	return;
	}
	if(x < (*k)->chave) {
    	insere (&(*k)->fesq, x);
    	return;
	}
	if(x > (*k)->chave) {
    	insere (&(*k)->fdir, x);
    	return;
	}
}

NoArvore *DoisFilhos(NoArvore *root){
    	if(root==NULL)
        	return NULL;
    	else if(root->fesq == NULL)
            	return root;
    	else
        	return DoisFilhos(root->fesq);
}

void retira (Arvore *k, int x){
	
	if (x < (*k)->chave)
		retira (&(*k)->fesq, x);
	else if (x > (*k)->chave)
		retira (&(*k)->fdir, x);
	else if ((*k)->fesq != NULL && (*k)->fdir != NULL){
		NoArvore *z = NULL;
		z = DoisFilhos ((*k)->fdir);
		(*k)->chave = z->chave;
		retira (&(*k)->fdir, (*k)->chave);
	}
	else {
		NoArvore *z = (*k);
		if ((*k)->fesq == NULL)
			(*k) = (*k)->fdir;
		else
			(*k) = (*k)->fesq;
		free (z);	
	}
}

void imprime (Arvore k){
	
	if (k == NULL)
		return;
	imprime (k->fesq);
	if (k->fesq != NULL && k->fdir != NULL)
		printf ("chave: %d fesq: %d fdir: %d\n", k->chave, k->fesq->chave, k->fdir->chave);
	if (k->fesq == NULL && k->fdir == NULL)
		printf ("chave: %d fesq: nil fdir: nil\n", k->chave);
	if (k->fesq != NULL && k->fdir == NULL)
		printf ("chave: %d fesq: %d fdir: nil\n", k->chave, k->fesq->chave);
	if (k->fesq == NULL && k->fdir != NULL)
		printf ("chave: %d fesq: nil fdir: %d\n", k->chave, k->fdir->chave);
	imprime	(k->fdir);
}

void listaemordem (Arvore k, char x){
	
	if (k == NULL)
		return;
	if (x == 'c'){
		listaemordem (k->fesq, x);
		printf ("%d\n", k->chave);
		listaemordem (k->fdir, x);
	}
	if (x == 'd'){
		listaemordem (k->fdir, x);
		printf ("%d\n", k->chave);
		listaemordem (k->fesq, x);
	}
}

void imprimenivel(Arvore k, int x, int i){
	if(k != NULL && i <= x){
		imprimenivel (k->fesq, x, i+1);
		if(i == x)
			printf("%d\n", k->chave);	
		imprimenivel (k->fdir, x, i+1);
	}
}
