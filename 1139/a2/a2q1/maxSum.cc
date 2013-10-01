#include <iostream>
#include <fstream>
using namespace std;

int main () {
  int num;
  cin >> num;
  int max = num;

  while (cin >> num) {
    if (num > max) {
      max = num;
    }
  }
  std::cout << max << endl;
}
