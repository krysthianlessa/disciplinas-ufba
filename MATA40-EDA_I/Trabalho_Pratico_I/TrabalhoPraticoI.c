#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 11

typedef struct NoFuncionario{
	char nome[20];
	int numid;
	char depart[30];
	float salario;
	struct NoFuncionario *prox;
} NoFuncionario, *Funcionario;

void inicializa (Funcionario *l);
_Bool consulta (Funcionario *l, NoFuncionario *x);
_Bool insere (Funcionario *l, NoFuncionario *x);
void retira (Funcionario *l, int x);
void ordemcod (Funcionario *l, int i, int x);
void ordemnome (Funcionario *l, int x);
int contarfuncio (Funcionario *l);


int main() {
	Funcionario VetListas[N];
	char entrada;
	
	inicializa (VetListas);
	scanf ("%c", &entrada);
	while (entrada != 'e'){
		if (entrada == 'c'){ 
			NoFuncionario ConsFunc;
						
			scanf ("%d", &ConsFunc.numid);
			if (consulta (VetListas, &ConsFunc)){
				printf ("%s\n", ConsFunc.nome);
				printf ("%d\n", ConsFunc.numid);
				printf ("%s\n", ConsFunc.depart);
				printf ("%.2f\n", ConsFunc.salario);
			}
		}
		if (entrada == 'i'){ 
			int i, QtFunc;
			
			scanf ("%d", &QtFunc);
			for (i=0; i!=QtFunc; i++){
				NoFuncionario NovoFunc;
				
				scanf ("%s", NovoFunc.nome);
				scanf ("%d", &NovoFunc.numid);
				scanf ("%s", NovoFunc.depart);
				if (strcmp(NovoFunc.depart , "adm")==0)
					strcpy(NovoFunc.depart, "administrativo");
				if (strcmp(NovoFunc.depart , "ped")==0)
					strcpy(NovoFunc.depart, "pesquisa-e-desenvolvimento");
				if (strcmp(NovoFunc.depart , "prod")==0)
					strcpy(NovoFunc.depart, "producao");
				scanf ("%f", &NovoFunc.salario);	
				insere(VetListas, &NovoFunc);
			}
		}
		if (entrada == 'r'){ 
			int x;
			
			scanf ("%d", &x);
			retira (VetListas, x);
		}
		if (entrada == 'l'){ 
			NoFuncionario *p;
			int ind, cont=0;
			
			scanf ("%d", &ind);
			for (p=VetListas[ind]; p!=NULL; p=p->prox, cont++);
			ordemcod (VetListas, ind, cont);
		}
		if (entrada == 'o'){ 
			int QtFunc = contarfuncio (VetListas);
			
			ordemnome (VetListas, QtFunc);			
		}
		
		scanf ("%c", &entrada);
	}
		
	return 0;
}

void inicializa (Funcionario *l){
	int i;
	
	for (i=0; i<N; i++)
		l[i]= NULL;
}

_Bool consulta (Funcionario *l, NoFuncionario *x){
	NoFuncionario *p;
	int i = x->numid % N;
	
	for (p=l[i]; (p!=NULL)&&(p->numid!=x->numid); p=p->prox);
	if (p==NULL)
		return false;
	strcpy(x->nome, p->nome);
	strcpy(x->depart, p->depart);
	x->salario = p->salario;
	return true;
}

_Bool insere (Funcionario *l, NoFuncionario *x){
	NoFuncionario *p;
	int i = x->numid % N;
	
	if ((consulta(l,x))||(!(p=(NoFuncionario*)malloc(sizeof(NoFuncionario)))))
		return false;
	strcpy(p->nome, x->nome);
	p->numid = x->numid;
	strcpy(p->depart, x->depart);
	p->salario = x->salario;
	p->prox = l[i];
	l[i] = p;
	return true;
}

void retira (Funcionario *l, int x){
	NoFuncionario *p, *q;
	int i = x%N;
	
	for (p=l[i], q=NULL;(p) && (p->numid != x); q=p, p=p->prox);
	if (p){
		if (!q)
			l[i] = p->prox;
		else
			q->prox = p->prox;
		free (p);
	}
}	

void ordemcod (Funcionario *l, int i, int x){
	NoFuncionario *p;
	int chave, n, j=0, VetIds[x];
	
	for (p=l[i]; p!=NULL; p=p->prox){
		VetIds[j]= p->numid;
		j++;
	}
	for (j=1; j<x; j++){
		chave = VetIds[j];
		n = j-1;
		while ((n>=0) && (chave < VetIds[n])){
			VetIds[n+1] = VetIds[n];
			n--;
		}
		VetIds[n+1]=chave;
	}
	for (j=0; j<x; j++)
		printf ("%d\n", VetIds[j]);
}

void ordemnome (Funcionario *l, int x){
	NoFuncionario *p;
	char ord, VetNomes[x][20], chave[20];
	int i, a=0;
	
	for (i=0; i < N; i++)
		for (p=l[i]; p!=NULL; p=p->prox){
			strcpy (VetNomes[a], p->nome);
			a++;
		}
		
	for (i=1; i<x; i++){
		strcpy (chave, VetNomes[i]);
		a = i-1;
		while ((a>=0) && (strcmp (VetNomes[a], chave)>0)){
			strcpy (VetNomes[a+1], VetNomes[a]);
			a--;
		}
		strcpy (VetNomes[a+1], chave);
	}
		
	scanf ("\n%c", &ord);
	if (ord == 'c'){
	for	(i=0; i < x; i++)
		printf ("%s\n", VetNomes[i]);
	}
	if (ord == 'd'){
		for	(i=x-1; i >= 0 ; i--)
			printf ("%s\n", VetNomes[i]);
	}
}

int contarfuncio (Funcionario *l){
	NoFuncionario *p;
	int i, cont=0;
	
	for (i=0; i < N; i++)
		for (p=l[i]; p!=NULL; p=p->prox, cont++);
	return cont;
}		
