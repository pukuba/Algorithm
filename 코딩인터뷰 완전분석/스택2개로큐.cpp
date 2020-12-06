#include <iostream>
#include <stack>

using namespace std;
stack<int> stk1, stk2;
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
            stk1.push(x);
        }
        if (s == "pop")
        {
            while (stk1.size() != 1)
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            cout << stk1.top();
            stk1.pop();
            while (stk2.size())
            {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
    }
}
