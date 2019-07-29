#include <iostream>
#include <vector>
#include "imagem.h"

//Define um N máximo para criar uma tabela NxN para armazenar as diferenças divididas/finitas
#define N 100 

using namespace std;

//Criação da tabela NxN
double tabelaDiferencas[N][N];

//Função para ler os dados de entrada do usuário
void lerEntradas(char &metodo, int &n, double &xDado, vector<double> &x, vector<double> &y, string &pathImage) {

    cout << "------------------------------------------------------------" << endl;
    cout << "Projeto 02 de MAT174 - Cálculo Numérico" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << endl << endl;
    cout << "Escolha por qual método deseja que a Interpolação seja feita:" << endl;
    cout << "(a) Método de Newton (Diferenças Divididas)" << endl;
    cout << "(b) Método de Gregory-Newton (Diferenças Divididas)" << endl;
    cout << "Método: ";
    cin >> metodo;
    cout << endl;
    cout << "Digite a quantidade de pontos que serão utilizados na Interpolação (digite um inteiro par): ";
    cin >> n;
    cout << endl;
    cout << "Digite todos os nós da interpolação:" << endl; 
    
    for(int i = 0; i < n; i++) {
        double auxiliar;

        cout << "x[" << i << "]: ";
        cin >> auxiliar;
        x.push_back(auxiliar);
        cout << "y[" << i << "]: ";
        cin >> auxiliar;
        y.push_back(auxiliar);
    }
    cout << endl;

    cout << "Digite o valor de x para calcular P" << n << "(x): ";
    cin >> xDado;

    cout << "Digite o caminho da imagem: ";
    cin >> pathImage;
    cout << endl;

}

//Função que calculao módulo de um número de ponto flutante
double modulo(double a) {
	if (a < 0)
		return a*(-1.0);
	return a;
}

//Função recursiva para calcular o fatorial de um número n
double fatorial(double n) {
	if (n == 0.0 || n == 1.0)
		return 1.0;
	return fatorial(n - 1.0)*n;
}

/* Função para ler o vetor x[i] novamente, caso o método das diferenças finitas seja escolhido
    e as diferenças entre os x[i] não estejam igualmente espaçados*/
void lerX(vector<double> x, int n){
	for (int i = 0; i < n; ++i) {
		printf("x[%d]: ", i);
		scanf("%lf", &x[i]);
	}
}

//Função para imprimir as tabelas das diferenças
void imprimirTabela(vector<double> x, vector<double> y, int n, char m) {
    if (m == 'a'){
        cout << "---Tabela das Diferenças Divididas---" << endl;
        cout << "x[i]\ty[i]\t";
        for (int i = 1; i < n; i++)
            cout << "DD^" << i << "yi\t";
        cout << endl;
    } else {
        cout << "---Tabela das Diferenças Finitas---" << endl;
        cout << "x[i]\ty[i]\t";
        for (int i = 1; i < n; i++)
            cout << "DF^" << i << "yi\t";
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << x[i] << '\t' << y[i] << '\t';
        for (int j = 1; j < n; j++) {
            if (tabelaDiferencas[i][j] == 0.0)
                cout << "--" << '\t';
            else
                cout << tabelaDiferencas[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

//Função para verificar se os x[i] estão igualmente espaçados, para o método das diferenças finitas.
bool ehDiferencaFinita(vector<double> x, int n){
	double h = x[1] - x[0];
	for(int i = 2; i < n; i++)
        if ((x[i] - x[i-1]) != h)
            return false;
	return true;
}

//Função que calcula as Diferenças Divididas recursivamente, e popula a tabela das diferenças
double difDividida(int n, int i, vector<double> y, vector<double> x) {
	if (n == 0) {
        double aux = y[i];
        tabelaDiferencas[i][n] = aux;    
		return aux;
    }
    double aux = ((difDividida(n-1, i+1, y, x) - difDividida(n-1, i, y, x)) / (x[i+n] - x[i]));
    tabelaDiferencas[i][n] = aux;
	return aux;
}

//Função que calcula as Diferenças Finitas recursivamente, e popula a tabela das diferenças
double difFinita(int n, int i, vector<double> y, vector<double> x) {
	if (n == 0) {
        double aux = y[i];
        tabelaDiferencas[i][n] = aux;    
		return aux;
    }
	double aux = (difFinita(n-1, i+1, y, x) - difFinita(n-1, i, y, x));
    tabelaDiferencas[i][n] = aux;
	return aux;
}

//Função para o calculo da Interpolação de Newton
double InterpolacaoDeNewton(int n, vector<double> x, vector<double> y, double xDado){
	double Pn, P, S;

	S = 0.0;
	for (int i = 1; i < n; ++i) {
		P = 1.0;
		for (int j = 0; j < i; ++j)
			P *= (xDado - x[j]);
		
		S += difDividida(i, 0, y, x) * P;
	}
	Pn = y[0] + S;
	return Pn;
}

//Função para o calculo da Interpolação de Gregory-Newton
double InterpolacaoDeGregoryNewton(int n, vector<double> x, vector<double> y, double xDado){
	double Pn, P, S, z;

	z = ((xDado - x[0]) / (x[1] - x[0]));
	S = 0.0;
	P = 1.0;
	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < i; j++)
			P *= (z - j);

		S += ((difFinita(i, 0, y, x) * P) / fatorial(i));
	}
	Pn = y[0] + S;

	return Pn;
}

//Função para o calculo do novo ponto Pn(x), a partir das entradas do usuário
double calculoDoPn(int n, double xDado, char metodo, vector<double> x, vector<double> y) {
    double z;
    cout << metodo << endl;
    if (metodo == 'a') {
        z = InterpolacaoDeNewton(n, x, y, xDado);
        imprimirTabela(x, y, n, metodo);
        return z;
    } else {
        while (!ehDiferencaFinita(x, n)){
            cout << "Esse metodo só pode ser utilizado com valores igualmente espaçados entre os x[i]!" << endl;
            cout << "Digite valores de x[i] igualmente espaçados." << endl;
            lerX(x, n);
        }
        z = InterpolacaoDeGregoryNewton(n, x, y, xDado);
        imprimirTabela(x, y, n, metodo);
        return z;
	}
}

//Função que faz a alteração do ponto (x, Pn(x)) na imagem
void restauracaoDaImagem(Imagem<int> &imagem, vector<double> x, vector<double> y, double xDado, double Pnx) {
    int n = x.size();
    int novoValor = 0;

    for (int i = 0; i < n; i++) {
        novoValor += imagem.at(x[i], y[i]);
    }
    novoValor /= n;
    
    imagem.setValor(xDado, Pnx, novoValor);
}

int main() {
    Imagem<int> imagem;
    char metodo;
    int n;
    double xDado, yCalculado;
    string pathImage;
    vector<double> x;
    vector<double> y;

    lerEntradas(metodo, n, xDado, x, y, pathImage);
    
    yCalculado = calculoDoPn(n, xDado, metodo, x, y);

    cout << "(x, Pn(x)) = " << "(" << xDado << ", " << yCalculado << ")" << endl;
 
    imagem.loadPNG(pathImage);
    restauracaoDaImagem(imagem, x, y, xDado, yCalculado);
    imagem.savePNG(pathImage);

    return 0;
}