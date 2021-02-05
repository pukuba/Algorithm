#include <iostream>
#include <string>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string str;
		int plus=0, ans=0;
		cin >> str;
		int a = str.size();
		for (int i = 1; i <= a; i++) {
			if (str[i - 1] == 'O'&&str[i] == 'O') {
				plus++;
				ans+=1+plus;
			}
			else if (str[i - 1] == 'O') {
				ans++;
			}
			else {
				plus = 0;
			}
		}
		cout<<ans<<'\n'; 

	}
}