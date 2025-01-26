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
private:
    double a, b;

public:
    Pravokutnik()
    {
        a = 0;
        b = 0;
    }
    Pravokutnik(double a)
    {
        this->a = a;
        this->b = a;
    }
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
        if (a >= 0)
            this->a = a;
    }
    void setB(double b)
    {
        if (b >= 0)
            this->b = b;
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
    Kvadrat()
    {
        setA(0);
        setB(0);
    }
    Kvadrat(double stranica)
    {
        setA(stranica);
        setB(stranica);
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

class Krug : public GeometrijskiLik
{
private:
    double r;
    static const double PI;

public:
    Krug()
    {
        r = 0;
    }
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
            this->r = r;
    }
    double opseg() override
    {
        return 2 * r * PI;
    }
    double povrsina() override
    {
        return r * r * PI;
    }
};

const double Krug::PI = 3.14159;

int main()
{
    Pravokutnik prvi(18, 9);
    Pravokutnik drugi(9);
    Pravokutnik treci(100.25, 125.1);
    cout << prvi.getA() << " " << prvi.getB() << " " << prvi.opseg() << " " << prvi.povrsina() << endl;
    cout << drugi.getA() << " " << drugi.getB() << " " << drugi.opseg() << " " << drugi.povrsina() << endl;
    cout << treci.getA() << " " << treci.getB() << " " << treci.opseg() << " " << treci.povrsina() << endl;

    Kvadrat cetvrti(18);
    Kvadrat peti(100.25);
    cout << cetvrti.getA() << " " << cetvrti.getB() << " " << cetvrti.opseg() << " " << cetvrti.povrsina() << endl;
    cout << peti.getA() << " " << peti.getB() << " " << peti.opseg() << " " << peti.povrsina() << endl;

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
            cout << stranica << " " << stranica << " " << likovi[i]->opseg() << " " << likovi[i]->povrsina() << endl;
        }
        else if (izbor == 2)
        {
            double radius;
            cin >> radius;
            likovi[i] = new Krug(radius);
            cout << radius << " " << likovi[i]->opseg() << " " << likovi[i]->povrsina() << endl;
        }
    }

    Pravokutnik zbroj = prvi + drugi;
    cout << zbroj << endl;

    for (int i = 0; i < n; i++)
    {
        delete likovi[i];
    }
    delete[] likovi;

    return 0;
}