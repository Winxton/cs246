#include <iostream>
#include <sstream>
using namespace std;

struct IntArray {
  int size;
  int capacity;
  int *contents;
};


void addToIntArray(IntArray& ia) 
{
    string s;
    
    while (cin >> s) {
        istringstream ss(s);
        int num;
        if (ss >> num) {
                //check if there's enough space
            if (ia.capacity == 0) {
                ia.contents = new int[5];
                ia.capacity = 5;
            }
            else if (ia.size == ia.capacity) {
                    //create a new array, copy everything over
                int *oldArr = ia.contents;
                ia.contents = new int[ia.capacity*2];
                    //copy everything over
                for (int i =0; i<ia.capacity; i++) {
                    ia.contents[i] = oldArr[i];
                }
                delete [] oldArr;
                ia.capacity *= 2;
            }

            ia.contents[ia.size] = num;
            ia.size += 1;
        } else {
            break;
        }
    }
}

IntArray readIntArray() 
{
    IntArray arr;    
    arr.size = 0;
    arr.capacity = 0;
    arr.contents = NULL;
    addToIntArray(arr);
    return arr;
}

void printIntArray(const IntArray& ia) 
{
    for (int i =0; i < ia.size; i++) {
        cout << ia.contents[i] << " ";
    }
    cout << endl;
 }

// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = 0;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
