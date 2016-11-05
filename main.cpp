#include "matrix.hpp"
void demo_matriz();
void demo_determ();
void demo_equacao();

int main()
{
   demo_equacao();


    return 0;
}

void demo_equacao()
{
    // resolve equacões simultâneas pelo método da matriz inversa
    // Ax = B <=> x = inv(A)* B

// resultado: 3,4,5

    Matriz m(3,3), inv(3,3), b(3,1);
   //x.CriarId();

   //valores  de B[]
   b(0,0) = (frac){12,1}; b(1,0) = (frac) {12,1};  b(2,0) = (frac) {-16,1};
   // matriz de coeficientes

   m(0,0) = (frac){1,1}; m(0,1) = (frac) {  1,1};  m(0,2) = (frac) { 1,1};
   m(1,0) = (frac){2,1}; m(1,1) = (frac) { -1,1};  m(1,2) = (frac) { 2,1};
   m(2,0) = (frac){1,1}; m(2,1) = (frac) { -1,1};  m(2,2) = (frac) {-3,1};
   cout <<  "------------ matriz m -------------\n";
   cout << m;
   cout << "-------- matriz b ------------------\n";
   cout << b;
   inv = m.Inversa();
   Matriz solucao =  inv * b;
   cout << "---------solução x1,x2,x3 --------------------\n";
   cout << solucao;
   cout << "\n Determinante de m: " << m.Determ();

}

void demo_matriz()
{

    //exemplo tirado de  http://www.mtm.ufsc.br/~taneja/MatMap/node17.html
    Matriz m(3,3);

    m(0,0) = (frac){ 2,1}; m(0,1) = (frac){-3,1}; m(0,2) = (frac) { 4,1};
    m(1,0) = (frac){-1,1}; m(1,1) = (frac){ 2,1}; m(1,2) = (frac) {-3,1};
    m(2,0) = (frac){ 3,1}; m(2,1) = (frac){ 2,1}; m(2,2) = (frac) {-1,1};


   cout <<  "------------ matriz m -------------\n";
   cout << m;


   Matriz inv = m.Inversa();
   Matriz test = inv *m;
   cout <<  "----------- m x Inv de m ----------\n";
   cout << test;

    cout << "------------- Inv de m -------------\n";
    cout << inv;
    cout << "------------- Transposta de Inv de m -------------\n";
    cout << inv.Transposta();


}

void demo_determ()
{


    Matriz m(3,3),inv(3,3);

   m(0,0) = (frac){1,1}; m(0,1) = (frac) { 5,1}; m(0,2) = (frac){-2,1};
   m(1,0) = (frac){8,1}; m(1,1) = (frac) { 3,1}; m(1,2) = (frac) {0,1};
   m(2,0) = (frac){4,1}; m(2,1) = (frac) {-1,1}; m(2,2) = (frac) {2,1};
   cout <<  "------------ matriz m -------------\n";
   cout << m;
   cout << "Determinante: " << m.Determ();
   inv = m.Inversa();
   cout <<  "\n------------ inversa de m ---------\n";
   cout << inv;
   cout << "Determinante: " << inv.Determ();

}






