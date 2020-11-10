#include <iostream>
#include <fstream>
using namespace std;

ifstream in("duomenys2.txt");//susikuriame skaitymo komanda
ofstream out("rezultatas2.txt");//susikuriame rasymo komanda

void kiekis(int &kiek);
void ivedimasMasyvo(int Z[], int kiek);
void isvedimasMasyvo(int Z[], int kiek, string txt);
void kiekisIsvedimas(string txt, int kiek);
void maksimalus (string txt, int Z[], int kiek, int &maxZ);
void minimalus (string txt, int Z[], int kiek, int &minZ);
void Cradimas(string txt, int Z[], int W[], int kiekA, int kiekB, int maxZ, int minZ, int maxW, int minW, int Y[]);


int main()
{
    int kiekA, kiekB, kiekC;
    kiekis(kiekA);
    kiekisIsvedimas("A", kiekA);
    int A[kiekA];
    ivedimasMasyvo(A, kiekA);
    kiekis(kiekB);
    int B[kiekB];
    ivedimasMasyvo(B, kiekB);
    isvedimasMasyvo(A, kiekA, "A");
    int minA, minB, maxA, maxB, maxC;
    maksimalus ("A", A, kiekA, maxA);
    minimalus ("A", A, kiekA, minA);
    kiekisIsvedimas("B", kiekB);
    isvedimasMasyvo(B, kiekB, "B");
    maksimalus ("B", B, kiekB, maxB);
    minimalus ("B", B, kiekB, minB);
    int C[kiekC];
    Cradimas("C",A, B, kiekA, kiekB, maxA, minA, maxB, minB, C);


in.close();
out.close();
return 0;
}

//Kieki suskaiciuojam

void kiekis(int &kiek)
{
   in>>kiek;
}

void kiekisIsvedimas(string txt, int kiek)
{
   out<<txt<<" masyvo elementai: ";
   out<<kiek<<endl;;
}

//------------Masyvo ivedimas-------
void ivedimasMasyvo(int Z[], int kiek)
{
   for(int i=0; i<kiek; i++)
    {
        in>>Z[i];
    }
}

//-------------Masyvo isvedimas-----------
void isvedimasMasyvo(int Z[], int kiek, string txt)
{
    out<<txt<<" masyvas:\n";
    for(int i=0; i<kiek;i++)
    {
        out<<Z[i]<<" ";
    }
    out<<endl;
}

//Max radimas
void maksimalus (string txt, int Z[], int kiek, int &maxZ)
{
    out<<txt<<" masyvo maksimali reiksme: "<<endl;
    maxZ=Z[0];
    for(int i=0; i<kiek; i++)
    {
        if (Z[i]>maxZ)
            {
                maxZ=Z[i];
                }
                }
                out<<maxZ<<endl;;
}
//Min reiksme
void minimalus (string txt, int Z[], int kiek, int &minZ)
{
    out<<txt<<" masyvo minimali reiksme: "<<endl;
    minZ=Z[0];
    for(int i=0; i<kiek; i++)
    {
        if (Z[i]<minZ)
            {
                minZ=Z[i];
                }
            }
            out<<minZ<<endl;;
}
//C Masyvo Radimas
void Cradimas(string txt, int Z[], int W[], int kiekA, int kiekB, int maxZ,int minZ, int maxW, int minW, int Y[])
{

    out<<txt<<" masyvas:"<<endl;
    for(int i=0; i<kiekA; i++)
    {
        if(Z[i]<maxZ && Z[i]>minZ)
            {
                out<<Z[i]<<" ";
        }
    }

    for(int j=0; j<kiekB; j++){
            if(W[j]<maxW && W[j]>minW)
            {
                out<<W[j]<<" ";
                }
    }
}
