#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "----------CALCOLO EQUAZIONE TANGENTE AD UN CIRCONFERENZA------------" << endl;

    float xP,yP,A,B,C=0;
    cout << "Inserire coordinate del punto separate da spazio: ";
    cin >> xP;
    cin >> yP;

    cout << "Inserire coefficenti A, B e C della circonferenza (x^2+y^2+Ax+By+C=0) separati da spazio: ";
    cin >> A;
    cin >> B;
    cin >> C;

    //cout << pow(xP,2)+pow(yP,2)+(A*xP)+(B*yP)+C;
    if (pow(xP,2)+pow(yP,2)+(A*xP)+(B*yP)+C==0)
            {
                cout << "Il punto appartiene alla circonferenza" << endl;
                cout << "L'equazione della tangente e': " << endl << "t: ";

                if (xP+(A/2)==0)
                    cout << "y=" << yP << endl;
                if (yP+(B/2)==0)
                    cout << "x=" << xP << endl;

                if (xP+(A/2)!=0 && yP+(B/2)!=0)
                {
                    if (xP+(A/2)!=0)
                        {
                        cout << (xP+(A/2));
                        if (yP+(B/2)>=0)
                            cout << "x+";
                        else
                            cout << "x";
                        }
                    if (yP+(B/2)!=0)
                        {
                        cout << yP+(B/2);
                        if ((((A*xP)/2)+((B*yP)/2)+C)>=0)
                            cout << "y+";
                        else
                            cout << "y";
                        }
                    if ((((A*xP)/2)+((B*yP)/2)+C)!=0)
                        cout << (((A*xP)/2)+((B*yP)/2)+C) << "=0" << endl;
                }

            }

    float xC=-A/2, yC=-B/2;
    float r=sqrt(pow(xC,2)+pow(yC,2)-C);
    float d=sqrt(pow(xP-xC,2)+pow(yP-yC,2));
    float f=xC-xP, g=-yC+yP, h=pow(yC,2)+pow(xC,2)-C;

    //cout << d << " " << r;
    if (d<r)
        cout << "Il punto e' interno, quindi non ci sono tangenti!" << endl;

    if (d>r)
    {
        cout << "Il punto e' esterno alla circonferenza" << endl << "Le equazioni delle tangenti sono:" << endl;

        float primo=pow(f,2)-h;
        float secondo=(2*f*g);
        float terzo=(pow(g,2)-h);
        float m1,m2=0;

        //cout << primo << " " << secondo << " " << terzo << endl;

        if (primo==0)
        {
            m1=-terzo/secondo;
            cout << "t1: y=";
                if (m1!=0)
                    {
                    cout << m1;
                    if (yP-m1*xP>0)
                        cout << "x+";
                    else
                        cout << "x";
                    }
                cout  << yP-m1*xP << endl;
            cout << "t2: x=" << xP << endl;
        }
        else
        {
            m1=((-secondo+sqrt(pow(secondo,2)-4*primo*terzo))/(2*primo));
            m2=((-secondo-sqrt(pow(secondo,2)-4*primo*terzo))/(2*primo));

            cout << "t1: y=";
            if (m1!=0)
                {
                cout << m1;
                if (yP-m1*xP>0)
                    cout << "x+";
                else
                    cout << "x";
                }
            cout  << yP-m1*xP << endl;

            cout << "t2: y=";
            if (m2!=0)
                {
                cout << m2;
                if (yP-m2*xP>0)
                    cout << "x+";
                else
                    cout << "x";
                }
            cout  << yP-m2*xP << endl;
        }

    }

    return 0;
}
