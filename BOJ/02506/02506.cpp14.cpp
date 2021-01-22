#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n, ans = 0, bs = 1;
	cin >> n;
	vector<int> a(n+1);
	a[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			bs = 1;
			continue;
		}
		else if (a[i - 1] == 0 && a[i] == 1) {
			ans += 1;
		}
		else if (a[i - 1] == 1 && a[i] == 1) {
			bs++;
			ans += bs;
		}
	}
	cout << ans << '\n';
}