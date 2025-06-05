#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "------------------EQUAZIONE TANGENTE ALLA PARABOLA---------------------" << endl;

    cout << "Inserisci coefficenti parabola (y=ax^2+bx+c) separati da spazio: ";
    float a,b,c=0;
    cin >> a >> b >> c;
    cout << "Inserisci coordinate punto (separate da spazio): ";
    float xP,yP=0;
    cin >> xP >> yP;

    if (yP==a*pow(xP,2)+b*xP+c)
        {
            cout << "Il punto appartiene alla parabola, l'equazione della tangente e': " << endl;
            cout << "t: y=";
            if (2*a*xP+b!=0)
                {
                   cout << 2*a*xP+b;
                   if (b*xP+2*c-yP>0)
                    cout << "x+";
                   else
                    {
                        cout << "x";
                        if (b*xP+2*c-yP!=0)
                            cout << b*xP+2*c-yP;
                    }

                }
            else
                cout << b*xP+2*c-yP;
        }
    else
        {
            float s=-4*a*xP-2*b, t=pow(b,2)-4*a*c+4*a*yP;

            float m1=(-s+sqrt(pow(s,2)-4*t))/2;
            float m2=(-s-sqrt(pow(s,2)-4*t))/2;

            cout << "Equazione tangenti: " << endl;
            cout << "t1: y=" << m1;
            if (yP-m1*xP>0)
                cout << "x+" << yP-m1*xP << endl;
            else
            {
                cout << "x";
                if (yP-m1*xP!=0)
                    cout << yP-m1*xP << endl;
                else
                    cout << endl;
            }
            cout << "t2: y=" << m2;
            if (yP-m2*xP>0)
                cout << "x+" << yP-m2*xP << endl;
            else
            {
                cout << "x";
                if (yP-m2*xP!=0)
                    cout << yP-m2*xP << endl;
                else
                    cout << endl;
            }
        }

    return 0;
}
