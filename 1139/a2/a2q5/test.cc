#include <iostream>
#include <sstream>
using namespace std;

struct IntArray
{
    int size;
    int capacity;
    int *contents;
};

void printArr(IntArray &ia) 
{
    cout << ia.size << endl;
}

void swap (int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{

    string s;
    int i;
    
    while (cin >> s) {
        istringstream ss(s);
        if (ss >> i) {
            cout << i << endl;
        } else {
                //non numeric
            break;
        }
    }

    cout << "OK" << endl;
}

            
