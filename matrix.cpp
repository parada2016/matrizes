#include "matrix.hpp"


ostream& operator << (ostream& out, const Matriz& M)
{
    int i;


   for(i=0; i < M.dy;i++)
   {
     out <<  "[";
     for(int j =0; j <  M.dx; j++)
        out << setw(3) << M.m[i][j];
    out << "  ]" << '\n' << '\n';
   }
   return out;
}

void Matriz::AllocArrays()
 {
   m = new frac * [dy];
   for(int i=0; i < dy; i++)
    m[i] =  new frac [dx];
 }


Matriz operator * (const Matriz& m1, const Matriz& m2)
    {
        if(m1.dx != m2.dy)
        {
            cerr << "Matrizes não conforme para multiplicação";
            exit(4);
        }
        Matriz p(m1.dy,m2.dx);
        frac f;

        for(int i=0; i < m1.dy; ++i)
        {
            for(int j=0; j < m2.dx; ++j)
            {
               p.m[i][j] = (frac){0,1};
               for(int k=0; k < m1.dx; ++k)
               {
                   f = m1.m[i][k]*m2.m[k][j];
                   p.m[i][j] = p.m[i][j] + f;

               }
            }
         }
       return p;
    }

 void Matriz::CriarId()
 {
    for(int i=0; i < dx; i++ ){
     for(int j=0; j < dy; j++)
     {
      if(i==j) m[i][j] = (frac){1,1} ;
      else m[i][j] = (frac){0,1};
     }
    }

  }
frac Matriz::Determ()
{

  int i, j, k, imax;
  frac factor;
  frac det = {1,1};
  Matriz M(dx,dy);
  frac zero = {0,1};
  M = *this;
   /* do the elimination */
  for (i = 0; i < M.dx; i++) {
        imax = M.MaiorPivot(i);

      // se o maior valor é zero, a matriz
      // não tem solução
      if(M.m[imax][i] == 0) return zero;
      // só permuta se  havia um pivot maior
       if(imax != i) {
            //SwapRows(M.Buffer[i], M.Buffer[imax]);
            frac * Temp = M.m[i];
            M.m[i] = M.m[imax];
            M.m[imax] = Temp;

           det = -1*det;
       }

    /* eliminate the lower rows to achieve triangular zeroes */
    for (j = i + 1; j < M.dy; j++) {
      if (!(M.m[j][i] == 0)) {
	    factor = M.m[j][i] / M.m[i][i];
	    for (k = i; k < M.dy; k++) {
	     M.m[j][k] = M.m[j][k] - (factor * M.m[i][k]);
	    }
      }
    }
  }
  // o determinante é o produto dos elementos da diagonal
  // em uma matriz triangular

  for (i = 0; i < M.dy; i++)
    det = det * M.m[i][i];

  return det;
}


Matriz Matriz::Inversa()
{

    if(dx != dy)
    {
        cerr << "Somente matriz quadrada pode ser invertida";
        exit(4);
    }
    Matriz A(dx,dy),B(dx,dy);
    A = *this;
    int i,j,k,m;
    int MatrixSize = dx;

    B.CriarId();

    for(j=0; j < MatrixSize; j++)
    {
        i = j + 1;
        while(A.m[i-1][j] == 0)
         {
           if(i==MatrixSize) { cerr << "Matriz não é invertível";  exit(4); };
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

Matriz Matriz::Transposta()
{
    Matriz t(dy,dx);
    for(int i= 0; i < t.dy; i++)
        for(int j = 0; j < t.dx; j++)
    {
        t.m[i][j] = m[j][i];
    }
    return t;
}

Matriz::Matriz (int Linhas, int Colunas)
{
    dx = Colunas; dy = Linhas;
 AllocArrays();

}

Matriz::Matriz(const Matriz & M)
{
    dx = M.dx;
    dy = M.dy;

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






