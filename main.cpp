#include "matrix.hpp"
void demo_matriz();
void demo_fracao();

int main()
{
   demo_matriz();

    return 0;
}

void demo_matriz()
{

    // http://www.mtm.ufsc.br/~taneja/MatMap/node17.html
    Matriz m(3,3);

    m(0,0) = (frac){ 2,1}; m(0,1) = (frac){-3,1}; m(0,2) = (frac) { 4,1};
    m(1,0) = (frac){-1,1}; m(1,1) = (frac){ 2,1}; m(1,2) = (frac) {-3,1};
    m(2,0) = (frac){ 3,1}; m(2,1) = (frac){ 2,1}; m(2,2) = (frac) {-1,1};


   cout <<  "------------ matriz m -------------\n";
   cout << m;


   Matriz inv = m.inverte();
   Matriz test = inv *m;
   cout <<  "----------- m x Inv de m ----------\n";
   cout << test;

    cout << "------------- Inv de m -------------\n";
    cout << inv;

}



void demo_fracao()
{
   frac f = {30,5};
   frac g = {0,4 };
   if(f == 6) cout << "f == 6" << '\n';
   if(g == 0) cout << "g == 0";


}



