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
        Pravokutnik()
        {
            a = 0;
            b = 0;
        }
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
            this->a = a;
        }
        void setB(double b)
        {
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
        void setR(double r)
        {
            if(r>=0)
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
    Kvadrat drugiK(100.25);


    cout << prvi.getA() << " " << prvi.getB() << " " << prvi.opseg() << " " << prvi.povrsina() << endl;
    cout << drugi.getA() << " " << drugi.getB() << " " << drugi.opseg() << " " << drugi.povrsina() << endl;
    cout << treci.getA() << " " << treci.getB() << " " << treci.opseg() << " " << treci.povrsina() << endl;

    cout << prviK.getA() << " " << prviK.getB() << " " << prviK.opseg() << " " << prviK.povrsina() << endl;
    cout << drugiK.getA() << " " << drugiK.getB() << " " << drugiK.opseg() << " " << drugiK.povrsina() << endl;

    int n;
    cin >> n;
    GeometrijskiLik **likovi = new GeometrijskiLik *[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Odaberite lik (1-kvadrat, 2-krug); " << endl;
        int izbor;
        cin >> izbor;
        if(izbor == 1)
        {
            double stranica;
            cin >> stranica;
            likovi[i] = new Kvadrat(stranica);
            cout << stranica << " " << stranica << " " << likovi[i]->opseg() << " ";
            cout << likovi[i]->povrsina() << endl;
        }
        else if(izbor == 2)
        {
            double radijus;
            cin >> radijus;
            likovi[i] = new Krug (radijus);
            cout << radijus << " " << likovi[i]->opseg() << " ";
            cout << likovi[i]->povrsina() << endl;
        }
    }
    cout << endl
         << "Podaci o svim likovima: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Opseg: " << likovi[i]->opseg() << ", ";
        cout << "Povrsina: " << likovi[i]->povrsina() << " " << endl;
        return 0;
    }
}