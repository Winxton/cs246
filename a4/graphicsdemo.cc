#include <iostream>
#include "window.h"
#include <unistd.h>

using namespace std;

int main() {
  Xwindow w;

  usleep(100000);

  w.fillRectangle(100, 200, 50, 250, Xwindow::Blue);
  
  w.drawString(50, 50, "Hello!");

  char c;
  cin >> c;
}

