#include "Utils.h"
bool isNumber(const string& str)
{
    return str.find_first_not_of("0123456789- ") == string::npos;
}
