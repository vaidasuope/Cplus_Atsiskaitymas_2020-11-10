#include <iostream>
#include <fstream>
using namespace std;

 ifstream in("duomenys.txt");//susikuriame skaitymo komanda
 ofstream out("rezultatas.txt");//susikuriame rasymo komanda

 void masyvoKiekis(int &kiekis);
 void ivedimasMasyvo (int Z[], int kiekis);
 void isvedimasMasyvo (int Z[], int kiekis, string txt);
 void sumaFunkcija (int Z[], int kiekis, int suma);



int main()
{
    int kiekisM;
    masyvoKiekis(kiekisM);
    int M[kiekisM];
    ivedimasMasyvo(M, kiekisM);
    isvedimasMasyvo(M, kiekisM, "Masyvas:\n");
    int suma(0);
    sumaFunkcija (M, kiekisM,suma);


    in.close();//uzdarome bylas
    out.close();//uzdarome bylas
    return 0;
}

//Kieki suskaiciuojam

void masyvoKiekis(int &kiekis)
{
  int laikinas;
  kiekis=0;
  while(!in.eof()) //skaityk duomenuis tol kol ne failo pabaiga
    {
      in>>laikinas;
      kiekis++;
    }
    in.seekg(0);
}

//Ivedimas masyvo

void ivedimasMasyvo (int Z[], int kiekis)
{
    for (int i=0; i<kiekis; i++){
        in>>Z[i];
    }
}

//Isvedimas masyvo

void isvedimasMasyvo (int Z[], int kiekis, string txt)
{
    out<<txt;
    for (int i=0; i<kiekis; i++)
    {
        out<<Z[i]<<" ";
    }
    out<<endl;
}

//Sumos skaiciavimo funkcija
void sumaFunkcija (int Z[], int kiekis, int suma)
{
    for (int i=0; i<kiekis; i++)
    {
        if (Z[i]<0 && Z[i]%2==0){
            suma+=Z[i];
        }
    }
    out<<"Suma = "<<suma;
}
