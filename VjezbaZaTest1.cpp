#include <iostream>
using namespace std;

class GeometrijskiLik
{
public:
    virtual double opseg() = 0;
    virtual double povrsina() = 0;
};

class Pravokutnik : public GeometrijskiLik
{
protected:
    double a, b;

public:
    Pravokutnik() : a(0), b(0) {}
    Pravokutnik(double a) : a(a), b(a) {}
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
        if (a >= 0)
        {
            this->a = a;
        }
    }

    void setB(double b)
    {
        if (b >= 0)
        {
            this->b = b;
        }
    }

    double opseg()
    {
        return 2 * (a + b);
    }

    double povrsina()
    {
        return a * b;
    }

    Pravokutnik operator+(const Pravokutnik &B)
    {
        return Pravokutnik(this->a + B.a, this->b + B.b);
    }

    friend ostream &operator<<(ostream &os, const Pravokutnik &p)
    {
        os << "(a = " << p.a << ", b = " << p.b << ")";
        return os;
    }
};

class Kvadrat : public Pravokutnik
{
public:
    Kvadrat() : Pravokutnik() {}

    Kvadrat(double a) : Pravokutnik(a) {}

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

class Krug : public GeometrijskiLik
{
protected:
    double r;
    static const double PI;

public:
    Krug() : r(0) {}

    Krug(double r)
    {
        setR(r);
    }

    double getR()
    {
        return r;
    }

    void setR(double r)
    {
        if (r >= 0)
        {
            this->r = r;
        }
    }

    double opseg()
    {
        return 2 * r * PI;
    }

    double povrsina()
    {
        return r * r * PI;
    }
};

const double Krug::PI = 3.14159;

int main()
{
    Pravokutnik prvi;
    prvi.setA(18);
    prvi.setB(9);

    Pravokutnik drugi(9);

    Pravokutnik treci(100.25, 125.1);

    Kvadrat prviK(18);

    Kvadrat drugiK;
    drugiK.setA(100.25);
    drugiK.setB(100.25);

    cout << "Pravokutnici:\n";
    cout << "A: " << prvi.getA() << ", B: " << prvi.getB()
         << " | Opseg: " << prvi.opseg() << ", Površina: " << prvi.povrsina() << endl;
    cout << "A: " << drugi.getA() << ", B: " << drugi.getB()
         << " | Opseg: " << drugi.opseg() << ", Površina: " << drugi.povrsina() << endl;
    cout << "A: " << treci.getA() << ", B: " << treci.getB()
         << " | Opseg: " << treci.opseg() << ", Površina: " << treci.povrsina() << endl;

    cout << "\nKvadarti:\n";
    cout << "A: " << prviK.getA() << ", B: " << prviK.getB()
         << " | Opseg: " << prviK.opseg() << ", Površina: " << prviK.povrsina() << endl;
    cout << "A: " << drugiK.getA() << ", B: " << drugiK.getB()
         << " | Opseg: " << drugiK.opseg() << ", Površina: " << drugiK.povrsina() << endl;

    int n;
    cin >> n;

    GeometrijskiLik **likovi = new GeometrijskiLik *[n];

    for (int i = 0; i < n; i++)
    {
        int izbor;
        cin >> izbor;

        if (izbor == 1)
        {
            double stranica;
            cin >> stranica;
            likovi[i] = new Kvadrat(stranica);
        }
        else if (izbor == 2)
        {
            double radijus;
            cin >> radijus;
            likovi[i] = new Krug(radijus);
        }
        else
        {
            cout << "Unos nije valjan!" << endl;
            i--;
            continue;
        }
    }

    // Ispis nakon unosa svih likova
    for (int i = 0; i < n; i++)
    {
        if (dynamic_cast<Kvadrat *>(likovi[i]))
        {
            Kvadrat *k = dynamic_cast<Kvadrat *>(likovi[i]);
            cout << k->getA() << " " << k->getB() << " " << k->opseg() << " " << k->povrsina() << endl;
        }
        else if (dynamic_cast<Krug *>(likovi[i]))
        {
            Krug *kr = dynamic_cast<Krug *>(likovi[i]);
            cout << kr->getR() << " " << kr->opseg() << " " << kr->povrsina() << endl;
        }
    }

    Pravokutnik zbroj = prvi + drugi;
    cout << "\nZbroj prvog i drugog pravokutnika: " << zbroj << endl;

    // Oslobađanje memorije
    for (int i = 0; i < n; i++)
    {
        delete likovi[i];
    }
    delete[] likovi;

    return 0;
}