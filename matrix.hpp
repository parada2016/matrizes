#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include "fracao.hpp"
class Matriz{
private:
    frac ** m;
    int dx, dy;
    void AllocArrays()
    {
        m = new frac * [dx];
        for(int i=0; i < dx; i++)
             m[i] =  new frac [dy];
    }

public:
    Matriz(int sizeX, int sizeY);
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

 Matriz inverte();
};

Matriz operator * (const Matriz& m1, const Matriz& m2)
    {
        Matriz p(m1.dx,m2.dy);
        frac f;

        for(int i=0; i < p.dx; i++)
        {
            for(int j=0; j < p.dy; j++)
            {
               p.m[i][j] = (frac){0,1};
               for(int k=0; k < m1.dy; k++)
               {
                   f = m1.m[i][k]*m2.m[k][j];
                   p.m[i][j] = p.m[i][j] + f;

               }
            }
         }
       return p;
    }

Matriz::Matriz (int sizeX, int sizeY):dx(sizeX),dy(sizeY)
{
 AllocArrays();

}

Matriz::Matriz(const Matriz & M):dx(M.dx),dy(M.dy)
{

AllocArrays();
for(int i=0; i < dx; i++)
    for(int j=0; j < dy; j++)
      m[i][j] = M.m[i][j];
}

Matriz& Matriz::operator=(const Matriz & M)
{
    if(this == &M) return *this;
    else
        {
            if(dx != M.dx || dy != M.dy )
            {
                this->~Matriz();
                dx = M.dx; dy = M.dy;
                AllocArrays();
            }
            for(int i=0; i < dx; i++)
            for(int j=0; j < dy; j++)
               m[i][j] = M.m[i][j];

        }
        return *this;
}

Matriz Matriz::inverte()
{
    Matriz A(dx,dy),B(dx,dy);
    A = *this;
    int i,j,k,m;
    int MatrixSize = dx;
    for(i=0; i < MatrixSize; i++ ){
        for(j=0; j < MatrixSize; j++)
        {
            if(i==j) B.m[i][j] = (frac){1,1} ;
            else B.m[i][j] = (frac){0,1};
        }
    }


    for(j=0; j < MatrixSize; j++)
    {
        i = j + 1;

        while(A.m[i-1][j] == 0)
            {
                if(i==MatrixSize) { exit(3); };
                i++;
            }

         frac * temp = A.m[i-1];
         A.m[i-1] = A.m[j];
         A.m[j] = temp;
         temp = B.m[i-1];
         B.m[i-1] = B.m[j];
         B.m[j] = temp;

         frac fator = 1 /A.m[j][j];
         for(k=0; k < MatrixSize; k++)
         {
             A.m[j][k] = fator * A.m[j][k];
             B.m[j][k] = fator * B.m[j][k];
         }
         for(m=0; m < MatrixSize; m++)
         {
             if(m != j)
             {
                 fator = -1*A.m[m][j];
                 for(k=0; k < MatrixSize; k++){
                 A.m[m][k] = A.m[m][k] + fator*A.m[j][k];
                 B.m[m][k] = B.m[m][k] + fator*B.m[j][k];
                 }
             }
         }
    }



    return B;
}


ostream& operator << (ostream& out, const Matriz& M)
{
   for(int i=0; i < M.dy;i++){
     out <<  "[";
     for(int j =0; j <  M.dx; j++){
      out << setw(5) << M.m[i][j] << ' ';
     }

    out << " ]" << '\n' << '\n';
   }
    return out;

}




#endif // __MATRIX_HPP__
