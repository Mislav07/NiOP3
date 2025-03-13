/*Koristeći STL tuple napisati C++ program koji za uneseni n korisnik unosi n parova imena, prezimena učenika 
i prosjek ocjena spremljenih u vektor.Program treba ispisati sve učenike silazno prema prosjeku ocjena.*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

typedef tuple<string, string, float> UcenikPodaci;

int main()
{
    int n;
    cout << "Unesite broj ucenika: ";
    cin >> n;

    vector<UcenikPodaci> ucenici(n);

    for (int i = 0; i < n; i++)
    {
        string ime;
        string prezime;
        float prosjek;

        cout << "Unesite ime i prezime: ";
        cin.ignore();
        getline(cin, ime);
        getline(cin, prezime);
        cout << "Prosjek: ";
        cin >> prosjek;
        ucenici[i] = {ime, prezime, prosjek};
    }

    sort(ucenici.begin(), ucenici.end(), greater<UcenikPodaci>());

    for (int i = 0; i < n; i++)
    {
        cout << get<0>(ucenici[i]) << " " << get<1>(ucenici[i]) << " " << get<2>(ucenici[i]) << endl;
    }
}