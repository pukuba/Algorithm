#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int d[80001] = { 0, };
	for (int i = 1; i <= 80000; i++) {
		if (i % 3 == 0 || i % 7 == 0) {
			d[i] = d[i - 1] + i;
		}
		else d[i] = d[i - 1];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}