/*
2.3. Struktura podataka Vector - Izbacivač (Vector)
Max Score: 1 | Difficulty: Not Specified
Napisati C++ program u kojem korisnik unosi brojeve u vector dok ne unese nula.
Program izbacuje sve brojeve iz vectora koji se pojavljuju neparan broj puta.
Program ispisuje brojeve iz vectora ne mijenjajući njihov poredak koristeći pomoćni sortirani vector i bound funkcije.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<int> brojevi;
    int broj;
    while(cin >> broj && broj != 0)
    {
        brojevi.push_back(broj);
    }
    vector<int> sortirani(brojevi);
    sort(sortirani.begin(), sortirani.end());

    vector<int> pomocni;

    for (int i = 0; i < brojevi.size(); i++)
    {
        int pojavljivanje = upper_bound(brojevi.begin(), brojevi.end(), brojevi[i]) - lower_bound(brojevi.begin(), brojevi.end(), brojevi[i]);
        if(pojavljivanje % 2 == 0)
        {
            pomocni.push_back(brojevi[i]);
        }
    }
    swap(brojevi, pomocni);
    pomocni.clear();
    pomocni.shrink_to_fit();

    for (int i = 0; i < brojevi.size(); i++)
    {
        cout << brojevi[i] << " ";
    }
    return 0;
}