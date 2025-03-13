/*#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

  typedef pair <float, string> Ucenik;
int main()
{
  int n; //broj učenika
  cin >> n;

  Ucenik *ucenici = new Ucenik[n];

  for(int i = 0; i < n; i++)
  {
    string ime_prezime;
    float prosjek;

    cin.ignore();

    getline(cin, ime_prezime);
    cin >> prosjek;
    ucenici[i] = {prosjek, ime_prezime};
  }
  sort(ucenici, ucenici + n, greater<Ucenik>());

  for(int i = 0; i < n; i++)
  {
    cout << ucenici[i].second << " " << ucenici[i].first << endl;
  }
  return 0;
}*/
/*
Koristeći STL pair napisati C++ program koji za uneseni n korisnik unosi n parova imena, prezimena učenika i prosjek ocjena.
Program treba ispisati sve učenike silazno prema prosjeku ocjena.*/

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<float, string> Ucenik;

int main()
{
    int n;
    cout << "Unesite broj ucenika: ";
    cin >> n;

    Ucenik *ucenici = new Ucenik[n];

    for (int i = 0; i < n; i++)
    {
        string ime_prezime;
        float prosjek;

        cin.ignore();
        cout << "Unesite ime i prezime ucenika: ";

        getline(cin, ime_prezime);
        cout << "Prosjek: ";
        cin >> prosjek;

        ucenici[i] = {prosjek, ime_prezime};
    }
    sort(ucenici, ucenici + n, greater<Ucenik>());
    cout << "Ucenici sortirani po prosjecima: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ucenici[i].second << " " << ucenici[i].first << endl;
    }
    return 0;
}