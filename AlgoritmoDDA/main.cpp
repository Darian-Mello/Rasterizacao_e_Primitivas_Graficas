// Dariãn de Mello Vargas e Huriel Ferreira Lopes

#include <iostream>
#include "PGM.hpp"
#include <cmath>

using namespace std;

#define _PI	3.14159265358979323846

float degree2rad(float ang);

int main (void) {
	setlocale(LC_ALL, "Portuguese");
  float x, y, i, x1, x2, y1, y2, dx, dy, step;

  PGM *img = new PGM();
	img->createImage(500, 500);

  do {
    cout << "Informe x1: ";
    cin >> x1;
    cout << "Informe y1: ";
    cin >> y1;
  } while (x1 < 0 || x1 > img->getWidth() || y1 < 0 || y1 > img->getHeight());
  do {
    cout << "Informe x2: ";
    cin >> x2;
    cout << "Informe y2: ";
    cin >> y2;
  } while (x2 < 0 || x2 > img->getWidth() || y2 < 0 || y2 > img->getHeight());

  dx = (x2 - x1);
  dy = (y2 - y1);
  if (abs(dx) >= abs(dy))
    step = abs(dx);
  else
    step = abs(dy);
  dx = dx / step;
  dy = dy / step;
  x = x1;
  y = y1;
  i = 1;
  while (i <= step) {
    img->setPixel(x, y, 255);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }

  img->gravar("saida.pgm");

	system("Pause");
	return EXIT_SUCCESS; 
}

float degree2rad(float ang) {
	float r = ang * (float)(_PI / 180.0);
	return r;
}