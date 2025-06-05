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
string path = dir + "/groupings.txt";
ofstream raggruppamenti(path);

int scelta()
{
    char risp='\0';
    while(risp!='S'&&risp!='s'&&risp!='N'&&risp!='n'){
    cout << "Are there identical elements? Can elements be repeated?\n(Y=Yes|N=No)\nAnswer: ";
    cin >> risp;
    if(risp=='Y'||risp=='y')
    {
        risp='\0';
        while(risp!='Y'&&risp!='y'&&risp!='N'&&risp!='n'){
        cout << "\nDoes the order count? (Is 'ABC' different from 'BAC'?)\n(Y=Yes|N=No)\nAnswer: ";
        cin >> risp;
        if(risp=='N'||risp=='n')
        {
            cout << "\nIt is a COMBINATION WITH REPETITION!\n";
            return 6;
        }
        if(risp=='Y'||risp=='y')
        {
            risp='\0';
            while(risp!='Y'&&risp!='y'&&risp!='N'&&risp!='n'){
            cout << "\nDoes each group consist of all possible elements? Does only the order count?\n"
                 << "(Y=Yes|N=No)\nAnswer: ";
            cin >> risp;
            if(risp=='Y'||risp=='y')
            {
                cout << "\nIt is a PERMUTATION WITH REPETITION!\n";
                return 4;
            }
            if(risp=='N'||risp=='n')
            {
                cout << "\nIt is a DISPOSITION WITH REPETITION!\n";
                return 2;
            }
            }
        }
        }
    }
    if(risp=='N'||risp=='n')
    {
        risp='\0';
        while(risp!='Y'&&risp!='y'&&risp!='N'&&risp!='n'){
        cout << "\nDoes the order count? (Is 'ABC' different from 'BAC'?)\n(Y=Yes|N=No)\nAnswer: ";
        cin >> risp;
        if(risp=='N'||risp=='n')
        {
            cout << "\nIt is a SIMPLE COMBINATION!!\n";
            return 5;
        }
        if(risp=='Y'||risp=='y')
        {
            risp='\0';
            while(risp!='Y'&&risp!='y'&&risp!='N'&&risp!='n'){
            cout << "\nDoes each group consist of all possible elements? Does only the order count?\n"
                 << "(S=Si'|N=No)\nAnswer: ";
            cin >> risp;
            if(risp=='Y'||risp=='y')
            {
                cout << "\nIt is a SIMPLE PERMUTATION!\n";
                return 3;
            }
            if(risp=='N'||risp=='n')
            {
                cout << "\nIt is a SIMPLE DISPOSITION!\n";
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
        {cout << p[i]; raggruppamenti << p[i];}
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
            
                }
                if(n>1)
                    m++;
                n=1;
                
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
        cout << "\n---------------------------COMBINATORICS---------------------------\n";
        cout << "Type selection guide\n";
    
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
                    cout << "Insert the number of elements: "; cin >> n;
                    cout << "Insert the number of elements for each group: "; cin >> k;
                }
    
                if(n<=20)
                    D=fattoriale(n)/fattoriale(n-k);
                else
                    D=ris(n,n-k);
    
                cout << "Total number of dispositions: " << D << endl;
    
                char* elementi = new char [n];
    
                for(int i=0; i<n; i++)
                {
                    cout << "Insert element " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p= new char[k];
                int* usciti = new int[k];
    
                for(int i=0; i<k; i++)
                    usciti[i]=n+1;
    
                cout << "Dispositions: \n";
    
                disposizionisemplici(p, elementi, n, k, 0, 0, usciti);
                break;
            }
        case 2: //disposizione ripetuta
            {
                unsigned int n=0, k=0;
                uintmax_t D=0;
    
                while(n==0 || k==0){
                    cout << "Insert the number of elements: "; cin >> n;
                    cout << "Insert the number of elements for each group: "; cin >> k;
                }
    
                D=pow(n,k);
    
                cout << "Total number of dispositions: " << D << endl;
    
                char* elementi = new char[n];
    
                for (int i=0; i<n; i++){
                    cout << "Insert element " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p= new char[k];
                int* j= new int[1];
    
                cout << "Dispositions: \n";
                disposizioniripetute(p, elementi, n, k, *j);
                break;
            }
        case 3: //permutazione semplice
            {
                unsigned n=0;
                uintmax_t D=0;
    
                while(n==0)
                    {cout << "Insert the number of elements to permute: "; cin >> n;}
    
                D=fattoriale(n);
                cout << "Total number of permutations: " << D << endl;
    
                char* elementi = new char [n];
    
                for(int i=0; i<n; i++)
                {
                    cout << "Insert element " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p= new char[n];
                int* j= new int[1];
                int* m= new int[1];
                int* usciti = new int[n];
    
                for(int i=0; i<n; i++)
                    usciti[i]=n+1;
    
                cout << "Permutations: \n";
    
                disposizionisemplici(p, elementi, n, n, *j, *m, usciti);
                break;
            }
        case 4: //permutazione ripetuta
            {
                int n=0;
    
                while(n==0)
                {cout << "Insert the number of elements: "; cin >> n;}
    
                char* elementi = new char[n];
    
                for(int i=0; i<n; i++)
                {
                    cout << "Insert element " << i+1 << ": "; cin >> elementi[i];
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
                cout << "Total number of permutations: " << D << endl;
    
    
                char* p= new char[n];
                int* j= new int[1];
                int* m= new int[1];
                int* c= new int[1];
                int* usciti = new int[n];
                string* combinazioni = new string[2*D];
    
                for(int i=0; i<n; i++)
                        usciti[i]=n+1;
    
                cout << "Permutations: \n";
                permutazioniripetute(p, elementi, n, n, *j, *m, usciti, D, c, combinazioni);
    
                break;
            }
        case 5: //combinazione semplice
            {
                unsigned int n=0, k=1;
                uintmax_t D=1;
    
                while(k>n || k==0 || n==0)
                    {
                        cout << "Insert the number of elements: "; cin >> n;
                        cout << "Insert the number of elements for each group: "; cin >> k;
                    }
    
                D=fattoriale(n)/( fattoriale(k)*fattoriale(n-k) );
    
                cout << "Total number of combinations: " << D << endl;
    
                char* elementi = new char [n];
    
                for(int i=0; i<n; i++)
                    {
                        cout << "Insert element " << i+1 << ": "; cin >> elementi[i];
                    }
    
                char* p = new char[k];
    
                cout << "Combinations: \n";
                combinazionisemplici(p, elementi, n, k, 0, 0, n-(k-1));
    
                break;
            }
        case 6: //combinazione ripetuta
            {
                unsigned int n=0, k=0;
                uintmax_t D=0;
    
                while(k==0 || n==0){
                	cout << "Insert the number of elements: "; cin >> n;
                        cout << "Insert the number of elements for each group: "; cin >> k;
		}
    
                D=fattoriale(n+k-1)/( fattoriale(k)*fattoriale(n-1) );
    
                cout << "Total number of combinations: " << D << endl;
    
                char* elementi = new char[n];
    
                for (int i=0; i<n; i++){
                    cout << "Element " << i+1 << ": "; cin >> elementi[i];
                }
    
                char* p = new char[k];
    
                cout << "Combinations: \n";
                combinazioniripetute(p, elementi, n, k, 0, 0);
    
                break;
            }
        }
    
        cout << "\nDo you want to exit? (Y=Yes|N=No)\n";
        cin >> again;
             
    }

    return 0;
}
