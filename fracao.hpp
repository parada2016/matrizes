#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

int signal(int x)
{
    if(x >= 0) return(1);
    else return(-1);
}

typedef struct {
long numerador;
long denominador;

}frac;

long mdc(long x, long y)
{
    long a = abs(x);
    long b = abs(y);

    while(a !=b)
    {
        a  = (a > b)? a - b : b - a;
        b  = (b > a)? b - a : a - b;
    }
    return(a);

}

bool operator == (frac f, long x)
{
    long d;
    if((f.numerador < f.denominador) && (f.numerador != 0) ) return(false);
    if(f.numerador % f.denominador != 0) return(false);
    d = f.numerador/f.denominador;
    if(d == x)  return(true);
    else return(false);
}

frac operator / (frac f1, frac f2)
{
    frac f;
    f.numerador =  f1.numerador  * f2.denominador;
    f.denominador = abs(f1.denominador * f2.numerador);
    int den = (f.denominador >= 0)? f.denominador : -f.denominador;
    if(f == 0) { cerr << "Divizao por zero detectada. Abortando"; exit(1); }
     if(f.numerador != 0 && f.numerador != 1 && den != 1){
    long Mdc = mdc(f.denominador,f.numerador);
    f.denominador /= Mdc;
    f.numerador /= Mdc;
    }

    return(f);
}


frac operator * (frac f1, frac f2)
{
    frac f;

    f.numerador = f1.numerador * f2.numerador;
    f.denominador = f1.denominador * f2.denominador;
    int den = (f.denominador >= 0)? f.denominador : -f.denominador;
    if(f.numerador != 0 && f.numerador != 1 && den != 1)
    {
        int Mdc = mdc(f.denominador,f.numerador);
        f.denominador /= Mdc;
        f.numerador /= Mdc;
    }

    return(f);
}

frac operator * (int fator, frac f1)
{
    frac f;
    f.numerador = fator * f1.numerador;
    f.denominador = f1.denominador;

    long den = (f.denominador >= 0)? f.denominador : -f.denominador;
    if(f.numerador != 0 && f.numerador != 1 && den != 1)
    {
        long Mdc = mdc(f.denominador,f.numerador);
        f.denominador /= Mdc;
        f.numerador /= Mdc;
    }

    return(f);
}

frac operator / (long fator, frac f1)
{
    frac f;
    f.numerador = signal(f1.numerador)*fator*f1.denominador;
    f.denominador = abs(f1.numerador);
    long den = (f.denominador >= 0)? f.denominador : -f.denominador;
    if(f.numerador != 0 && f.numerador != 1 && den != 1)
    {
        int Mdc = mdc(f.denominador,f.numerador);
        f.denominador /= Mdc;
        f.numerador /= Mdc;
    }

    return(f);
}

long mmc(long x, long y)
{
    long a = (x > 0)? x : -x;
    long b = (y > 0)? y : -y;
    short divisor = 2;
    long prod = 1;
    int resto_a = a % divisor;
    int resto_b = b % divisor;
    while(a > 1 || b  > 1)
    {
        resto_a = a % divisor;
        resto_b = b % divisor;
        if(resto_a == 0 || resto_b == 0)
        {
            if(resto_a == 0) a = a/divisor;
            if(resto_b == 0) b = b/divisor;
            prod *= divisor;
        }
        else divisor += 1;
    }
    return(prod);

}



frac operator + (frac f1, frac f2)
{
    frac temp;

    int den = mmc(f1.denominador,f2.denominador);
    temp.numerador = (den/f1.denominador)*f1.numerador + (den/f2.denominador)*f2.numerador;
    temp.denominador = den;
    den = (temp.denominador >= 0)? temp.denominador : -temp.denominador;
    if(temp.numerador != 0 && temp.numerador != 1 && den != 1){
    int Mdc = mdc(temp.denominador,temp.numerador);
    temp.denominador /= Mdc;
    temp.numerador /= Mdc;
    }
    return(temp);

}

frac operator - (frac f1, frac f2)
{
    frac temp;

    int den = f1.denominador * f2.denominador;
    temp.numerador = (den/f1.denominador)*f1.numerador - (den/f2.denominador)*f2.numerador;
    if(temp.numerador == 0) { temp.denominador = 1; return (temp) ;}
    temp.denominador = den;
    den = (temp.denominador >= 0)? temp.denominador : -temp.denominador;
    if(temp.numerador != 0 && temp.numerador != 1 && den != 1){
    int Mdc = mdc(temp.denominador,temp.numerador);
    temp.denominador /= Mdc;
    temp.numerador /= Mdc;
    }
    return(temp);

}







bool operator > (frac f1, frac f2)
{
    double r1 = ((double)f1.numerador/(double)f1.denominador);
    double r2 = ((double)f2.numerador/(double)f2.denominador);
        return(r1 > r2);
}

bool operator >= (frac f1, frac f2)
{
    double r1 = ((double)f1.numerador/(double)f1.denominador);
    double r2 = ((double)f2.numerador/(double)f2.denominador);
        return(r1 >= r2);
}

bool operator < (frac f1, frac f2)
{
    double r1 = ((double)f1.numerador/(double)f1.denominador);
    double r2 = ((double)f2.numerador/(double)f2.denominador);
        return(r1 < r2);
}



bool operator <= (frac f1, frac f2)
{
    double r1 = ((double)f1.numerador/(double)f1.denominador);
    double r2 = ((double)f2.numerador/(double)f2.denominador);
        return(r1 <= r2);
}



ostream& operator << (ostream& out ,frac f)
{
    if(f.denominador != 1 && f.numerador != 0)
    out << f.numerador << '/' << f.denominador;
    else
        out << f.numerador;
    return out;
}

