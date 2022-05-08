#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
 using namespace std;
#define WHITE 1
#define GRAY 2
#define BLACK 3

 const int INF = std::numeric_limits<int>::max(); 

bool  isNumber(const string& str);
void myExit();