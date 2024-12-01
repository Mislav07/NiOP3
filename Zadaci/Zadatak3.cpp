/*Napiši C++ program koji sadrži klasu "Pravokutnik" s dva atributa, metode za opseg i površinu, konstruktor bez argumenata, s jednim (koristeći skraćeni zapis) te s dva argumenta (koristeći this).
Napravite enkapsulacija atributa (setere i getere).
Instancirajte 3 objekta iz te klase koristeći različite konstruktore s vrijednostima atributa:
18 9
9 9
100.25 125.1

Program ispisuje te vrijednosti, njihov opseg i površinu u istom retku.*/

#include <iostream>
using namespace std;

class Pravokutnik{
    private:
        double a, b;
    public:
    Pravokutnik()
    {
        a = 0;
        b = 0;
    }
    Pravokutnik(double a) : a(a), b(a) {}
    Pravokutnik(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    double getA()
    {
        return a;
    }
    double getB()
    {
        return b;
    }
    void setA(double a)
    {
        if(a>=0)
        {
            this->a = a;
        }
    }
    void setB(double b)
    {
        if(b>=0)
        {
            this->b = b;
        }
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
    prvi.setA(18);
    prvi.setB(9);
    Pravokutnik drugi(9);
    Pravokutnik treci(100.25, 125.1);

    cout << prvi.getA() << " " << prvi.getB() << " " << prvi.opseg() << " " << prvi.povrsina() << endl;
    cout << drugi.getA() << " " << drugi.getB() << " " << drugi.opseg() << " " << drugi.povrsina() << endl;
    cout << treci.getA() << " " << treci.getB() << " " << treci.opseg() << " " << treci.povrsina() << endl;
    return 0;
}