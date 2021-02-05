#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			ans++;
		}
	}
	cout << ans << '\n';
}