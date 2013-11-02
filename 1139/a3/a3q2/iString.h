#ifndef __ISTRING_H__
#define __ISTRING_H__

#include <cstdlib>

//string - default capacity 10;
struct iString {
	char * chars;
	unsigned int length;
	unsigned int capacity;
	iString();
	iString(const char *a);
	iString(const iString &a);
	~iString();
	void print();
	iString &operator=(const iString &other);
};

#endif // !1