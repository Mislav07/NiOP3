#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    string token;
    vector<int> vec;
    stringstream ss(input);
    while (ss >> token)
    {
        vec.push_back(stoi(token));
    }
    stack<int> st;
    vector<int> res(vec.size(), 0);
    for (int i = 0; i < vec.size(); i++)
    {
        while (!st.empty() && vec[st.top()] < vec[i])
        {
            int idx = st.top();
            st.pop();
            res[idx] = i - idx;
        }
        st.push(i);
    }

    for (int elem : res)
    {
        cout << elem << " ";
    }
    return 0;
}