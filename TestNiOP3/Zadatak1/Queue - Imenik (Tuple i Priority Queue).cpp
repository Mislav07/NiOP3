/*
Koristeći STL tuple napisati C++ program koji za uneseni n korisnik unosi n parova imena, prezimena učenika i prosjek ocjena spremljenih u priority queue.
Program treba ispisati sve učenike silazno prema prosjeku ocjena.*/

#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;


int main()
{
    priority_queue<tuple<float, string, string>> imenik;

    int brojUcenika;
    cin >> brojUcenika;

    for (int i = 0; i < brojUcenika; i++)
    {
        string ime, prezime;
        float prosjek;

        cin.ignore();
        getline(cin, ime);
        getline(cin, prezime);
        cin >> prosjek;

        imenik.push(make_tuple(prosjek, ime, prezime));
    }
    while (!imenik.empty())
    {
        auto ucenik = imenik.top();
        cout << get<1>(ucenik) << " " << get<2>(ucenik) << " " << get<0>(ucenik) << endl;
        imenik.pop();
    }
    return 0;
}