/*Napiši C++ program koji sadrži klasu "Pravokutnik" s dva atributa, metode za opseg i površinu, konstruktor bez argumenata, s jednim (koristeći skraćeni zapis) te s dva argumenta (koristeći this).
Instancirajte 3 objekta iz te klase koristeći različite konstruktore s vrijednostima atributa:
18 9
9 9
100.25 125.1

Program ispisuje te vrijednosti, njihov opseg i površinu u istom retku.*/

#include <iostream>
using namespace std;

class Pravokutnik
{
    public:
        double a, b;

    Pravokutnik()
    {
        a = 0;
        b = 0;
    }
    Pravokutnik(double a) : a(a), b(a){}
    Pravokutnik(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    double opseg()
    {
        return 2 * a + 2 * b;
    }
    double povrsina()
    {
        return a * b;
    }
};

int main()
{
    Pravokutnik prvi;
    prvi.a = 18;
    prvi.b = 9;
    Pravokutnik drugi(9);
    Pravokutnik treci(100.25, 125.1);

    cout << prvi.a << " " << prvi.b << " " << prvi.opseg() << " " << prvi.povrsina() << endl;
    cout << drugi.a << " " << drugi.b << " " << drugi.opseg() << " " << drugi.povrsina() << endl;
    cout << treci.a << " " << treci.b << " " << treci.opseg() << " " << treci.povrsina() << endl;
    return 0;
}