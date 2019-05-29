#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG false

#define Q0 0
#define ID 1
#define NUM_I 2
#define NUM_F 3
#define STR 4
#define PRE_CHR 5
#define CHR 6
#define PRE_DIF 7
#define DIFE 8
#define ATRIB 9
#define CMP_ORD1 10
#define CMP_ORD2 11

typedef struct {
    string str;
} Lexema;

typedef struct {
    int estado;
    string str_acumulado;
    int ult_linha;
    int ult_coluna;
} MaquinaDeEstados;

char flag = 1;
MaquinaDeEstados maquina;
int linha = 1;
int coluna = 1;

void analisadorLexico(string buffer);
bool is_charValido(char c);
bool is_letterUnder(char c);
bool is_number(char c);
bool is_aspasDuplas(char c);
bool is_aspasSimples(char c);
bool is_ponto(char c);
bool is_lexUnitario(char c);
bool is_exclamacao(char c);
bool is_igual(char c);
bool is_white(char c);
bool is_compOrdem(char c);
void consome(char c);
void imprimeErro();
void imprimeErro(int linha, int coluna);
int qzero(char c);
int id(char c);
int numI(char c);
int numF(char c);
int str(char c);
int pre_chr(char c);
int chr(char c);
int pre_dif(char c);
int dif(char c);
int atrib(char c);
int cmp_ord1(char c);
int cmp_ord2(char c);
void teste();

int main(){
    char c;
    string buffer;
    vector<Lexema> filaDeLexemas;

    if (DEBUG) {
        teste();
        if (flag) {
            cout << "OK\n";
        }
        return 0;
    }
    

    while((c = getchar()) && (c != EOF)){
        if (!is_charValido(c)) {
            cout << "ARQUIVO INVALIDO\n";
            return 0;
        }
        buffer += c;
    }
    buffer += -1;

    analisadorLexico(buffer);

    if (flag) {
        cout << "OK\n";
    }

    return 0;
}

void analisadorLexico(string buffer){
    MaquinaDeEstados maquina;
    maquina.estado = Q0;
    
    for(int i = 0; i < buffer.size(); i++, coluna++){
        switch (maquina.estado) {
            case Q0:
                maquina.estado = qzero(buffer[i]);
                break;
            case ID:
                maquina.estado = id(buffer[i]);
                break;
            case NUM_I:
                maquina.estado = numI(buffer[i]);
                break;
            case NUM_F:
                maquina.estado = numF(buffer[i]);
                break;
            case STR:
                maquina.estado = str(buffer[i]);
                break;
            case PRE_CHR:
                maquina.estado = pre_chr(buffer[i]);
                break;
            case CHR:
                maquina.estado = chr(buffer[i]);
                break;
            case PRE_DIF:
                maquina.estado = pre_dif(buffer[i]);
                break;
            case DIFE:
                maquina.estado = dif(buffer[i]);
                break;
            case ATRIB:
                maquina.estado = atrib(buffer[i]);
                break;
            case CMP_ORD1:
                maquina.estado = cmp_ord1(buffer[i]);
                break;
            case CMP_ORD2:
                maquina.estado = cmp_ord2(buffer[i]);
                break;
            default:
                cout << "Tratar alguma coisa!\n";
                break;
        }
    }
}

bool is_charValido(char c){
    return (c == 9 || c == 10 || (c >= 32 && c <= 126));
}

bool is_letterUnder(char c){  
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 95));
}

bool is_number(char c){
    return (c >= 48 && c <= 57);
}

bool is_aspasDuplas(char c){
    return (c == 34);
}

bool is_aspasSimples(char c){
    return (c == 39);
}

bool is_ponto(char c){
    return (c == '.');
}

bool is_lexUnitario(char c){
    return ((c == 37) || (c == 42) || (c == 43) || (c == 45) || (c == 47) ||
            (c == 40) || (c == 41) || (c == 44) || (c == 59) || (c == 91) || 
            (c == 93) || (c == 123) || (c == 125));
}

bool is_exclamacao(char c){
    return (c == 33);
}

bool is_igual(char c){
    return (c == 61);
}

bool is_white(char c){
    return ((c == 9) || (c == 10) || (c == 32));
}

bool is_compOrdem(char c){
    return ((c == 60) || (c == 62));
}

bool is_EOF(char c){
    return (c == -1);
}

bool is_nenhumaColuna(char c){
    return !(is_letterUnder(c) || is_number(c) || is_aspasDuplas(c) || 
            is_aspasSimples(c) || is_ponto(c) || is_lexUnitario(c) || 
            is_exclamacao(c) || is_igual(c) || is_white(c) || is_compOrdem(c) || 
            is_EOF(c));
}

void consome(char c){
    maquina.str_acumulado += c;
    maquina.ult_linha = linha;
    maquina.ult_coluna = coluna;
}

void imprimeErro(){
    flag = 0;
    cout << linha << ' ' << coluna << endl;
    maquina.str_acumulado = "";
    maquina.estado = Q0;
}

void imprimeErro(int linha, int coluna){
    flag = 0;
    cout << linha << ' ' << coluna << endl;
    maquina.str_acumulado = "";
    maquina.estado = Q0;
}

void gerarLexema(){
    maquina.str_acumulado = "";
}

int qzero(char c) {
    if (is_letterUnder(c)) {
        consome(c);
        return ID;
    } else if (is_number(c)) {
        consome(c);
        return NUM_I;
    } else if (is_aspasDuplas(c)) {
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c) || is_nenhumaColuna(c)) {
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        consome(c);
        return ATRIB;
    } else if (is_white(c)) {
        if (c == 10){
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        return Q0;
    }
}

int id(char c){
    if (is_letterUnder(c)) {
        if (maquina.str_acumulado.size() >= 128) {
            imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        }
        consome(c);
        return ID;
    } else if (is_number(c)) {
        if (maquina.str_acumulado.size() >= 128) {
            imprimeErro(maquina.ult_linha, maquina.ult_coluna);
            consome(c);
            return NUM_I;
        }
        consome(c);
        return ID;
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;        
    } else if (is_ponto(c) || is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        gerarLexema();
        consome(c);
        return ATRIB;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10){
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    }
}

int numI(char c){
    if (is_letterUnder(c)) {
        gerarLexema();
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        consome(c);
        return ID;
    } else if (is_number(c)) {
        if (maquina.str_acumulado.size() >= 128){
            imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        }
        consome(c);
        return NUM_I;
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c)) {
        if (maquina.str_acumulado.size() >= 128) {
            imprimeErro(maquina.ult_linha, maquina.ult_coluna);
            imprimeErro();
            return Q0;
        } else {
            consome(c);
            return NUM_F;
        }
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        gerarLexema();
        consome(c);
        return ATRIB;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10) {
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    } else if (is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    }
}

int numF(char c){
    if (is_letterUnder(c)) {
        gerarLexema();
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        consome(c);
        return ID;
    } else if (is_number(c)) {
        if (maquina.str_acumulado.size() >= 128) {
            imprimeErro(maquina.ult_linha, maquina.ult_coluna);
            consome(c);
            return NUM_I;
        } else {
            consome(c);
            return NUM_F;
        }
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c)) {
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        gerarLexema();
        consome(c);
        return ATRIB;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10){
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    } else if (is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    }
}

int str(char c){
    if ((maquina.str_acumulado.size() >= 129 && !is_aspasDuplas(c)) || is_EOF(c)) {
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        return qzero(c);
    } else {
        if (is_aspasDuplas(c)) {
            consome(c);
            gerarLexema();
            return Q0;
        } else {
            consome(c);
            if (c == 10) {
                linha++;
                coluna = 0;
            }
            return STR;
        }        
    }
}

int pre_chr(char c){
    if (is_aspasSimples(c)) {
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        consome(c);
        return PRE_CHR;
    } else if (is_EOF(c)) {
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        return Q0;
    } else {
        consome(c);
        if (c == 10) {
            linha++;
            coluna = 0;
        }
        return CHR;
    }
}

int chr(char c){
    if (is_aspasSimples(c)) {
        consome(c);
        gerarLexema();
        return Q0;
    } else {
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        return qzero(c);
    }
    
}

int pre_dif(char c){
    if (is_igual(c)) {
        consome(c);
        return DIFE;
    } else {
        imprimeErro(maquina.ult_linha, maquina.ult_coluna);
        return qzero(c);
    }
}

int dif(char c){
    if (is_letterUnder(c)) {
        gerarLexema();
        consome(c);
        return ID;
    } else if (is_number(c)) {
        gerarLexema();
        consome(c);
        return NUM_I;
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c) || is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        gerarLexema();
        consome(c);
        return ATRIB;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10) {
            linha++;
            coluna = 0;   
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    }    
}

int atrib(char c){
    if (is_letterUnder(c)) {
        gerarLexema();
        consome(c);
        return ID;
    } else if (is_number(c)) {
        gerarLexema();
        consome(c);
        return NUM_I;
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c) || is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        consome(c);
        return CMP_ORD2;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10) {
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    }    
}

int cmp_ord1(char c){
    if (is_letterUnder(c)) {
        gerarLexema();
        consome(c);
        return ID;
    } else if (is_number(c)) {
        gerarLexema();
        consome(c);
        return NUM_I;
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c) || is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        consome(c);
        return CMP_ORD2;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10) {
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    }    
}

int cmp_ord2(char c){
    if (is_letterUnder(c)) {
        gerarLexema();
        consome(c);
        return ID;
    } else if (is_number(c)) {
        gerarLexema();
        consome(c);
        return NUM_I;
    } else if (is_aspasDuplas(c)) {
        gerarLexema();
        consome(c);
        return STR;
    } else if (is_aspasSimples(c)) {
        gerarLexema();
        consome(c);
        return PRE_CHR;
    } else if (is_ponto(c) || is_nenhumaColuna(c)) {
        gerarLexema();
        imprimeErro();
        return Q0;
    } else if (is_lexUnitario(c)) {
        gerarLexema();
        consome(c);
        gerarLexema();
        return Q0;
    } else if (is_exclamacao(c)) {
        gerarLexema();
        consome(c);
        return PRE_DIF;
    } else if (is_igual(c)) {
        gerarLexema();
        consome(c);
        return ATRIB;
    } else if (is_white(c)) {
        gerarLexema();
        if (c == 10) {
            linha++;
            coluna = 0;
        }
        return Q0;
    } else if (is_compOrdem(c)) {
        gerarLexema();
        consome(c);
        return CMP_ORD1;
    } else if (is_EOF(c)) {
        gerarLexema();
        return Q0;
    }    
}

void teste(){
    string input;

    input = "1a";
    input += -1;

    analisadorLexico(input);
}