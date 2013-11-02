#include "iString.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

iString::iString() {
	chars = new char[10];
	length = 0;
	capacity = 10;
}

iString::iString(const char *a) {
	int n = strlen(a);
	chars = new char[n];
	for (int i = 0; i < n; i++) {
		chars[i] = a[i];
	}
	length = n;
	capacity = n;
}

iString::iString(const iString &a){
	chars = new char[a.capacity];
	for (int i = 0; i < a.length; i++) {
		chars[i] = a.chars[i];
	}
	length = a.length;
	capacity = a.capacity;
}

iString::~iString() {
	delete [] chars;
}

iString &iString::operator=(const iString &other) {
	delete [] chars;

	chars = new char[other.capacity];
	for (int i = 0; i < other.length; i++) {
		chars[i] = other.chars[i];
	}
	length = other.length;
	capacity = other.capacity;
	return *this;
}

iString operator+(const iString &a, const iString &b) {
	char *chars = new char[a.length + b.length + 1];
	//copy each string to new character array
	for (int i = 0; i < a.length; i++) {
		chars[i] = a.chars[i];
	}
	for (int i = 0; i < b.length; i++) {
		chars[a.length+i] = b.chars[i];
	}
	chars[a.length + b.length] = '\0';
	return iString(chars);
}

iString operator*(int n, const iString &s) {
	if (n == 0) {
		return iString();
	}
	else
	{
		//create resulting iString
		iString result = s;

		for (int times = 1; times < n; times++) {
			result = result + s;
		}
		return result;
	}
}

iString operator*(const iString &s, int n) {
	return n * s;
}

ostream &operator<<(ostream &out, const iString &s) {
	for (int i = 0; i < s.length; i++) {
		out << s.chars[i];
	}
	return out;
}

std::istream &operator>>(std::istream &in, iString &s) {
	//create character array of default size
	int capacity = 10;
	int length = 0;
	char *chars = new char[capacity];

	char temp;
	//read in from std input until termination, create a dynamic string
	//while ( !(isspace( in.peek() )) ) {
		//in >> temp;
	while (cin >> temp) {
		if (length == capacity) {
			capacity *= 2;
			char *newChars = new char[capacity];
			for (int i = 0; i < length; i++) {
				newChars[i] = chars[i];
			}
			delete[] chars;
			chars = newChars;
		}
		chars[length] = temp;
		length++;
		if (isspace(in.peek())) break;
	}
	//replace the character array in the iString with the new one
	delete[] s.chars;
	s.chars = chars;
	s.length = length;
	s.capacity = capacity;
	return in;
}
