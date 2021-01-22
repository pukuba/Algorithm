#include <iostream>
 
char grill[12][12];
int h, w;
using namespace std; 
int main(void)
{
    int tc; cin >> tc;
    while (tc--) {
        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++)
                cin >> grill[i][j];
        }
 
        for (int i = 1; i <= h; i++) {
            for (int j = w; j >= 1; j--)
                cout << grill[i][j];
            cout << '\n';
        }
    }
}
