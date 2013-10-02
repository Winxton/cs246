#include <iostream>
using namespace std;

int main() {
  int n = 5;
  int *p = &n;
  int **pp = &p;
  cout << p << endl;
  cout << *p << endl;
  cout << pp << endl;
  cout << *pp << endl;
  cout << **pp << endl;
}
