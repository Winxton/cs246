#include <iostream>
using namespace std;

int test(int p){
  static int i;
  cout << i;
  i = p;
  return p;
}

int main() {
  test(5);
  test(6);
  return 0;
}
