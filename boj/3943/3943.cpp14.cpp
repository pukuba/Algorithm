#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int ans = 1, n;
		cin >> n;
		while (n != 1) {
			ans = max(ans, n);
			if (n % 2 == 0) {
				n /= 2;
			}
			else if (n % 2 != 0) {
				n=(n * 3) + 1;
			}
		}
		cout << ans << '\n';
	}
}