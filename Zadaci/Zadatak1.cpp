/*Napiši C++ program koji sadrži klasu "Pravokutnik" s dva atributa i 3 objekta intanciranih iz te klase s vrijednostima atributa:
18 9
9 18
100.25 125.1

Program ispisuje te vrijednosti.*/

#include <iostream>
using namespace std;

class Pravokutnik{
    public:
        double a, b;
};

int main()
{
    Pravokutnik prvi, drugi, treci;
    prvi.a = 18;
    prvi.b = 9;

    drugi.a = 9;
    drugi.b = 18;

    treci.a = 100.25;
    treci.b = 125.1;

    cout << prvi.a << " " << prvi.b << endl;
    cout << drugi.b << " " << drugi.b << endl;
    cout << treci.a << " " << treci.b << endl;
    return 0;
}
