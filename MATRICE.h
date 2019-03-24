#include <iostream>
#include "VECTOR.h"

using namespace std;

#ifndef MATRICE_H
#define MATRICE_H

class matrice
{
    vector *a;
    int m;

public:

    // constructori/destructori:

    matrice();
    explicit matrice(int);
    matrice(const matrice&); //copy constructor
    ~matrice();

    // >> << overloading:
    friend ifstream& operator>>(ifstream&,matrice&);
    friend istream&  operator>>(istream&,matrice&);
    friend ostream&  operator<<(ostream&,matrice&);

    // op. overloading:
    matrice& operator=(matrice);
    matrice operator+(matrice);

    // setter/getter:
    int get_rows();
    int get_columns();
    vector& get_array(int);


};

#endif
