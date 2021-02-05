#include <iostream>
#include <string>

using namespace std;
int main() {
	bool check = false;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		for (int j = 2; j < s.size(); j++) {
			if (s[j - 2] == 'F'&&s[j - 1] == 'B'&&s[j] == 'I') {
				check = true;
				cout << i << '\n';
				break;
			}
		}
	}
	if (!check) cout << "HE GOT AWAY!";
}