/*Napiši C++ program koji sadrži klasu "Pravokutnik" s dva atributa, metode za opseg i površinu, konstruktor bez argumenata, s jednim (koristeći skraćeni zapis) te s dva argumenta (koristeći this).
Napravite enkapsulacija atributa (setere i getere).

Iz klase "Pravokutnik" naasljedite klasu "Kvadrat" koja ima 2 konstruktora, postavljanjem dujine stranice a postavlja se na istu duljinu i stranica b i obrnuto.

Instancirajte 3 objekta iz klase "Pravokutnik" koristeći različite konstruktore s vrijednostima atributa:
18 9
9 9
100.25 125.1

Instancirajte 2 objekta iz klase "Kvadrat" koristeći različite konstruktore s vrijednostima atributa:
18 18
100.25 100.25

Program ispisuje vrijednosti svih objekata, njihov opseg i površinu u svakom retku.*/

#include <iostream>
using namespace std;

class Pravokutnik
{
    protected:
        double a, b;
    public:
    Pravokutnik()
    {
        a = 0;
        b = 0;
    }
    Pravokutnik(double a) : a(a), b(a){}
    Pravokutnik(double a, double b)
    {
        setA(a);
        setB(b);
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

class Kvadrat : public Pravokutnik
{
    public:
    Kvadrat()
    {
        a = 0;
        b = 0;
    }
    Kvadrat(double a)
    {
        setA(a);
    }
    void setA(double a)
    {
        Pravokutnik::setA(a);
        Pravokutnik::setB(a);
    }
    void setB(double b)
    {
        Pravokutnik::setA(b);
        Pravokutnik::setB(b);
    }
};

int main()
{
    Pravokutnik prvi;
    prvi.setA(18);
    prvi.setB(9);
    Pravokutnik drugi(9);
    Pravokutnik treci(100.25, 125.1);

    Kvadrat prviK(18);
    Kvadrat drugiK(100.25);

    cout << prvi.getA() << " " << prvi.getB() << " " << prvi.opseg() <<" "<< prvi.povrsina() << endl;
    cout << drugi.getA() << " " << drugi.getB() << " " << drugi.opseg() <<" " << drugi.povrsina() << endl;
    cout << treci.getA() << " " << treci.getB() << " " << treci.opseg() << " " << treci.povrsina() << endl;

    cout << prviK.getA() << " " << prviK.getB() << " " << prviK.opseg() << " " << prviK.povrsina() << endl;
    cout << drugiK.getA() << " " << drugiK.getB() << " " << drugiK.opseg() << " " << drugiK.povrsina() << endl;

    return 0;
}