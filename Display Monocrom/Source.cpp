#include <iostream>
#include <fstream>
#include "Display.h"

using namespace std;
#define MAX 50


int main()
{
    ifstream matricetext;
    matricetext.open("matricetext.txt");

    Display m1;
    m1.citire(matricetext);

   // m1.construct(); - se va folosi constructorul !!
   // m1.dimx = 6; - rezulta prin citirea din fisier
   // m1.dimy = 2; - rezulta prin citirea din fisier
    m1.afisare();

    matricetext.close();
	cin.get();

    return 0;
}
