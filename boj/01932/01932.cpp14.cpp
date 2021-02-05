#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int d[501][501];
	int n, ans = -1;
	cin >> n;
	for (int i=1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)d[i][j] += d[i - 1][j];
			else if (j == n)d[i][j] += d[i - 1][j - 1];
			else d[i][j] += max(d[i - 1][j], d[i - 1][j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[n][i]);
	}
	cout << ans << '\n';
}