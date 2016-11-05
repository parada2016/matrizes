#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include "fracao.hpp"


/* Definição da Classe de Matriz que usa frações */
class Matriz{
private:
    frac ** m;
    int dy, dx;
    void AllocArrays();
    // para ser usado na eliminação de Gauss
   int MaiorPivot(int Coluna)
  {
    int imax = Coluna;
    int Linha;
    frac valor;
    frac Maior_Pivot = fracAbs(m[Coluna][Coluna]);
    for(Linha=Coluna; Linha < dy; ++Linha)
    {
        valor =fracAbs(m[Linha][Coluna]);
        if(valor > Maior_Pivot)
        {
            Maior_Pivot = valor;
            imax = Linha;
        }
    }
    return (imax);
}

public:
    Matriz(int Linhas, int Colunas);
    Matriz();
    Matriz(const Matriz& M);
    Matriz& operator = (const Matriz & M);
    frac& operator () (int i,int j)
    {
        return m[i][j];
    }

    const frac& operator () (int i,int j)const
    {
        return m[i][j];
    }



   friend  Matriz operator * (const Matriz& m1, const Matriz& m2);
   friend ostream& operator << (ostream& out, const Matriz& M);
   void CriarId();
   Matriz Inversa();
   Matriz Transposta();

frac Determ();

};




#endif // __MATRIX_HPP__
