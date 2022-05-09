#include <iostream>
#include <fstream>
#include "Display.h"


//#define MAX 50

using namespace std;

//Constructor
Display::Display(void)
{
	dimx=0;
	dimy=0;

	cout << "|-|" << endl << endl;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			this->matrice[i][j] = 0;
		}
	}

}

//Destructor
Display::~Display(void)
{
}

//Functia de citire a unei imagini din fisier
void Display::citire(ifstream& stream)
{
	int i=0, j=0;

	do
	{
		char ch = stream.get();
		if (ch == '0')
		{
			matrice[i][j] = 0;
			j++;
		}

		if (ch == '1')
		{
			matrice[i][j] = 1;
			j++;
		}
		if( ch == '\n') // se trece la randul urmator
		{
			i++;
			j=0;
		}

		if((int)ch == -1) // s-a ajuns la eof si a fost citit ultimul rand
			i++;

	}while (!stream.eof());

	dimx = i;
	dimy = j;
}

//Functia de afisare a dimensiunii unei imagini
int Display::dimensiune()
{
	cout << dimx << ' ' << dimy << endl << endl;
	return (dimx * dimy);
}

//Functia de afisare a unei imagini
void Display::afisare()
{
	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			if (this->matrice[i][j] == 0)
				cout << "0 ";
			else
				cout << "1 ";
		}
		cout << endl;
	}
	cout << endl;
}

//Functia de editare a unui pixel
void Display::pixel(int i, int j, int valoare)
{
	this->matrice[i][j] = valoare;
}

//Functia de compunere a doua imagini
Display Display::operator+(Display b)
{
	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			matrice[i][j] += b.matrice[i][j];
			if (matrice[i][j] > 1)
				matrice[i][j] = 1;
		}
	}
	return Display();
}

//Functia de scadere a doua imagini
Display Display::operator-(Display b)
{
	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			matrice[i][j] -= b.matrice[i][j];
			if (matrice[i][j] < 0)
				matrice[i][j] = 0;
		}
	}
	return Display();
}

//Functia de inversare a imaginii
Display Display::operator-()
{
	for (int i = 0; i < this->dimx; i++)
	{
		for (int j = 0; j < this->dimy; j++)
		{
			if (this->matrice[i][j] == 0)
				this->matrice[i][j] = 1;
			else
				this->matrice[i][j] = 0;
		}
	}
	return Display();
}

//Functia de stergere a imaginii
Display Display::operator~()
{
	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			this->matrice[i][j] = 0;
		}
	}
	return Display();
}

//Functia de scalare a unei imagini folosind un int ca multiplicator
Display Display::operator*(int mult)
{
	
	Display backup;
	backup.dimx = this->dimx;
	backup.dimy = this->dimy;

	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			backup.matrice[i][j] = this->matrice[i][j];
		}
	}

	dimx = dimx * mult;
	dimy = dimy * mult;
	int icount, jcount;

	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			icount = div(i, mult).quot;
			jcount = div(j, mult).quot;
			matrice[i][j] = backup.matrice[icount][jcount];
		}
	}
	return Display();
}

//Functia de scalare a unei imagini folosind un double ca multiplicator
Display Display::operator*(double mult)
{

	Display backup;
	backup.dimx = this->dimx;
	backup.dimy = this->dimy;

	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			backup.matrice[i][j] = this->matrice[i][j];
		}
	}

	dimx = (int)((double)dimx * mult);
	dimy = (int)((double)dimy * mult);
	int icount, jcount;

	for (int i = 0; i < dimx; i++)
	{
		for (int j = 0; j < dimy; j++)
		{
			icount = (int)((double)i / mult);
			jcount = (int)((double)j / mult);
			matrice[i][j] = backup.matrice[icount][jcount];
		}
	}
	return Display();
}