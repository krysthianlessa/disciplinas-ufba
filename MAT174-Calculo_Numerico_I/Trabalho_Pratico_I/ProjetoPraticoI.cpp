#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

#define FEX 0

void exibeTitulo();
char escolheMetodo();
void lerConfigMaquina(int &mantissa, int &limInf, int &limSup);
char escolherTipoAprox();
void lerIntervalosePrecisao(double &a, double &b, double &e);
double funcao(double x);
double primDerivada(double x);
double segDerivada(double x);
double absoluto(double x);
int contaDigitos(int numero);
void arredondar(string &maquina, string numNormal, int n, int t);
void truncar(string &maquina, string numNormal, int n, int t);
double maquinaToDouble(string maquina, int valorExp, int t);
double maquina(double x , char c, int t, int i, int s);
double metodoDeNewton(double a, double b, double e, char aprox, int t, int i, int s);
double metodoDasSecantes(double a, double b, double e, char aprox, int t, int i, int s);
void teste();

int main() {
	int mantissa, limInf, limSup;
    double a, b, precisao, xBarra;
	char metodo, aproximacao;

	exibeTitulo();
	metodo = escolheMetodo();
	lerConfigMaquina(mantissa, limInf, limSup);
	aproximacao = escolherTipoAprox();
	lerIntervalosePrecisao(a, b, precisao);

	if (metodo == 'a')
		xBarra = metodoDeNewton(a, b, precisao, aproximacao, mantissa, limInf, limSup);
	else
		xBarra = metodoDasSecantes(a, b, precisao, aproximacao, mantissa, limInf, limSup);

    cout << "xBarra é igual a: " << xBarra << endl;

	return 0;
}

//Função para exibir o titulo da aplicação
void exibeTitulo() {
	string str = "Essa aplicação encontra o estimador de máxima verossimilhança, através dos zeros reais da derivada da função de Log-Verossimilhança para a distribuição Log-Normal. Com n = 100 e Somatório(log(xi) - mi)^2 = 52264844.";

	cout << "-----";
	cout << "Aplicação para calcular o estimador de máxima verossimilhança";
	cout << "-----" << endl;

	cout << endl << str << endl;

}

//Função que retorna o método numérico escolhido pelo usuário
char escolheMetodo() {
	char opcao;

	cout << endl;
	cout << "Por qual método numérico para encontrar zeros reais da função você ";
	cout << "deseja encontrar o estimador de máxima verossimilhança? " << endl;
	cout << "(a) Método de Newton" << endl;
	cout << "(b) Método das Secantes" << endl;
	cout << "Método: ";
	cin >> opcao;

	while (opcao != 'a' && opcao != 'b'){
		cout << endl;
		cout << "Opção inválida! Tente novamente." << endl;
		cout << "Por qual método você deseja encontrar os zeros reais? " << endl;
		cout << "(a) Método de Newton" << endl;
		cout << "(b) Método das Secantes" << endl;
		cout << "Método: ";
		cin >> opcao;
	}

	return opcao;
}

//Função que lê do teclado as configurações da máquina à ser simulada
void lerConfigMaquina(int &mantissa, int &limInf, int &limSup) {
	cout << endl;
	cout << "Digite as configurações da máquina." << endl;
	cout << "Mantissa: ";
	cin >> mantissa;
	cout << "Limite inferior do expoente: ";
	cin >> limInf;
	cout << "Limite superior do expoente: ";
	cin >> limSup;
}

//Função que retorna o tipo de aproximação que a máquina realizará
char escolherTipoAprox() {
	char opcao;

	cout << endl;
	cout << "Deseja que a máquina faça qual tipo de aproximação?" << endl;
	cout << "(a) Truncamento" << endl;
	cout << "(b) Arredondamento" << endl;
	cout << "Aproximação: ";
	cin >> opcao;

	while (opcao != 'a' && opcao != 'b'){
		cout << endl;
		cout << "Opção inválida! Tente novamente." << endl;
		cout << "Deseja que a máquina faça qual tipo de aproximação?" << endl;
		cout << "(a) Truncamento" << endl;
		cout << "(b) Arredondamento" << endl;
		cout << "Aproximação: ";
		cin >> opcao;
	}

	return opcao;
}

//Função para receber do usuário o intevarlo e a precisão para encontrar a raiz real
void lerIntervalosePrecisao(double &a, double &b, double &e) {
	cout << endl;
	cout << "Digite o valor de a: ";
	cin >> a;
	cout << "Digite o valor de b: ";
	cin >> b;
	cout << "Digite o valor de epslon: ";
	cin >> e;
}

//Função Log - Verossimilhança
//l'(sigma, x) = -(n/sigma) + ((Somatório(log(xi) - mi)^2)/simga^3)
double funcao(double x) {

	if (FEX) return (pow(x, 3) - (9*x) + 3);

	double a = -(100.0/x);
	double b = (8408621.0/pow(x, 3.0));
	return (a + b);
}

//Primeira derivada de l', que é l''
double primDerivada(double x) {

	if (FEX) return ((3*pow(x, 2)) - 9);

	double a = (100.0/pow(x,2));
	double b = -((3*8408621.0)/pow(x,4.0));
	return (a + b);
}

//Segunda derivada de l', que é l'''
double segDerivada(double x) {

	if (FEX) return (6*x);

	double a = -((2*100.0)/pow(x,3.0));
	double b = ((12*8408621.0)/pow(x,5.0));
	return (a + b);
}

//Função que retorna o valor absoluto (módulo) do argumento
double absoluto(double x){
	if (x < 0.0)
		return (x*(-1.0));
	return x;
}

//Função para contar a quantidade de digitos de um número inteiro
int contaDigitos(int numero) {
	int contador = 0;

	if (numero == 0) return 1;
	else
		while (numero != 0) {
			contador++;
			numero /= 10;
		}

	return contador;
}

//Função para arredondar a máquina
void arredondar(string &maquina, string numNormal, int n, int t) {
    int i,j;

	for (i = 1, j = 2; i <= t; i++, j++)
        if (j < numNormal.size())
            maquina[i] = numNormal[j];
        else
            maquina[i] = '0';

    if (j < numNormal.size())
        if (numNormal[j] >= '5')
            for (int k = t; k > 0; k--)
                if (maquina[k] == '9')
                    maquina[k] = '0';
                else {
					maquina[k]++;
					break;
				}
}

//Função para truncar a máquina
void truncar(string &maquina, string numNormal, int n, int t) {
    for (int i = 1, j = 2; i <= t; i++, j++)
        if (j < numNormal.size())
            maquina[i] = numNormal[j];
        else
            maquina[i] = '0';
}

//Função que retorna o valor da máquina para o tipo primitivo double
double maquinaToDouble(string maquina, int valorExp, int t) {
    string aux;
    double x;

    aux += "0.";
    for (int i = 1; i <= t; i++)
        aux += maquina[i];

    x = stod(aux);

    if (maquina[0] == '1')
        x *= -1;

    if (maquina[t + 1] == '1')
        for (int i = 0; i < valorExp; i++)
            x /= 10;
    else
        for (int i = 0; i < valorExp; i++)
            x *= 10;

    return x;
}

//Função que simula uma máquina de base = 10, mantissa = t, lim. inf = i, lim. sup. = s
double maquina(double x , char c, int t, int i, int s) {
    int n = 2 + t + contaDigitos(s);
    int qtdMovPonto = 0;
    string expoente, numNormal, maquina(n,'0');

    if (x < 0)
        maquina[0] = '1';
    else
        maquina[0] = '0';

    x = absoluto(x);

    if (x > 0 && x < 0.1) {
        maquina[1 + t] = '1';
        while(x < 0.1) {
            x *= 10;
            qtdMovPonto++;
        }
    } else if(x >= 1.0) {
        maquina[1 + t] = '0';
        while(x >= 1.0) {
            x /= 10;
            qtdMovPonto++;
        }
    }

    numNormal = to_string(x);
    expoente = to_string(qtdMovPonto);

    for (int i = n-1, j = expoente.size() - 1; i >= (2+t); i--, j--)
        if (j >= 0)
            maquina[i] = expoente[j];
        else
            maquina[i] = '0';

    if (c == 'a')
        truncar(maquina, numNormal, n, t);
    else
		arredondar(maquina, numNormal, n, t);

    x = maquinaToDouble(maquina, qtdMovPonto, t);

    return x;
}

//Função que resolve sistemas não-lineares por Métodos das Cordas
double metodoDasSecantes(double a, double b, double e, char aprox, int t, int i, int s) {
	double xProximo, xZero, xUm;
	int k = 0;

	//Encontrando valor de x0 e x1
	xZero = a;
	while ((funcao(xZero)*segDerivada(xZero) <= 0))
		xZero += 0.1;

	xUm = xZero + 0.1;
	while ((funcao(xUm)*segDerivada(xUm) <= 0))
		xUm += 0.1;

	//Aplicando o método numérico
	cout << endl << 'k' << '\t' << "Xk+1" << endl;
	do {
		xProximo = xUm - ((funcao(xUm)/(funcao(xUm)-funcao(xZero)))*(xUm - xZero));
		cout << k << '\t' << setprecision(15) << xProximo << endl;
		xProximo = maquina(xProximo, aprox, t, i, s);
		cout << k << '\t' << setprecision(15) << xProximo << endl;
		xZero = xUm;
		xUm = xProximo;
		k++;
	} while ((absoluto(funcao(xProximo)) >= e) || (absoluto(xProximo - xUm) >= e));

	return xProximo;
}

//Função que resolve sistemas não-lineares por Método de Newton
double metodoDeNewton(double a, double b, double e, char aprox, int t, int i, int s) {
	double xAnterior, xProximo, xZero;
	int k = 0;

	//Encontrando o valor de x0
	xZero = a;
	if (funcao(a)*segDerivada(a) > 0) {
		xZero = a;
	} else if (funcao(b)*segDerivada(b) > 0) {
		xZero = b;
	} else {
		xZero = (b+a)/2;
		while ((funcao(xZero)*segDerivada(xZero) <= 0))
			xZero = (xZero+a)/2;
	}

	xProximo = maquina(xZero, aprox, t, i, s);
	//Aplicando o método numérico
	cout << endl << 'k' << '\t' << "Xk+1" << endl;
	do {
		xAnterior = xProximo;
		xProximo = xAnterior - (funcao(xAnterior) / primDerivada(xAnterior));
		cout << k << '\t' << setprecision(15) << xProximo << endl;
		xProximo = maquina(xProximo, aprox, t, i, s);
		cout << k << '\t' << setprecision(15) << xProximo << endl;
		k++;
	} while ((absoluto(funcao(xProximo)) >= e) || (absoluto(xProximo - xAnterior) >= e));

	return xProximo;
}
