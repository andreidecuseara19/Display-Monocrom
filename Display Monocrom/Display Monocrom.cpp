#include <iostream>
#include <fstream>
#include "Display.h"

using namespace std;
#define MAX 50

void displaymenu()
{
    cout << " ===================================================== \n";
    cout << " \t\tMONOCHROME DISPLAY MENU \t \n ";
    cout << "===================================================== \n";
    cout << " 1.Print out the first matrix\n";
    cout << " 2.Print out the second matrix\n";
    cout << " 3.Adding the first two matrices\n";
    cout << " 4.Inverting the first matrix\n";
    cout << " 5.Scaling up by a factor of 2:\n";
    cout << " 6.Scaling down by 0.5:\n";
    cout << " 7.Deleting the first matrix:\n";
    cout << " 8.Draw by pixels:\n";
    cout << "\n 9.Exit the program \n";
    cout << " ===================================================== \n";
}

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

    displaymenu();
    int yourchoice;
    do
    {
        cout << "Enter your choice(1-8) (To exit enter 9): ";
        cin >> yourchoice;
        switch (yourchoice)
        {
        case 1:
        {
            cout << "M1 displayed here:\n" << endl;
            m1.afisare();
            break;
        }
        case 2:
        {
            cout << "M2 displayed here:\n" << endl;
            m2.afisare();
            break;
        }
        case 3:
        {
            cout << "M1 added with M2:\n" << endl;
            m1 + m2;
            m1.afisare();
            break;
        }
        case 4:
        {
            cout << "M1 inverted:\n" << endl;
            -m1;
            m1.afisare();
            break;
        }
        case 5:
        {
            cout << "M1 scaled up by a factor of 2:\n" << endl;
            m1 * 2;
            m1.afisare();
            break;
        }
        case 6:
        {
            cout << "M1 scaled down by a factor of 0.5:\n" << endl;
            m1 * 0.5;
            m1.afisare();
            break;
        }
        case 7:
        {
            cout << "M1 deleted:\n" << endl;
            ~m1;
            m1.afisare();
            break;
        }
        case 8:
        {
            int valpix;
            int xpix;
            int ypix;
            cout << "\nWhat pixel do you want to modify? Keep in mind that";
            m1.dimensiune();
            cout << "(First number will be the X and the second number will be the Y)\n";
            cin >> xpix;
            cin >> ypix;
            cout << "Should the pixel be on?\n";
            cin >> valpix;
            m1.pixel(xpix, ypix, valpix);
            cout << "Here is your masterpiece:\n";
            m1.afisare();
            break;
        }
        case 9:
        {
                return 0;
            break;
        }
        default:
        {
            cout << "\nInvalid input!\n" << endl;
            break;
        }
        }
        if (yourchoice > 9 || yourchoice < 1)
            return 0;
    } while (true);

    
/*
    m1.pixel(0, 0, 0);

    m1.afisare();
    m2.afisare();

    cout << "M1 added with M2:\n" << endl;
    m1 + m2;
    m1.afisare();
    
    cout << "M1 inverted:\n" << endl;
    -m1;
    m1.afisare();

    cout << "M1 scaled up by a factor of 2:\n" << endl;
    m1 * 2;
    m1.afisare();

    cout << "M1 minus M3:\n" << endl;
    m1 - m3;
    m1.afisare();

    cout << "M1 scaled down by a factor of 0.5:\n" << endl;
    m1 * 0.5;
    m1.afisare();

    cout << "M1 deleted:\n" << endl;
    ~m1;
    m1.afisare();
*/

    matricetext.close();
    matricetext2.close();

    return 0;
}
