#include <fstream>
using namespace std;

#pragma once

#define MAX 100

class Display
{
public:
    int dimx, dimy;
    int matrice[MAX][MAX];

public:
	Display(void);
	~Display(void);

	void citire(ifstream&);
    int dimensiune();
    void afisare();
    void pixel(int, int, int);

    Display operator + (Display);
    Display operator - (Display);
    Display operator - ();
    Display operator ~ ();
    Display operator * (int);
    Display operator * (double);

};

