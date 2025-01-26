#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    list<int> brojevi;
    int broj;
    while (cin >> broj && broj != 0)
        brojevi.push_back(broj);

    vector<int> sortirani(brojevi.begin(), brojevi.end());
    sort(sortirani.begin(), sortirani.end());
    for (auto it = brojevi.begin(); it != brojevi.end();)
    {
        if ((upper_bound(sortirani.begin(), sortirani.end(), *it) - lower_bound(sortirani.begin(), sortirani.end(), *it)) % 2 != 0)
            it = brojevi.erase(it);

        else
            it++;
    }

    for (auto broj : brojevi)
        cout << broj << " ";

    return 0;
}