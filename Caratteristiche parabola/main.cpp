#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "----------------CARATTERISTICHE PARABOLA------------------" << endl;

    cout << "Scegli uno dei seguenti casi:" << endl;
    cout << "1. Parabola verticale (y=ax^2+bx+c)" << endl << "2. Parabola orizzontale (x=ay^2+by+c)" << endl;
    cout << "Caso: ";
    int r=0;
    cin >> r;
    float A,B,C=0;

    while (r<1 || r>2)
    {
        cout << "Inserisci un numero valido!! " << endl << "Caso: ";
        cin >> r;
    }
    switch (r)
        {
            case 1:
                {
                    cout << "Inserisci i coefficenti della parabola (separati da spazio): ";
                    cin >> A >> B >> C;

                    cout << "Asse -> a: x=" << -B/2*A << endl;
                    cout << "Vertice -> V(" << -B/2*A << ";" << (4*A*C-pow(B,2))/4*A << ")" << endl;
                    cout << "Fuoco -> F(" << -B/2*A << ";" << (1-pow(B,2)+4*A*C)/4*A << ")" << endl;
                    cout << "Direttrice -> d: y=" << (4*A*C-1-pow(B,2))/4*A << endl;
                    
                    break;
                }
            case 2:
                {
                    cout << "Inserisci i coefficenti della parabola (separati da spazio): ";
                    cin >> A >> B >> C;

                    cout << "Asse -> a: y=" << -B/2*A << endl;
                    cout << "Vertice -> V(" << (4*A*C-pow(B,2))/4*A << ";" << -B/2*A << ")" << endl;
                    cout << "Fuoco -> F(" << (1-pow(B,2)+4*A*C)/4*A << ";" << -B/2*A << ")" << endl;
                    cout << "Direttrice -> d: x=" << (4*A*C-1-pow(B,2))/4*A << endl;
                    
                    break;
                }
        }

    return 0;
}
