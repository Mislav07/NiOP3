#include <iostream>
#include <tuple>
#include <string>
using namespace std;

int main()
{
    tuple<int, string> ime(10, "Andrija");
    cout << get<0> (ime) << " " << get<1>(ime) << endl;
    tuple<int, string> vid(10, "VID");
    cout << get<1> (vid);
}