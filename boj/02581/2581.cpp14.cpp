#include <iostream>
#include <algorithm>

using namespace std;
bool check[10001];

int main() {
	check[1] = check[0] = true;
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 2; i <= 10001; i++) {
		if (check[i] == true) {
			continue;
		}
		if (check[i] == false) {
			for (int j = i+i; j <= 10001; j += i) {
				check[j] = true;
			}
		}
	}
	int n, m, ans = 0, ans2=10001;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (check[i] == false) {
			ans2 = min(i, ans2);
			ans += i;
		}
	}
	if (ans == 0) {
		cout << "-1" << '\n';
		return 0;
	}
	cout << ans << '\n';
	cout << ans2 << '\n';
}