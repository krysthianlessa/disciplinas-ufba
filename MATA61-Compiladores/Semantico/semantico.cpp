#include <bits/stdc++.h>

using namespace std;

#define N 5

typedef struct {
    string id;
    int escopo;
} variavel;

set<string> palavrasReservadas = {"e","escreve","int","le","letra","mainha","nada","nao","ou","real","se","senao","tome","uai","vaza"};
vector<string> listaDeLexemas;
vector<string> funcoesDeclaradas;
vector<variavel> variaveisDeclaradas;
bool flags[N];

bool is_letterUnder(char c){  
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 95));
}

bool ehTipo(string lexema) {
    if (lexema == "real" || lexema == "int" || lexema == "letra" || lexema == "nada")
        return true;
    return false;
}

void separarTokens(string buffer) {
    string lexema = "";
    
    for(int i = 0; i < buffer.size(); i++) {
        if (buffer[i] == ' ') {
            listaDeLexemas.push_back(lexema);
            lexema = "";
        } else {
            lexema += buffer[i];
        }    
    }
    listaDeLexemas.push_back(lexema);
}

bool caracteresFinal(string lexema) {
    if (lexema == "," || lexema == ")")
        return true;
    
    return false;
}

bool verifDeclEmFunc(int i) {
    if (listaDeLexemas[i + 1] == "[" && listaDeLexemas[i + 2] == "]" && listaDeLexemas[i + 3] != "=")
        return true;
    return false;
}

bool contemNaListaDeFuncoes(string id) {
    for (int i = 0; i < funcoesDeclaradas.size(); i++)
        if (funcoesDeclaradas[i] == id)
            return true;
    
    return false;    
}

bool contemNaListaDeVariaveis(variavel var) {
    for (int i = 0; i < variaveisDeclaradas.size(); i++)
        if ((variaveisDeclaradas[i].id == var.id) && (variaveisDeclaradas[i].escopo == var.escopo))
            return true;
    
    return false;
}

void analiseSemantica() {
    stack<variavel> pilhaDeVar;
    int escopoAtual = 0, qtdChaves = 0;

    for (int i = 0; i < listaDeLexemas.size(); i++) {
        if (is_letterUnder(listaDeLexemas[i][0]) && !palavrasReservadas.count(listaDeLexemas[i])) { //Se é id
            if (ehTipo(listaDeLexemas[i - 1])) {
                if (listaDeLexemas[i + 1] == "(") { //Declaração de Função!
                    escopoAtual++;
                    if (contemNaListaDeFuncoes(listaDeLexemas[i])){
                        flags[2] = true;
                    } else {
                        funcoesDeclaradas.push_back(listaDeLexemas[i]);
                    }
                } else { //Declaração de variável!
                    variavel var;
                    var.id = listaDeLexemas[i];
                    var.escopo = escopoAtual;
                    
                    if (contemNaListaDeVariaveis(var))
                        flags[3] = true;
                    else {
                        if (contemNaListaDeFuncoes(var.id))
                            flags[4] = true;
                        
                        if (caracteresFinal(listaDeLexemas[i + 1]) || verifDeclEmFunc(i))
                            variaveisDeclaradas.push_back(var);
                        else 
                            pilhaDeVar.push(var);
                    }
                }
            } else {
                if (listaDeLexemas[i + 1] == "(") { //Chamada de Função
                    if (!contemNaListaDeFuncoes(listaDeLexemas[i]))
                        flags[0] = true;
                } else { //Uso de Variável
                    variavel var;
                    var.id = listaDeLexemas[i];
                    var.escopo = escopoAtual;
                    
                    if (!contemNaListaDeVariaveis(var))
                        flags[1] = true;
                }
            }
        } else if (listaDeLexemas[i] == "mainha")
            escopoAtual++;
        else if (listaDeLexemas[i] == ";") {
            while (!pilhaDeVar.empty()) {
                variaveisDeclaradas.push_back(pilhaDeVar.top());
                pilhaDeVar.pop();
            }
        }         
    }
}

int main() {
    char c;
    string buffer;
    memset(flags, false, sizeof(flags));

    while((c = getchar()) && (c != EOF))
        buffer += c;

    separarTokens(buffer);
    analiseSemantica();

    for (int i = 0; i < N; i++)
        if (flags[i])
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;       
    
    return 0;
    
}
