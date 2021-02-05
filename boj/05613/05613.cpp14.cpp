#include <iostream>

using namespace std;
int main() {
	int ans = 0;
	int a; cin >> a;
	ans += a;
	while (1) {
		char ch;
		cin >> ch;
		if (ch == '+') {
			int b;
			cin >> b;
			ans += b;
		}
		else if (ch == '-') {
			int b;
			cin >> b;
			ans -= b;
		}
		else if (ch == '*') {
			int b;
			cin >> b;
			ans *= b;
		}
		else if (ch == '/') {
			int b;
			cin >> b;
			ans /= b;
		}
		else if (ch == '=') {
			cout << ans;
			break;
		}
	}
}