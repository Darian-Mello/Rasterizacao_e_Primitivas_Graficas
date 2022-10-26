#include "PGM.hpp"

#include <iostream>
using namespace std;

PGM::PGM(){
    pixels = nullptr;
	larg = 0;
	alt = 0;
	tipo = "";
}

PGM::~PGM() {
    if (pixels)
        delete pixels;
    pixels = nullptr;
}


int PGM::getWidth()
{
    return larg;
}

int PGM::getHeight()
{
    return alt;
}


unsigned char* & PGM::getPixels()
{
    return pixels;
}

unsigned char PGM::getPixel(int x, int y)
{
    if (!pixels)
        return 0;
 
    return pixels[y*larg + x];
}

void PGM::setPixel(int x, int y, unsigned char cor)
{
    if (!pixels)
        return;

    if(pixels)
        pixels[y*larg + x] = cor;
}

void PGM::setCorLinha(int linha, unsigned char cor)
{
    if (!pixels) //pixels==NULL
        return;

    // for(int x=0; x<larg; x++)
    //     pixels[linha*larg + x] = cor;

    for(int x=0; x<larg; x++)
        this->setPixel(x, linha, cor);
   

    
}

void PGM::setRegiao(int x1, int y1, int x2, int y2, unsigned char cor)
{
    if (!pixels)
        return;

    for (int y = y1; y <= y2; y++) 
    {
        for (int x = x1; x <= x2; x++) 
        { 

            //pixels[y*larg + x] = cor;
            this->setPixel(x, y, cor);
        }
    }
}

void PGM::setRegiaoVersao2(int x1, int y1, int x2, int y2, unsigned char cor)
{
    if (!pixels)
        return;

    for (int y = y1; y < y2; y++)
    {
        for (int x = x1; x <= x2; x++)
        { 
            if(x<larg && x>=0 && y<alt && y>=0)
                pixels[y*larg + x] = cor;
        }
    }
}



void PGM::createImage(int largura, int altura) //cria imagem com fundo preto, dimensão "largura X altura"
{
    //desaloca memória caso o vetor de pixels esteja alocado
    if (pixels) //pixels!=NULLL
        delete pixels;

    //define o tipo
    tipo = "P2";

    //atribui a largura e altura aos atributos da classe
    larg = largura;
    alt = altura;

    //cria o vetor de pixels
    pixels = new unsigned char[larg * alt];

    //definir a cor preta para todos os pixels
    for( int i=0; i< larg * alt; i++)
        pixels[i] = 0;
}

void PGM::colorirLinhas(int intervalo, unsigned char cor)
{
    if (!pixels)
        return;

    for (int y = intervalo; y < alt; y+=intervalo)
    {
        for (int x = 0; x < larg; x++) 
        { 
                pixels[y*larg + x] = cor;
        }
    }
}


bool PGM::ler(string caminho) {
    ifstream arq;
    string aux;

    

    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }

    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler o tipo da imagem\n";
        return false;
    }
    tipo = aux;


    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler a largura da imagem\n";
        return false;
    }
    larg = atoi(aux.c_str());

    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler a altura da imagem\n";
        return false;
    }
    alt = atoi(aux.c_str());


    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler o valor máximo de cor\n";
        return false;
    }
    vmax = atoi(aux.c_str());

    if (pixels)
        delete pixels;
    pixels = new unsigned char[larg * alt];

    int i = 0;
    while (!arq.eof()) {
        if (!lerDado(arq, &aux)) {
            break;
        }

        pixels[i] = (unsigned char) atoi(aux.c_str());
        i++;

    }

    //cout << "i: " << i << endl;
    if (i != larg * alt) {
        cout << "PGM: erro ao ler os pixels\n";
        return false;
    }

    //cout << this->tipo << endl;
    //cout << this->larg << endl;
    //cout << this->alt << endl;
    //cout << this->vmax << endl;


    return true;
}



bool PGM::gravar(string caminho) {

    if (!pixels)
        return false;

    ofstream arq;

    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }

    arq << tipo << endl;

    arq << larg << " " << alt << endl;

    arq << 255 << endl; // valor máximo de cor fixo em 255

    int tam = larg * alt;
    for (int i = 0; i < tam; i++)
    {
        arq << (int) pixels[i] << endl;
        arq.flush();
    }
        

    arq.close();
    return true;
}

bool PGM::lerDado(ifstream &arq, string *dado) {
    string aux;
    while (!arq.eof()) {
        arq >> aux;
        if (aux.size() > 0 && aux[0] == '#') {//isso é um comentário? descartar
            std::getline(arq, aux);//descartar
        }else if(aux.size() > 0){
            *dado = aux;
            return true;
        }

        aux = "";
    }
    return false;
}
