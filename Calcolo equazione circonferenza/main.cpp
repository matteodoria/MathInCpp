#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    float xC,yC,r=0;
    unsigned int caso=0;

    cout << "--------------CALCOLATORE EQUAZIONE CIRCONFERENZA---------------------" << endl;
    cout << "Seleziona uno dei seguenti casi:" << endl;
    cout << "1. Avendo centro e raggio" << endl;
    cout << "2. Avendo estremi del diametro" << endl;
    cout << "3. Avendo centro e tangente" << endl;
    cout << "4. Avendo due punti appartenti alla circonferenza e la retta del centro" << endl;
    cout << "5. Avendo tre punti di passaggio" << endl;

    cout << "Caso: ";
    cin >> caso;
    cout << endl;

    while (caso<1 || caso>5)
        {
            cout << "Inserisci un numero tra 1 e 5" << endl;
            cout << "Caso: ";
            cin >> caso;
            cout << endl;
        }

    switch(caso)
    {
        case 1:
            cout << "Inserisci le coordinate del centro (separate da spazio): ";
            cin >> xC >> yC;
            cout << "Inserisci il raggio: ";
            cin >> r;
            cout << endl;

            if (r>0)
            {
                cout << "L'equazione della circonferenza e':" << endl;

                if (-2*xC>0)
                    cout << "c: x^2+y^2+";
                else
                    cout << "c: x^2+y^2";

                if (xC!=0)
                    {
                        cout << -2*xC;
                        if (-2*yC>0)
                            cout << "x+";
                        else
                            cout << "x";
                    };
                if (yC!=0)
                    {
                        cout << -2*yC;
                        if (pow(xC,2)+pow(yC,2)-pow(r,2)>0)
                            cout << "y+";
                        else
                            cout << "y";
                    };

                if (pow(xC,2)+pow(yC,2)-pow(r,2)!=0)
                    cout << pow(xC,2)+pow(yC,2)-pow(r,2) << "=0" << endl;
                else
                    cout << "=0";
            }
            if (r==0)
                cout << "Il raggio e' nullo, la circonferenza e' degenere e corrisponde al punto: P(" << xC << ";" << yC << ")" << endl;
            if (r<0)
                cout << "Il raggio e' negativo percio' non esiste alcuna circonferenza!" << endl;
            break;

        case 2:
            {
            double xA,yA,xB,yB=0;

            cout << "Inserisci le coordinate del primo estremo (separate da spazio): ";
            cin >> xA >> yA;
            cout << "Inserisci le coordinate del secondo estremo (separate da spazio): ";
            cin >> xB >> yB;
            cout << endl;

            xC=(xA+xB)/2;
            yC=(yA+yB)/2;
            r=(pow(xB-xA,2)+pow(yB-yA,2))/4;

            if (r>0)
            {
                cout << "L'equazione della circonferenza e':" << endl;

                if (-2*xC>0)
                    cout << "c: x^2+y^2+";
                else
                    cout << "c: x^2+y^2";

                if (xC!=0)
                    {
                        cout << -2*xC;
                        if (-2*yC>0)
                            cout << "x+";
                        else
                            cout << "x";
                    };
                if (yC!=0)
                    {
                        cout << -2*yC;
                        if (pow(xC,2)+pow(yC,2)-pow(r,2)>0)
                            cout << "y+";
                        else
                            cout << "y";
                    };

                if (pow(xC,2)+pow(yC,2)-pow(r,2)!=0)
                    cout << pow(xC,2)+pow(yC,2)-pow(r,2) << "=0" << endl;
                else
                    cout << "=0";
            }
            if (r==0)
                cout << "Il raggio e' nullo, la circonferenza e' degenere e corrisponde al punto: P(" << xC << ";" << yC << ")" << endl;
            if (r<0)
                cout << "Il raggio e' negativo percio' non esiste alcuna circonferenza!" << endl;

            break;
            }

        case 3:
            {
                float A,B,C=0;

                cout << "Inserisci le coordinate del centro (separate da spazio): ";
                cin >> xC >> yC;
                cout << "Inserisci i coefficenti dell'equazione della tangente (Ax+By+C=0) (separati da spazio): ";
                cin >> A >> B >> C;
                cout << endl;

                r=((abs(A*xC+B*yC+C))/(sqrt(pow(A,2)+pow(B,2))));

                if (r>0)
            {
                cout << "L'equazione della circonferenza e':" << endl;

                if (-2*xC>0)
                    cout << "c: x^2+y^2+";
                else
                    cout << "c: x^2+y^2";

                if (xC!=0)
                    {
                        cout << -2*xC;
                        if (-2*yC>0)
                            cout << "x+";
                        else
                            cout << "x";
                    };
                if (yC!=0)
                    {
                        cout << -2*yC;
                        if (pow(xC,2)+pow(yC,2)-pow(r,2)>0)
                            cout << "y+";
                        else
                            cout << "y";
                    };

                if (pow(xC,2)+pow(yC,2)-pow(r,2)!=0)
                    cout << pow(xC,2)+pow(yC,2)-pow(r,2) << "=0" << endl;
                else
                    cout << "=0";
            }
            if (r==0)
                cout << "Il raggio e' nullo, la circonferenza e' degenere e corrisponde al punto: P(" << xC << ";" << yC << ")" << endl;
            if (r<0)
                cout << "Il raggio e' negativo percio' non esiste alcuna circonferenza!" << endl;
                break;

            }

        case 4:
            {
                float xA,yA,xB,yB,A,B,C=0;

                cout << "Inserisci le coordinate del primo punto di passaggio: ";
                cin >> xA >> yA;
                cout << "Inserisci le coordinate del secondo punto di passaggio: ";
                cin >> xB >> yB;
                cout << "Inserisci i coefficenti dell'equazione della retta del centro (Ax+By+C=0) (separati da spazio): ";
                cin >> A >> B >> C;
                cout << endl;

                float xM=(xA+xB)/2,yM=(yA+yB)/2,m=-((xB-xA)/(yB-yA));

                xC=(B*m*xM-B*yM-C)/(A+B*m);
                yC=m*xC-m*xM+yM;

                r=sqrt(pow(xA-xC,2)+pow(yA-yC,2));

                if (r>0)
            {
                cout << "L'equazione della circonferenza e':" << endl;

                if (-2*xC>0)
                    cout << "c: x^2+y^2+";
                else
                    cout << "c: x^2+y^2";

                if (xC!=0)
                    {
                        cout << -2*xC;
                        if (-2*yC>0)
                            cout << "x+";
                        else
                            cout << "x";
                    };
                if (yC!=0)
                    {
                        cout << -2*yC;
                        if (pow(xC,2)+pow(yC,2)-pow(r,2)>0)
                            cout << "y+";
                        else
                            cout << "y";
                    };

                if (pow(xC,2)+pow(yC,2)-pow(r,2)!=0)
                    cout << pow(xC,2)+pow(yC,2)-pow(r,2) << "=0" << endl;
                else
                    cout << "=0";
            }
            if (r==0)
                cout << "Il raggio e' nullo, la circonferenza e' degenere e corrisponde al punto: P(" << xC << ";" << yC << ")" << endl;
            if (r<0)
                cout << "Il raggio e' negativo percio' non esiste alcuna circonferenza!" << endl;
                break;

            }
        case 5:
            float xA,xB,xC,yA,yB,yC,A,B,C=0;

            cout << "Inserisci le coordinate del primo punto (separate da spazio): ";
            cin >> xA >> yA;
            cout << "Inserisci le coordinate del secondo punto (separate da spazio): ";
            cin >> xB >> yB;
            cout << "Inserisci le coordinate del terzo punto (separate da spazio): ";
            cin >> xC >> yC;
            cout << endl;

            if (xA==xB && xB==xC && yA==yB && yB==yC)
                cout << "I tre punti sono sovrapposti, la circonferenza e' degenere e corrisponde al punto P(" << xA << ";" << yA << ")\n";
            else
            {
                if (((yC-yA)/(yB-yA))!=((xC-xA)/(xB-xA)))
                {
                    float D,dA,dB,dC=0;

                    D=(xA*yB)+(yA*xC)+(xB*yC)-(xC*yB)-(yC*xA)-(xB*yA);
                    float tmp1=(-(pow(xA,2)+pow(yA,2))),tmp2=(-(pow(xB,2)+pow(yB,2))),tmp3=(-(pow(xC,2)+pow(yC,2)));
                    dA=(tmp1*yB)+(yA*tmp3)+(tmp2*yC)-(tmp3*yB)-(yC*tmp1)-(tmp2*yA);
                    dB=(xA*tmp2)+(tmp1*xC)+(xB*tmp3)-(xC*tmp2)-(tmp3*xA)-(xB*tmp1);
                    dC=(xA*yB*tmp3)+(yA*tmp2*xC)+(tmp1*xB*yC)-(xC*yB*tmp1)-(yC*tmp2*xA)-(tmp3*xB*yA);

                    A=dA/D;
                    B=dB/D;
                    C=dC/D;

                    if (A>0)
                        cout << "x^2+y^2+";
                    else
                        cout << "x^2+y^2";
                    if (A!=0)
                    {
                        cout << A;
                        if (B>0)
                            cout << "x+";
                        else
                            cout << "x";
                    }
                    if (B!=0)
                    {
                        cout << B;
                        if (C>0)
                            cout << "y+";
                        else
                            cout << "y";
                    }
                    if (C!=0)
                    cout << C;

                    cout << "=0" << endl;
                }
                else
                    cout << "I tre punti sono allineati e non passa alcuna circonferenza!";
            }
            break;
    }

    return 0;
}
