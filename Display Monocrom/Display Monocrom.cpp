#include <iostream>
#include <fstream>
#include "Display.h"

using namespace std;
#define MAX 50


int main()
{
    ifstream matricetext;
    ifstream matricetext2;
    ifstream matricetext3;
    matricetext.open("matricetext.txt");
    matricetext2.open("matricetext2.txt");
    matricetext3.open("matricetext3.txt");

    Display m1;
    Display m2;
    Display m3;
    m1.citire(matricetext);
    m2.citire(matricetext2);
    m3.citire(matricetext3);

    m1.dimensiune();

    m1.pixel(0, 0, 0);

    m1.afisare();
    m2.afisare();

    m1 + m2;
    m1.afisare();
    
    -m1;
    m1.afisare();

    m1 * 2;
    m1.afisare();

    m1 - m3;
    m1.afisare();

    m1 * 0.5;
    m1.afisare();

    ~m1;
    m1.afisare();

    matricetext.close();
    matricetext2.close();

    return 0;
}
