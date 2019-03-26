#include "VECTOR.h"

using namespace std;


vector::vector()
{
    n=0;
    v= nullptr;
}


vector::vector(int size)
{
  n=size;
  v=new int(n);
}

vector::vector(const vector &p)
{
    //delete[] v;

    n=p.n;

    v=new int[n];

    for(int i=0;i<n;i++)
        v[i]=p.v[i];

}

vector::~vector()
{
  delete[] v;
}


void vector::setSize(int size)
{
    n=size;
}


int vector::getSize()
{
    return n;
}


int vector::get_int(int j)
{
    return v[j];
}



ifstream &operator>>(ifstream &in, vector &p)
 {
    if(p.n==0)
    {
        in >> p.n;
        p.v = new int[p.n];
    }

    if(p.v== nullptr)
         p.v=new int[p.n];


    for(int i=0;i<p.n;i++ )
      in>>p.v[i];

  return in;
  }



istream &operator>>(istream &is, vector &p)
{
    if(p.n==0)
    {
        cout<<"dimensiune : ";
        is>>p.n;
        p.v=new int[p.n];
    }

    if(p.v== nullptr)
        p.v=new int[p.n];

    for(int i=0;i<p.n;i++ )
    {
        cout<<"v["<<i<<"]= ";
        is>>p.v[i];
    }

    return is;
}



ostream &operator<<(ostream &out, vector &p)
 {
  for(int i=0;i<p.n;i++)
    out<<p.v[i]<<" ";
  return out;
 }



int vector::sum()
    {
      int s=0;
      for(int i=0;i<n;i++)
          s=s+v[i];
      return s;
    }


void vector::max()
{
    int m=0,i;
  for(i=1;i<n;i++)
      if(v[m]<v[i])
          m=i;

   cout<<" VAL MAX: "<<v[m]<<"  POZITIE: "<<m<<endl;
}


void vector::sort()
{
    int i,j, m=0;

    for(i=0;i<n-1;i++)
    {
        m=i;
        for(j=i;j<n;j++)
            if(v[m]>v[j])
                m=j;
        swap(v[i],v[m]);
    }
}



vector& vector::operator=(vector p){

    delete[]v;
    n=p.n;
    v=new int[n];

    for(int i=0;i<n;i++)
        v[i]=p.v[i];

    return *this;
}


int vector::operator*(vector p)
{
    if(p.n!=n)
    {
        cout<<"Vectorii nu au aceiasi dimensiune"<<endl;
        return -1;
    }

    int s=0;

    for( int i=0; i < n; i++)
       s=s+p.v[i] * v[i];

    return s;
}


vector vector::operator+(vector p)
{
    if(n!=p.n)
    {
        cout<<"vectorii nu au aceiasi dimensiune"<<endl;
        vector t;
        return t;
    }
    for(int i=0;i<n;i++)
       v[i]=v[i]+p.v[i];

    return *this;
}

int vector::operator[](int i)
{
    if(i>=n)
     cout<<"argument out of bound"<<endl;

    return get_int(i);
}
