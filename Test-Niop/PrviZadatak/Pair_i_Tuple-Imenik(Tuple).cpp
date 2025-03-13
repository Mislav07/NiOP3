/*

2.2. Uvod u STL. Struktura podataka Pair i Tuple - Imenik (Tuple)
Max Score: 1 | Difficulty: Not Specified
Koristeći STL tuple napisati C++ program koji za uneseni n korisnik unosi n imena, prezimena učenika (spremiti odvojeno) i prosjek ocjena.
Program treba ispisati sve učenike silazno prema prosjeku ocjena.
*/

#include <iostream>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<float, string, string> Ucenik;

int main()
{
    int n;
    cout << "Unesite broj ucenika: ";
    cin >> n;

    Ucenik *ucenici = new Ucenik[n];

    for (int i = 0; i < n; i++)
    {
        string ime;
        string prezime;
        float prosjek;

        cout << "Unesite ime i prezime ucenika: ";
        cin.ignore();
        getline(cin, ime);
        getline(cin, prezime);
        cout << "Prosjek: ";
        cin >> prosjek;
        ucenici[i] = {prosjek, ime, prezime};
    }

    sort(ucenici, ucenici + n, greater<Ucenik>());

    for (int i = 0; i < n; i++)
    {
        cout << get<1>(ucenici[i]) << " " << get<2>(ucenici[i]) << " " << get<0>(ucenici[i]) << endl;
    }
    return 0;
}