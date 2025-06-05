#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstdint>

#include <mach-o/dyld.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

string getExecutableDir() {
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) != 0) {
        cerr << "Errore: percorso eseguibile troppo lungo." << endl;
        exit(1);
    }
    // Ricava la directory
    return std::string(dirname(path));
}

string dir = getExecutableDir();
string path = dir + "/raggruppamenti.txt";
ofstream raggruppamenti(path);

int scelta()
{
    char risp='\0';
    while(risp!='S'&&risp!='s'&&risp!='N'&&risp!='n'){
    cout << "Ci sono elementi uguali? Gli elementi si possono ripetere?\n(S=Si'|N=No)\nRisposta: ";
    cin >> risp;
    if(risp=='S'||risp=='s')
    {
        risp='\0';
        while(risp!='S'&&risp!='s'&&risp!='N'&&risp!='n'){
        cout << "\nConta l'ordine? (ABC e' diverso da BAC?)\n(S=Si'|N=No)\nRisposta: ";
        cin >> risp;
        if(risp=='N'||risp=='n')
        {
            cout << "\nSi tratta di una COMBINAZIONE CON RIPETIZIONE!\n";
            return 6;
        }
        if(risp=='S'||risp=='s')
        {
            risp='\0';
            while(risp!='S'&&risp!='s'&&risp!='N'&&risp!='n'){
            cout << "\nOgni gruppo e' formato da tutti gli elementi possibili? Conta solo l'ordine?\n"
                 << "(S=Si'|N=No)\nRisposta: ";
            cin >> risp;
            if(risp=='S'||risp=='s')
            {
                cout << "\nSi tratta di una PERMUTAZIONE CON RIPETIZIONE!\n";
                return 4;
            }
            if(risp=='N'||risp=='n')
            {
                cout << "\nSi tratta di una DISPOSIZIONE CON RIPETIZIONE!\n";
                return 2;
            }
            }
        }
        }
    }
    if(risp=='N'||risp=='n')
    {
        risp='\0';
        while(risp!='S'&&risp!='s'&&risp!='N'&&risp!='n'){
        cout << "\nConta l'ordine? (ABC e' diverso da BAC?)\n(S=Si'|N=No)\nRisposta: ";
        cin >> risp;
        if(risp=='N'||risp=='n')
        {
            cout << "\nSi tratta di una COMBINAZIONE SEMPLICE!\n";
            return 5;
        }
        if(risp=='S'||risp=='s')
        {
            risp='\0';
            while(risp!='S'&&risp!='s'&&risp!='N'&&risp!='n'){
            cout << "\nOgni gruppo e' formato da tutti gli elementi possibili? Conta solo l'ordine?\n"
                 << "(S=Si'|N=No)\nRisposta: ";
            cin >> risp;
            if(risp=='S'||risp=='s')
            {
                cout << "\nSi tratta di una PERMUTAZIONE SEMPLICE!\n";
                return 3;
            }
            if(risp=='N'||risp=='n')
            {
                cout << "\nSi tratta di una DISPOSIZIONE SEMPLICE!\n";
                return 1;
            }
            }
        }
        }
    }
    }
}

void stampa(char* p, int dimensione)
{
    for(int i=0; i<dimensione; i++)
        {cout << p[i]; 
         raggruppamenti << p[i];
    }
    cout << endl;
    raggruppamenti << endl;
}

bool controllo(int* usciti, int dimensione, int n)
{
    bool flag=false;
    for(int i=0; i<dimensione; i++)
    {
        if(n==usciti[i])
            {
                flag= true;
                break;
            }
    }
    return flag;
}

void disposizioniripetute(char* p, char* elementi, int n, int k, int j)
{
    for(int i=0; i<n; i++)
    {
        p[j]=elementi[i];

        if(j==(k-1))
            stampa(p, k);
        else
        {
            int* jp = new int[1];
            jp[0]=j+1;
            disposizioniripetute(p, elementi, n, k, *jp);
        }
    }
}

void disposizionisemplici(char* p, char* elementi, int n, int k, int j, int m, int* usciti)
{
    for(int i=0; i<n; i++)
    {
        if(!(controllo(usciti, n, i)))
        {
            usciti[m]=i;
            int* mp = new int[1];
            mp[0]=m+1;

            p[j]=elementi[i];

            if(j==(k-1))
                stampa(p, k);
            else
            {
                int* jp = new int[1];
                jp[0]=j+1;
                disposizionisemplici(p, elementi, n, k, *jp, *mp, usciti);
            }
        }
    }
    for(int i=j; i<n; i++)
        usciti[i]=(n+1);
}

bool giauscito(string* combinazioni, int dimensioni, string a)
{
    bool flag = false;
    for(int i=0; i<dimensioni; i++)
        if(a==combinazioni[i])
        {
            flag=true;
            break;
        }
    return flag;
}

void elementiuguali(char* elementi, int dimensione, int* hr)
{
    char* elementi2 = new char[dimensione];

    for(int i=0; i<dimensione; i++)
        elementi2[i]=elementi[i];

    int m=0, n=1;
    for(int i=0; i<dimensione-1; i++)
    {
        if(elementi2[i]!='\0')
            {
                for(int j=i+1; j<dimensione; j++)
                {
                    if(elementi2[j]==elementi2[i])
                    {
                        n++;
                        //cout << n << endl;
                        hr[m]=n;
                        elementi2[j]='\0';
                    }
                    //else cout << elementi[j] << " non uguale a " << elementi[i] << endl;
                }
                if(n>1)
                    m++;
                n=1;
                //system("pause");
            }
    }
}

void permutazioniripetute(char* p, char* elementi, int n, int k, int j, int m, int* usciti, int D, int* c, string* combinazioni)
{
    for(int i=0; i<n; i++)
    {
        if(!(controllo(usciti, n, i)))
        {
            usciti[m]=i;
            int* mp = new int[1];
            mp[0]=m+1;

            p[j]=elementi[i];

            if(j==(k-1) ){

                if(!giauscito(combinazioni, D, string(p)))
                {
                    stampa(p, k);
                    combinazioni[*c]=string(p);
                    c[0]=c[0]+1;
                }
            }
            else
            {
                int* jp = new int[1];
                jp[0]=j+1;
                permutazioniripetute(p, elementi, n, k, *jp, *mp, usciti, D, c, combinazioni);
            }
        }
    }
    for(int i=j; i<n; i++)
        usciti[i]=(n+1);
}

void combinazionisemplici(char* p, char* elementi, int n, int k, int j, int inizio_i, int fine_i)
{
    for(int i=inizio_i; i<fine_i; i++)
    {
        p[j]=elementi[i];

        if(j==k-1)
            stampa(p, k);
        else
        {
            int* jp = new int[1];
            jp[0]=j+1;
            int* fine_ip = new int[1];
            fine_ip[0] = fine_i+1;
            inizio_i=i+1;
            combinazionisemplici(p, elementi, n, k, *jp, inizio_i,  *fine_ip);
        }
    }

}

void combinazioniripetute(char* p, char* elementi, int n, int k, int j, int inizio_i)
{
    for(int i=inizio_i; i<n; i++)
    {
        p[j]=elementi[i];

        if(j==k-1)
            stampa(p, k);
        else
        {
            int* jp = new int[1];
            jp[0]=j+1;
            combinazioniripetute(p, elementi, n, k, *jp, i);
        }
    }
}

uintmax_t fattoriale(int n)
{
    if (n==0)
        return 1;
    else
        return n*fattoriale(n-1);
}

uintmax_t ris(int n, int k)
{
    int risu=1;
    while(n!=k)
    {
        risu*=n;
        n--;
        ris(n,k);
    }
    return risu;
}

int main()
{
    char again = 'n';
    
    while(again=='n' || again=='N'){
        cout << "\n---------------------------CALCOLO COMBINATORIO---------------------------\n";
        cout << "Guida alla scelta della tipologia\n";
    
        int risposta=scelta();
    
        cout << "--------------------------------------------------------------------------\n";
    
        switch(risposta)
        {
        case 1: //disposizione semplice
            {
                unsigned int n=0, k=1;
                uintmax_t D=1;
    
                while(k>n || k==0 || n==0)
                {
                    cout << "Inserisci il numero di elementi: "; cin >> n;
                    cout << "Inserisci il numero di elementi per ogni gruppo: "; cin >> k;
                }
    
                if(n<=20)
                    D=fattoriale(n)/fattoriale(n-k);
                else
                    D=ris(n,n-k);
    
                cout << "Numero totale disposizioni: " << D << endl;
    
                char* elementi = new char [n];
    
                for(int i=0; i<n; i++)
                {
                    cout << "Inserisci elemento " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p= new char[k];
                int* usciti = new int[k];
    
                for(int i=0; i<k; i++)
                    usciti[i]=n+1;
    
                cout << "Disposizioni: \n";
    
                disposizionisemplici(p, elementi, n, k, 0, 0, usciti);
                break;
            }
        case 2: //disposizione ripetuta
            {
                unsigned int n=0, k=0;
                uintmax_t D=0;
    
                while(n==0 || k==0){
                    cout << "Inserisci il numero di elementi: "; cin >> n;
                    cout << "Inserisci il numero di elementi per ogni gruppo: "; cin >> k;
                }
    
                D=pow(n,k);
    
                cout << "Numero totale disposizioni: " << D << endl;
                cout << "Inserisci gli elementi:\n";
    
                char* elementi = new char[n];
    
                for (int i=0; i<n; i++){
                    cout << "Elemento " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p= new char[k];
                int* j= new int[1];
    
                cout << "Disposizioni: \n";
                disposizioniripetute(p, elementi, n, k, *j);
                break;
            }
        case 3: //permutazione semplice
            {
                unsigned n=0;
                uintmax_t D=0;
    
                while(n==0)
                    {cout << "Inserisci numero di elementi da permutare: "; cin >> n;}
    
                D=fattoriale(n);
                cout << "Numero totale permutazioni: " << D << endl;
    
                char* elementi = new char [n];
    
                for(int i=0; i<n; i++)
                {
                    cout << "Inserisci elemento " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p= new char[n];
                int* j= new int[1];
                int* m= new int[1];
                int* usciti = new int[n];
    
                for(int i=0; i<n; i++)
                    usciti[i]=n+1;
    
                cout << "Permutazioni: \n";
    
                disposizionisemplici(p, elementi, n, n, *j, *m, usciti);
                break;
            }
        case 4: //permutazione ripetuta
            {
                int n=0;
    
                while(n==0)
                {cout << "Inserisci il numero di elementi: "; cin >> n;}
    
                char* elementi = new char[n];
    
                for(int i=0; i<n; i++)
                {
                    cout << "Inserisci elemento " << i+1 << ": "; cin >> elementi[i];
                }
    
                int* hr=new int[n];
    
                for(int i=0; i<n; i++)
                    hr[i]=1;
    
                elementiuguali(elementi, n, hr);
    
                uintmax_t denominatore=1, D=0;
    
                for(int i=0; i<n || hr[i]==1; i++)
                    denominatore*=fattoriale(hr[i]);
                //cout << denominatore;
    
                D=fattoriale(n)/denominatore;
                cout << "Numero totale permutazioni: " << D << endl;
                system("pause");
    
    
                char* p= new char[n];
                int* j= new int[1];
                int* m= new int[1];
                int* c= new int[1];
                int* usciti = new int[n];
                string* combinazioni = new string[2*D];
    
                for(int i=0; i<n; i++)
                        usciti[i]=n+1;
    
                cout << "Permutazioni: \n";
                permutazioniripetute(p, elementi, n, n, *j, *m, usciti, D, c, combinazioni);
    
                break;
            }
        case 5: //combinazione semplice
            {
                unsigned int n=0, k=1;
                uintmax_t D=1;
    
                while(k>n || k==0 || n==0)
                    {
                        cout << "Inserisci il numero di elementi: "; cin >> n;
                        cout << "Inserisci il numero di elementi per ogni gruppo: "; cin >> k;
                    }
    
                D=fattoriale(n)/( fattoriale(k)*fattoriale(n-k) );
    
                cout << "Numero totale di combinazioni: " << D << endl;
    
                char* elementi = new char [n];
    
                for(int i=0; i<n; i++)
                    {
                        cout << "Inserisci elemento " << i+1 << ": "; cin >> elementi[i];
                    }
    
                char* p = new char[k];
    
                cout << "Combinazioni: \n";
                combinazionisemplici(p, elementi, n, k, 0, 0, n-(k-1));
    
                break;
            }
        case 6: //combinazione ripetuta
            {
                unsigned int n=0, k=0;
                uintmax_t D=0;
    
                while(k==0 || n==0){
                cout << "Inserisci il numero di elementi: "; cin >> n;
                cout << "Inserisci il numero di elementi per ogni gruppo: "; cin >> k;}
    
                D=fattoriale(n+k-1)/( fattoriale(k)*fattoriale(n-1) );
    
                cout << "Numero totale di combinazioni: " << D << endl;
    
                cout << "Inserisci gli elementi:\n";
                char* elementi = new char[n];
    
                for (int i=0; i<n; i++){
                    cout << "Elemento " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p = new char[k];
    
                cout << "Combinazioni: \n";
                combinazioniripetute(p, elementi, n, k, 0, 0);
    
                break;
            }
        }
    
        cout << "\nVuoi uscire? (S=Sì|N=No)\n";
        cin >> again;
             
    }

    raggruppamenti.close();

    return 0;
}
