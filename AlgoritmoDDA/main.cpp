// Dariãn de Mello Vargas e Huriel Ferreira Lopes
#include <iostream>
#include "PGM.hpp"
#include <cmath>

using namespace std;

int main (void) {
	setlocale(LC_ALL, "Portuguese");
  float x, y, i, x1, x2, y1, y2, dx, dy, step;

  PGM *img = new PGM();
	img->createImage(500, 500);

  // Defne os pontos (x1, y1) e (x2, y2)
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

  // Define a distancia entre x1, x2 e y1, y2 
  dx = (x2 - x1);
  dy = (y2 - y1);

  // fabs() retorna o valor absoluto. Ex: se o numero for -5 retorna 5
  // Caso dx seja maior que dy, a quantidade de passos(pixels) que formarão reta será dx, caso contrário será dy
  if (fabs(dx) >= fabs(dy))
    step = fabs(dx);
  else
    step = fabs(dy);

  // O deslocamento de x ou y será = 1
  dx = dx / step;
  dy = dy / step;

  // início da reta
  x = x1;
  y = y1;
  i = 1;

  //cout << endl << " dx: " << dx << " dy: " << dy << " step: " << step;
  while (i <= step) {
    img->setPixel(round(x), round(y), 255);
    //cout << endl << "x: " << x << " y: " << y;
    //avança para o próximo pixel
    x = x + dx;
    y = y + dy;
    i++;
  }

  img->gravar("saida.pgm");

	system("Pause");
	return EXIT_SUCCESS; 
}