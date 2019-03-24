#include "MATRICE.h"
#include "VECTOR.h"
#include <fstream>

using namespace std;


matrice::matrice()
{
    m=0;
    a= nullptr;
}


matrice::matrice(int l)
{
    m=l;
    a= new vector[m];
}

matrice::matrice(const matrice &b)
{
    m=b.m;
    a=new vector[m];

    for(int i=0;i<m;i++)
        a[i]=b.a[i];
}


matrice::~matrice()
{

    delete[] a;
}

ifstream &operator>>(ifstream &in, matrice &b)
{
    if(b.m==0)
    {
        in>>b.m;
        b.a=new vector[b.m];
    }

    int size;
    in>>size;

    for(int i=0;i<b.m;i++)
    {
        b.a[i].setSize(size);
        in>>b.a[i];
    }

    return in;
}


istream &operator>>(istream &is, matrice &b)
{
    if(b.m==0)
    {
        cout<<"nr linii: ";
        is>>b.m;
        b.a=new vector[b.m];
    }

    int size;
    cout<<"nr coloane: ";
    is>>size;

    for(int i=0;i<b.m;i++)
    {
        b.a[i].setSize(size);
        is>>b.a[i];
    }

    return is;
}


ostream &operator<<(ostream &out, matrice &b)
{
    for(int i=0;i<b.m;i++)
        out<<b.a[i]<<endl;
    return out;
}


matrice matrice::operator+(matrice b)
{
    if(m!=b.m)
    {
        cout<<"matricele nu au aceiasi dimensiune"<<endl;
        matrice o;
        return o;
    }
    for(int i=0;i<m;i++)
       a[i]=a[i] + b.a[i];

    return *this;

}


matrice& matrice::operator=(matrice b){

    delete[] a;
    m=b.m;
    a=new vector[m];

    for(int i=0;i<m;i++)
        a[i]=b.a[i];

    return *this;
}


int matrice::get_rows()
{
    return m;
}


int matrice::get_columns()
{
    return a[0].n;
}


vector matrice::get_array(int i) {
    return a[i];
}










