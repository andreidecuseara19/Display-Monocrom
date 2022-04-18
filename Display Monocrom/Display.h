#include <fstream>
using namespace std;

#pragma once

#define MAX 50


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
    Display operator - ();
    Display operator ~ ();
    Display scalare(Display);


};

