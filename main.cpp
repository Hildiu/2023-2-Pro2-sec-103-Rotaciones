/*---------------------------------
 * Dato de Entrada: +n ó -n,  [1 - 7]  o [-1  -7]
 *                  +n rotar a la derecha
 *                  -n rotar a la izquierda
 * Doto de Salida: mostrar el arreglo rotado
 * */

#include <iostream>
#include <iomanip>
using namespace std;

void imprimir(string *bts, int n);
void rotar(string *bts, int tam, int nr);
void rotarAlaDerecha(string *bts, int n);
void rotarAlaIzquierda(string *bts, int n);

int main()
{
  string bts[7] = {"JKook", "V", "Jimin", "Jin", "Suga", "RM", "J-Hope"};
  int n;

  cout << "Estado inicial:";
  imprimir(bts,7);
  cout << "\n\n";
  do {
    cout << "Ingrese numero de rotaciones: ";
    cin >> n;
  }while(n<-7 or n>7);
  rotar(bts,7,n);
  return 0;
}


void rotarAlaDerecha(string *bts, int n)
{
  string auxiliar = bts[n-1];
  for(int i=n-2; i>=0; i--)
    bts[i+1]=bts[i];
  bts[0]=auxiliar;
}

void rotarAlaIzquierda(string *bts, int n)
{
  string auxiliar=bts[0];
  for(int i=1; i<n; i++)
    bts[i-1] = bts[i];
  bts[n-1]= auxiliar;
}

void rotar(string *bts, int tam, int nr)
{
  if(nr==0)
    cout << "No hay rotacion!";
  else
    if(nr>0)  //--- rota a la derecha
      for(int i=0; i<nr; i++)
      {
        rotarAlaDerecha(bts, tam);
        imprimir(bts,tam);
      }
    else //--- rota a la izquierda
      for(int i=0; i<abs(nr); i++)
      {
        rotarAlaIzquierda(bts, tam);
        imprimir(bts, tam);
      }
}


void imprimir(string *bts, int n)
{
  cout <<"\n";
  for(int i=0; i<7; i++)
    cout << setw(8) << bts[i];
}