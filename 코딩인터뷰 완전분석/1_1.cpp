#include <iostream>
#include <set>

using namespace std;
set<char> _set;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (char c : s)
    {
        if (_set.count(c))
        {
            return cout << 1, 0;
        }
        _set.insert(c);
    }
    cout << 0;
}
