/*Koristeći STL tuple napisati C++ program koji za uneseni n korisnik unosi n parova imena, prezimena učenika i prosjek ocjena spremljenih u vektor.
Program treba ispisati sve učenike silazno prema prosjeku ocjena.*/

#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef tuple <float, string, string> Ucenik;

int main()
{
    int n;
    cin >> n;

    vector<Ucenik> ucenici(n);

    for (int i = 0; i < n; i++)
    {
        string ime, prezime;
        float prosjek;

        cin.ignore();
        getline(cin, ime);
        getline(cin, prezime);
        cin >> prosjek;
        ucenici[i] = {prosjek, ime, prezime};
    }
    sort(ucenici.begin(), ucenici.end(), greater<Ucenik>());

    for (int i = 0; i < n; i++)
    {
        cout << get<1>(ucenici[i]) << " " << get<2>(ucenici[i]) << " " << get<0>(ucenici[i]) << endl;
    }
}