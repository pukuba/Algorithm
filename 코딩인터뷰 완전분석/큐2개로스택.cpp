#include <iostream>
#include <queue>

using namespace std;
queue<int> q1, q2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        string s;
        int x;
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            q1.push(x);
        }
        if (s == "pop")
        {
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            cout << q1.front();
            q1.pop();
            while (q2.size())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
}
