#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> brojevi;
    int broj;
    cout << "Unesite brojeve: ";
    while(cin >> broj && broj != 0)
    {
        brojevi.push_back(broj);
    }
    vector<int> sortirani(brojevi);
    sort(sortirani.begin(), sortirani.end());

    vector<int> pomocni;
    for (int i = 0; i < brojevi.size(); i++)
    {
        int pojavljivanje = upper_bound(sortirani.begin(), sortirani.end(), brojevi[i]) - lower_bound(sortirani.begin(), sortirani.end(), brojevi[i]);
        if(pojavljivanje % 2 == 0)
        {
            pomocni.push_back(brojevi[i]);
        }
    }
        swap(brojevi, pomocni);
        pomocni.clear();
        pomocni.shrink_to_fit();

        cout << "Sortiani brojevi koji su se pojavili paran broj puta ";
        for (int i = 0; i < brojevi.size(); i++)
        {
            cout << brojevi[i] << " ";
        }
        return 0;
}