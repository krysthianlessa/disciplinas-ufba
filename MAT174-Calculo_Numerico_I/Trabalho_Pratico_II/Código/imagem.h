#ifndef Imagem_H
#define Imagem_H
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "stb_image.h"
#include "stb_image_write.h"

#define LARGURA 256
#define ALTURA 256

using namespace std;

template <class T> class Imagem
{

private:
    int** matriz;
    int largura, altura;

public:
    //Alocacao da matriz que armazenara a imagem
    void alocarMatriz (int altura, int largura)
    {
        matriz = new int*[altura];
        for (int a = 0; a < altura; a++)
        {
            matriz[a] = new int [largura];

        }

        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                matriz[i][j] = 0;
            }
        }
    }

    //Devolve o valor da largura
    int getLargura()
    {
        return largura;
    }

    //Devolve o valor da altura
    int getAltura()
    {
        return altura;
    }

    //Acessa um elemento na posicao Imagem(linha,coluna)
    //Ex.: img.at(0,0);
    int at (int linha, int coluna)
    {
        return matriz[linha][coluna];
    }

    void setValor(int linha, int coluna, int valor) {
        matriz[linha][coluna] = valor;
    }

    int& operator()(int linha, int coluna)
    {
        return matriz[linha][coluna];
    }

    //Carrega a imagem no buffer (matriz)
    void loadPNG (string caminhoImagem)
    {
        altura = ALTURA;
        largura = LARGURA;
        int canais = 8;


        stbi_uc *pixelData = stbi_load(caminhoImagem.c_str(), &largura, &altura, &canais, STBI_grey);
        alocarMatriz(altura, largura);

        //Copiando o vetor para a matriz
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                stbi_uc pixel = pixelData[largura * j + i];
                matriz[i][j] = static_cast<int>(pixel);
            }
        }

        stbi_image_free(pixelData);
    }

    //Salvando a imagem em um arquivo .PNG
    bool savePNG (string path)
    {
        stbi_uc *pixelData = (stbi_uc*)malloc(1*largura*altura*sizeof(stbi_uc));

        //Copiando a matriz para o vetor
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                pixelData[largura * j + i + 0] = matriz[i][j];
            }
        }

        int saving = stbi_write_png (path.c_str(), LARGURA, ALTURA, 1, pixelData, largura*1);

        return false;
    }

};

#endif // Imagem_H
