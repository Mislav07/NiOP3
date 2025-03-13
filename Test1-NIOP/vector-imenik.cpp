#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

typedef tuple<string, string, float> Ucenik;

int main()
{
    int n;
    cout << "Unesite broj ucenika" << endl;
    cin >> n;

    vector<Ucenik> ucenici(n);
    for (int i = 0; i < n; i++)
    {
        string ime, prezime;
        float prosjek;

        cin.ignore();
        cout << "Unesite ime: ";
        getline(cin, ime);
        cout << "Unesite prezime: ";
        getline(cin, prezime);
        cout << "Unesite prosjek: ";
        cin >> prosjek;
        ucenici[i] = {ime, prezime, prosjek};
    }
    sort(ucenici.begin(), ucenici.end(), greater<Ucenik>());
    for (int i = 0; i < n; i++)
    {
        cout << get<0>(ucenici[i]) << " " << get<1>(ucenici[i]) << " " << get<2>(ucenici[i]) << endl;
    }
    return 0;
}