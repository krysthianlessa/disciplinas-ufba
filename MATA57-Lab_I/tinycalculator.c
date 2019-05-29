#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int verifstr(char *str)
{
	int indic; int testeletra=0; int testenumero=0; int aux=0;
	for(indic=0;(str[indic]!='\0');indic++){
		if(str[indic]>=97 && str[indic]<=122)
			testeletra=1;
		else {
			if((str[indic]>=48 && str[indic]<=57) || (str[indic]==45) || (str[indic]==46))
			testenumero=1;
			else {
				aux=1;
				break;
			}
		}
	}
	
	if(testeletra==1 && testenumero!=1 && aux!=1)
		return 0;
	else if(testenumero==1 && testeletra!=1 && aux!=1)
		return 1;
	else 
		return 2;
}

void stod(char *valor , int *indic , char **vetvar , float *valvar , float *acum)
{
	int i;
	if (strlen(valor)>32)
		printf("ERR: nome de variavel invalido\n");
	else{
		for(i=0; valor[i]!='\0'; i++)
			vetvar[*indic][i]=valor[i];
		
		valvar[*indic]=*acum;	
		vetvar[*indic][i]='\0';
		*indic+=1;
	}
}

void set(char *valor , char **matvar , float *valvar , float *acum, int tamvetor)
{
	int indic;
	
	if(verifstr(valor)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(valor, matvar[indic])==0){
				*acum=valvar[indic];
				break;
			} else if ((strcmp(valor, matvar[indic])!=0)&&(indic==tamvetor))
				printf("ERR: Variavel nao definida\n");
		}	
	} 
	else
		*acum=atof(valor);
}

void add(char *valor , char **matvar , float *valvar , float *acum, int tamvetor)
{
	int indic;
	
	if(verifstr(valor)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(valor, matvar[indic])==0){
				*acum=(*acum + valvar[indic]);
				break;
			} 
			else if ((strcmp(valor, matvar[indic])!=0) && (indic==tamvetor))
				printf("ERR: Variavel nao definida\n");
		}	
	} 
	else 
		*acum=(*acum + atof(valor));
}

void sub(char *valor , char **matvar , float *valvar , float *acum, int tamvetor)
{
	int indic;
	
	if(verifstr(valor)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(valor, matvar[indic])==0){
				*acum=(*acum - valvar[indic]);
				break;
			} 
			else if ((strcmp(valor, matvar[indic])!=0) && (indic==tamvetor))
				printf("ERR: Variavel nao definida\n");
		}	
	} 
	else
		*acum=(*acum - atof(valor));
}

void mul(char *valor , char **matvar , float *valvar , float *acum, int tamvetor)
{
	int indic;
	
	if(verifstr(valor)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(valor, matvar[indic])==0){
				*acum=(*acum * valvar[indic]);
				break;
			} 
			else if ((strcmp(valor, matvar[indic])!=0) && (indic==tamvetor))
				printf("ERR: Variavel nao definida\n");
		}	
	} 
	else
		*acum=(*acum * atof(valor));
}

void divs(char *valor, char **matvar, float *valvar, float *acum, int tamvetor)
{
	int indic;
	
	if(verifstr(valor)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(valor, matvar[indic])==0){
				if (valvar[indic]==0){
					printf("ERR: divisao por zero\n");
					break;
				} 
				else {
					*acum=(*acum/valvar[indic]);
					break;
				}
			} 
			else if ((strcmp(valor, matvar[indic])!=0) && (indic==tamvetor))
				printf("ERR: Variavel nao definida\n");
		}	
	} 
	else {
		if (atof(valor)==0)
			printf ("ERR: divisao por zero\n");
		else 
			*acum=(*acum/atof(valor));
		}
}

void poten(char *valor , char **matvar , float *valvar , float *acum, int tamvetor)
{
	int indic;
	
	if(verifstr(valor)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(valor, matvar[indic])==0){
				if ((*acum==0) && (valvar[indic]==0)){
					printf("ERR: potenciacao invalida\n");
					break;
				} 
				else {
					*acum=pow(*acum, valvar[indic]);
					break;
				}
			} 
			else if ((strcmp(valor, matvar[indic])!=0) && (indic==tamvetor))
				printf("ERR: Variavel nao definida\n");
		}	
	} 
	else {
		if ((*acum==0) && (atof(valor)==0))
			printf("ERR: potenciacao invalida\n");
		else
			*acum=pow(*acum, atof(valor));
	}
}

void raiz(char repet[], char oper[], char **vetvar , float *valvar , float *acum, int tamvetor){
	int indic, i;
	float numrepe=0;
	
	if (*acum<0)
		printf("ERR: raiz quadrada invalida\n");
	else {
		if (verifstr(repet)==2)
			printf("ERR: nome da variavel %s invalido\n", repet);
		if (verifstr(repet)==0){
			for(indic=0;indic<=tamvetor;indic++){
				if(strcmp(repet, vetvar[indic])==0){
					numrepe=valvar[indic];
					break;
				}
				else if ((strcmp(repet, vetvar[indic])!=0)&&(indic==tamvetor))
					printf("ERR: Variavel %s nao definida.\n", repet);
			}
		} 
		else if (verifstr(repet)==1)
			numrepe=atof(repet);
	}
	for (i=0; i < numrepe; i++)
		*acum=sqrt(*acum);
}

void rep(char *repet, char *oper, char *valoper , char **vetvar , float *valvar , float *acum, int tamvetor)
{
	int indic=0;
	float numrepe, i;
	
	if (verifstr(repet)==2)
		printf("ERR: nome da variavel %s invalido\n", repet);
	if (verifstr(repet)==0){
		for(indic=0;indic<=tamvetor;indic++){
			if(strcmp(repet, vetvar[indic])==0){
				numrepe=valvar[indic];
				break;
			}
			else if ((strcmp(repet, vetvar[indic])!=0)&&(indic==tamvetor))
				printf("ERR: Variavel %s nao definida.\n", repet);
		}
	} 
	else if (verifstr(repet)==1)
		numrepe=atof(repet);
	if (numrepe<0)
		printf("ERR: Numero para repeticoes negatino.\n");
	else if ((strcmp(oper , "ADD")!=0) && (strcmp(oper , "SUB")!=0) && (strcmp(oper , "MUL")!=0) &&
			(strcmp(oper , "DIV")!=0) && (strcmp(oper , "POW")!=0))
				printf("ERR: instrucao invalida\n");
	else {
		for (i=0; i < numrepe; i++){
			if(strcmp(oper , "ADD")==0){
				if (verifstr(valoper)<2)
					add(valoper , vetvar , valvar , acum, tamvetor);
				else{
					printf("ERR: nome da variavel %s invalido\n", valoper);
					break;
				}
			}
			if(strcmp(oper , "SUB")==0){
				if (verifstr(valoper)<2)
					sub(valoper , vetvar , valvar , acum, tamvetor);
				else{
					printf("ERR: nome da variavel %s invalido\n", valoper);
					break;
				}
			}
			if(strcmp(oper , "MUL")==0){
				if (verifstr(valoper)<2)
					mul(valoper , vetvar , valvar , acum, tamvetor);
				else{
					printf("ERR: nome da variavel %s invalido\n", valoper);
					break;
				}
			}
			if(strcmp(oper , "DIV")==0){
				if (verifstr(valoper)<2)
					divs(valoper , vetvar , valvar , acum, tamvetor);
				else{
					printf("ERR: nome da variavel %s invalido\n", valoper);
					break;
				}
			}
			if(strcmp(oper , "POW")==0){
				if (verifstr(valoper)<2)
					poten(valoper , vetvar , valvar , acum, tamvetor);
				else{
					printf("ERR: nome da variavel %s invalido\n", valoper);
					break;
				}
			}
		}
	}
}

void arquivo(FILE *arq, char *comando, char *numcomando, char **vetvar , float *valvar , float *acum, int indic)
{
	while (!feof(arq)){
		
		fscanf(arq, "%s" , comando);
		if (feof(arq))
			return;
		if(strcmp(comando , "OFF")==0)
			return;
		else if(strcmp(comando , "CLD")==0)
			*acum=0;
		else if(strcmp(comando , "PRINT")==0)
			printf("%.2f\n" , *acum);
		else if(strcmp(comando , "SQRT")==0){
			if (*acum<0)
				printf("ERR: raiz quadrada invalida\n");
			else
				*acum=sqrt(*acum);
		}
		else if(strcmp(comando , "REP")==0){
			char repet[33], oper[11], valoper[33];
			fscanf(arq, "%s %s", repet, oper);
			if (strcmp(oper, "SQRT")==0)
				raiz(repet, oper, vetvar , valvar , acum, indic);
			else{
				fscanf(arq, "%s", valoper);
				rep(repet, oper, valoper, vetvar , valvar , acum, indic);
			}				
		}
		else if(strcmp(comando , "SET")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)<2)
				set(numcomando , vetvar , valvar , acum, indic);
			else
				printf("ERR: nome de variavel invalido\n");
		}
		else if(strcmp(comando , "ADD")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)<2)
				add(numcomando , vetvar , valvar , acum, indic);
			else
				printf("ERR: nome de variavel invalido\n");
		}
		else if(strcmp(comando , "SUB")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)<2)
				sub(numcomando , vetvar , valvar , acum, indic);
			else
				printf("ERR: nome de variavel invalido\n");
		}
		else if(strcmp(comando , "MUL")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)<2)
				mul(numcomando , vetvar , valvar , acum, indic);
			else
				printf("ERR: nome de variavel invalido\n");
		}
		else if(strcmp(comando , "DIV")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)<2)
				divs(numcomando , vetvar , valvar , acum, indic);
			else
				printf("ERR: nome de variavel invalido\n");
		}
		else if(strcmp(comando , "POW")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)<2)
				poten(numcomando , vetvar , valvar , acum, indic);
			else
				printf("ERR: nome de variavel invalido\n");
		}	
		else if(strcmp(comando , "STOD")==0){
			fscanf(arq, "%s", numcomando);
			if (verifstr(numcomando)>0)
				printf("ERR: nome de variavel invalido\n");
			else
				stod(numcomando , &indic , vetvar , valvar , acum);
		}
		else
			printf("ERR: instrucao invalida\n");
	}
}


int main(int argc, char **argv)
{
	FILE *arq;
	float acum=0;
	char comando[1000], numcomando[33];
	int indic=0, l=8,c=32, i;
	char **vetvar;
	float *valvar;
	
	valvar=(float *)malloc(sizeof(float));
	vetvar=malloc(l * sizeof(char));  
	for (i=0;i<l;i++)
		vetvar[i]=malloc(c * sizeof(char));
	
	if (argc>0){
		
		arq = fopen(argv[1], "r");
		if (arq == NULL){
			printf ("Falha ao abrir o arquivo.\n");
			return 1;
		}
		else
			arquivo(arq, comando, numcomando, vetvar , valvar , &acum, indic);
		fclose(arq);
	}
	else{
		while(strcmp(comando , "OFF")!=0){
			
			scanf("%s" , comando);
	
			if(strcmp(comando , "OFF")==0)
				return 0;
			else if(strcmp(comando , "CLD")==0)
				acum=0;
			else if(strcmp(comando , "PRINT")==0)
				printf("%.2f\n" , acum);
			else if(strcmp(comando , "SQRT")==0){
				if (acum<0)
					printf("ERR: raiz quadrada invalida\n");
				else
					acum=sqrt(acum);	
			}
			else if(strcmp(comando , "REP")==0){
				scanf("\n\r%[^\n]", numcomando);
				char repet[33], oper[11], valoper[33];
				scanf("%s %s", repet, oper);
				if (strcmp(oper, "SQRT")==0)
					raiz(repet, oper, vetvar , valvar , &acum, indic);
				else{
					scanf("%s", valoper);
					rep(repet, oper, valoper, vetvar , valvar , &acum, indic);
				}				
			}
			else if(strcmp(comando , "SET")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)<2)
					set(numcomando , vetvar , valvar , &acum, indic);
				else
					printf("ERR: nome de variavel invalido\n");
			}
			else if(strcmp(comando , "ADD")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)<2)
					add(numcomando , vetvar , valvar , &acum, indic);
				else
					printf("ERR: nome de variavel invalido\n");
			}
			else if(strcmp(comando , "SUB")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)<2)
					sub(numcomando , vetvar , valvar , &acum, indic);
				else
					printf("ERR: nome de variavel invalido\n");
			}
			else if(strcmp(comando , "MUL")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)<2)
					mul(numcomando , vetvar , valvar , &acum, indic);
				else
					printf("ERR: nome de variavel invalido\n");
			}
			else if(strcmp(comando , "DIV")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)<2)
					divs(numcomando , vetvar , valvar , &acum, indic);
				else
					printf("ERR: nome de variavel invalido\n");
			}
			else if(strcmp(comando , "POW")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)<2)
					poten(numcomando , vetvar , valvar , &acum, indic);
				else
					printf("ERR: nome de variavel invalido\n");
			}	
			else if(strcmp(comando , "STOD")==0){
				scanf("\n\r%[^\n]", numcomando);
				if (verifstr(numcomando)>0)
					printf("ERR: nome de variavel invalido\n");
				else
					stod(numcomando , &indic , vetvar , valvar , &acum);
			}
			else 
				printf("ERR: instrucao invalida\n");
		}
	}
	return 0;
}

