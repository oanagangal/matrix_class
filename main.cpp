#include <iostream>
#include "VECTOR.h"
#include "MATRICE.h"
#include <fstream>

using namespace std;

bool funct(matrice A,vector x,vector y)  // functia care verifica daca Ax=y
{
   if(A.get_columns()!=x.getSize()||A.get_rows()!=y.getSize())
    {
        cout<<"vectori incompatibili cu matricea A"<<endl;
        return false;
    }

    for(int i=0;i<A.get_rows();i++)
    {
        if (A.get_array(i) * x != y.get_int(i))
        {
            return false;
        }
    }

    return true;
}



int main() {

  ifstream f,g;

  f.open("matrice");
  g.open("vector");

  matrice C,B;
  f>>B>>C;
  cout<<B<<endl<<C<<endl;
  matrice X=C+B;
  cout<<X;
  //cout<<funct(B,z,w);
   
  g.close();
  f.close();

    return 0;
}
