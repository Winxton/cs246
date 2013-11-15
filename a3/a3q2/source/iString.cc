#include "iString.h";
#include <iostream>;
#include <cstdlib>;
using namespace std;

iString::iString() {
	cout << "used default constructor" << endl;
	chars = (char *)malloc(10*sizeof(char));
	*chars = '\0'; //chars[0] = 0
	length = 0;
	capacity = 10;
}

iString::iString(const char *a) {
	cout << "used constructor with char" << endl;
	int n = strlen(a) + 1;
	chars = (char *) malloc( sizeof(char) * n );
	strcpy(chars, a);
	length = n;
	capacity = n;
}

iString::iString(const iString &a){
	cout << "used copy constructor" << endl;
	chars = (char *)malloc(a.capacity*sizeof(char));
	strcpy(chars, a.chars);
	length = a.length;
	capacity = a.capacity;
}

iString::~iString() {
	delete [] chars;
}

iString &iString::operator=(const iString &other) {
	cout << "used assignment operator" << endl;
	delete [] chars;
	chars = (char *)malloc(other.capacity*sizeof(char));
	strcpy(chars, other.chars);
	length = other.length;
	capacity = other.capacity;
	return *this;
}

void iString::print() {
	cout << "String: " << chars << " length: " << length << " capacity: " << capacity << endl;
}