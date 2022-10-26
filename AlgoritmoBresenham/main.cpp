// Dariãn de Mello Vargas e Huriel Ferreira Lopes

#include <iostream>
#include "PGM.hpp"
#include <bits/stdc++.h>

using namespace std;

#define _PI	3.14159265358979323846

PGM *img = new PGM();

float degree2rad(float ang);
void plotPixel(int x1, int y1, int x2, int y2, int dx, int dy, int decide);

int main (void) {
	setlocale(LC_ALL, "Portuguese");
  int x1, y1, x2, y2, dx, dy, pk;
  img->createImage(500, 500);

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
 
  dx = abs(x2 - x1);
  dy = abs(y2 - y1);

  if (dx > dy) {
    plotPixel(x1, y1, x2, y2, dx, dy, 0);
  }
  else {
    plotPixel(y1, x1, y2, x2, dy, dx, 1);
  }

  img->gravar("saida.pgm");
	system("Pause");
	return EXIT_SUCCESS; 
}

float degree2rad(float ang) {
	float r = ang * (float)(_PI / 180.0);
	return r;
}

void plotPixel(int x1, int y1, int x2, int y2, int dx, int dy, int decide) {
  int pk = 2 * dy - dx;
  for (int i = 0; i <= dx; i++) {
    x1 < x2 ? x1++ : x1--;
    if (pk < 0) {
      if (decide == 0) {
        pk = pk + 2 * dy;
      }
      else {
        pk = pk + 2 * dy;
      }
    }
    else {
      y1 < y2 ? y1++ : y1--;
      if (decide == 0) {
        img->setPixel(x1, y1, 255);
        // putpixel(x1, y1, RED);
      }
      else {
        img->setPixel(y1, x1, 255);
        //  putpixel(y1, x1, YELLOW);
      }
      pk = pk + 2 * dy - 2 * dx;
    }
  }
}