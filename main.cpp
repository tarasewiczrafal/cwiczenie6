 #include <iostream>
 #include <vector>
 #include <fstream>
 #include <sstream>
 #include <string>
 #include <stdexcept>
 #include <limits>

using namespace std;

struct Probka {
 double t;
 double x;

 Probka(double _t,double _x)
 {
     t= _t;
     x= _x;
 }
};

    vector <Probka> wczytaj (string nazwa)
    {
     vector <Probka> tablica;
     ifstream plik(nazwa);

     string linia;
     while(getline(plik,linia))
     {

        stringstream ss(linia);
         double _t, _x;
         ss >> _t;
         ss.ignore();
         ss >> _x;

*
        tablica.push_back (Probka(_t,_x)) ;

     }
     plik.close();

    return tablica;
    }

void odczyt(vector <Probka> probkix)
{
    for (int i =0; i < probkix.size(); i++)
    {
    cout<<probkix[i].t<<" ";
    cout<<probkix[i].x<<endl;
    }
}

void zapisz (vector <Probka> probkix)
{
    ofstream plik("Rafal_Tarasewicz.txt");
    for (int i = 0; i <= probkix.size(); i++)
    {
    plik << probkix[i].t << ", " << probkix[i].x << endl;
    }
plik.close();
}

    double mini (vector <Probka> probkix)
    {

    double minimum = 10000.0;

    for (int i = 0; i < probkix.size(); i++)
        {
     if (probkix[i].x < minimum)
     {
     minimum = probkix[i].x;
     }
}
 return minimum;
}

    double maxi (vector <Probka> probkix)
    {

    double maximum = -10000.0;


    for (int i = 0; i < probkix.size(); i++)
        {
     if (probkix[i].x > maximum)
     {
     maximum = probkix[i].x;
     }
}
 return maximum;
}

double srednia (vector <Probka> probkix)
{
     double m = 0.0;
     for (int i = 0; i < probkix.size(); i++)
        {
     m = m + probkix[i].x;
     }
     if (probkix.size() > 0)
        {
     m = m / probkix.size();

}
return m;
}

double calkowanie (vector<Probka> probkix)
{
    double dt1, dpole1, calka;
    for (int i = 0; i <= (probkix.size()) -1; i++)
    {
     dt1 = probkix[i + 1].t - probkix[i].t;
     dpole1 = (probkix[i].x + probkix[i + 1].x) * dt1 / 2;
    calka = calka + dpole1;
    }
   return calka;

}

double dlugosc_vectora(vector <Probka> probkiy)
{
    double probki_dtp = probkiy[0].t;

    double probki_dt = probkiy[probkiy.size()-1].t;
    double roznica = probki_dt - probki_dtp;

    return roznica;

}


int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        return -1;
    }
    cout << argv[1]<<endl;

    string nazwa_pliku = argv[1];

    vector <Probka> dane = wczytaj (nazwa_pliku);


    odczyt (dane);
    dlugosc_vectora (dane);
    cout<<endl;
    cout<<"Dlugosc wektora "<<dlugosc_vectora (dane)<<endl;
    mini(dane);
    cout<<"Minimum sygnalu "<<mini (dane)<<endl;
    maxi (dane);
    cout<<"Maksimum syganlu "<<maxi (dane)<<endl;
    srednia(dane);
    cout<<"Srednia wartosc sygnalu "<< srednia (dane)<<endl;
    calkowanie (dane);
    cout<<"Wartosc calki sygnalu wynosi "<<calkowanie (dane)<<endl;
    zapisz (dane);


    return 0;
}
