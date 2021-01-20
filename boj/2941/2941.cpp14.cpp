#include <iostream>
#include <string>

using namespace std;
int main() {
    int ans = 0;
    string w;
    cin >> w;
    for (int i = 0; i < w.size(); i++)
    {
        if (w[i] == '=')
        {
            if ((w[i - 1] == 'c' || w[i - 1] == 's') && i - 1 >= 0)
            {
                w[i] = '0';
            }
            else if (w[i - 1] == 'z' &&i - 1 >= 0)
            {
                if (w[i - 2] == 'd' && i - 2 >= 0)
                {
                    w[i - 1] = '0'; w[i] = '0';
                }
                else
                    w[i] = '0';
            }
        }
        else if (w[i] == '-')
        {
            if ((w[i - 1] == 'd' || w[i - 1] == 'c') &&  i - 1 >= 0)
                w[i] = '0';
        }
        else if (w[i] == 'j')
        {
            if ((w[i - 1] == 'l' || w[i - 1] == 'n') &&  i - 1 >= 0)
                w[i] = '0';
        }
    }
    for (int i = 0; i < w.size(); i++)
    {
        if (w[i] != '0')
            ans++;
    }
    cout << ans;
}