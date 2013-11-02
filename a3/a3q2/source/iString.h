#ifndef __ISTRING_H__
#define __ISTRING_H__

#include <cstdlib>
#include <iostream>

//string - default capacity 10;
struct iString {
	char * chars;
	unsigned int length;
	unsigned int capacity;
	iString();
	iString(const char *a);
	iString(const iString &a);
	~iString();

	iString &operator=(const iString &other);
};
iString operator*(int n, const iString &s);
iString operator*(const iString &s, int n);
iString operator+(const iString &a, const iString &b);

std::ostream &operator<<(std::ostream &out, const iString &s);
std::istream &operator>>(std::istream &in, iString &s);
#endif // !1