#include <iostream>
#include <fstream>


using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

class vector
{
    friend class matrice;

private:

    int *v;
    int n;

public:
    // Constructor - Destructor:
    vector();
    explicit vector(int);
    vector(const vector&); // copy constructor
    ~vector();


    // setter/getter
    void setSize(int);
    int getSize();
    int get_int(int);


    // supraincarcare << >>:
    friend ifstream& operator>>(ifstream&,vector&);
    friend istream&  operator>>(istream&,vector&);
    friend ostream&  operator<<(ostream&,vector&);


    //op. overloading:
    vector& operator=(vector);
    int operator*(vector);
    vector operator+(vector);


    // Metode:
    int sum();
    void max();
    void sort();

};

#endif
