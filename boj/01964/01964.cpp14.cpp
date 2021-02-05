#include <iostream>

using namespace std;
int main() {
	int n, plus = 7;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) ans += 5;
		else {
			ans += plus;
			plus += 3;
			ans %= 45678;
		}
	}
	cout << ans << '\n';
}