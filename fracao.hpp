#ifndef __FRACAO_HPP__
#define __FRACAO_HPP__




#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;



typedef struct {
long numerador;
long denominador;

}frac;

frac fracAbs(frac f);

bool operator > (frac f1, frac f2);
bool operator < (frac f1, frac f2);

bool operator == (frac f1,frac f2);

bool operator == (frac f, long x);

frac operator / (frac f1, frac f2);

frac operator * (frac f1, frac f2);

frac operator * (int fator, frac f1);

frac operator / (long fator, frac f1);

frac operator + (frac f1, frac f2);

frac operator - (frac f1, frac f2);
ostream& operator << (ostream& out ,frac f);



#endif // __FRACAO_HPP__

