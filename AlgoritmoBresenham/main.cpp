// Dariãn de Mello Vargas e Huriel Ferreira Lopes

#include <iostream>
#include "PGM.hpp"
#include <bits/stdc++.h>

using namespace std;

#define _PI	3.14159265358979323846

PGM *img = new PGM();

void plotPixel(int x1, int y1, int x2, int y2, int dx, int dy, int decide);

int main (void) {
	setlocale(LC_ALL, "Portuguese");
  int x1, x2, y1, y2, dx,dy,p,p2,xy2,x,y,xf; 
  img->createImage(500, 500);

  // Defne os pontos (x1, y1) e (x2, y2)
  do {
    cout << "Informe x1: ";
    cin >> x1;
    cout << "Informe y1: ";
    cin >> y1;
  } while (x1 < 0 || x1 > img->getWidth() || y1 < 0 || y1 > img->getWidth());
  do {
    cout << "Informe x2: ";
    cin >> x2;
    cout << "Informe y2: ";
    cin >> y2;
  } while (x2 < 0 || x2 > img->getWidth() || y2 < 0 || y2 > img->getWidth());
 
 // Define a distancia entre x1, x2 e y1, y2 
  dx = x2 - x1;
  dy = y2 - y1;

  // varável de decisão P: 
  p = 2 * dy - dx;
  p2 = 2 * dy;
  xy2 = 2 * (dy-dx);
  if (x1>x2) {
    x = x2; 
    y = y2; 
    xf = x1; 
  }
  else {
    x = x1; 
    y = y1; 
    xf = x2; 
  }
  img->setPixel(x, y, 255);

  while (x<xf) {
    x++;
    if (p<0) {
      // próximo ponto será (x+1, y)
      p += p2;
    }
    else {
      // próximo ponto será (x+1, y+1)
      // P é recalculado
      y++;
      p += xy2;
    }
    img->setPixel(x, y, 255);
  }

  img->gravar("saida.pgm");
	system("Pause");
	return EXIT_SUCCESS; 
}