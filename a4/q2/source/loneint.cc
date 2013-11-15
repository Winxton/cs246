#include "loneint.h"
#include <sstream>
using namespace std;

LoneInt::LoneInt(int num):num(num) {}

int LoneInt::evaluate() {
    return num;
}

string LoneInt::prettyprint() {
    stringstream ss;
    ss << num;
    return ss.str();
}

LoneInt::~LoneInt() {}
