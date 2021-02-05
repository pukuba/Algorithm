#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	int x = 100000001, vmin = 999999999, vmax = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vmin = min(vmin, k);
		vmax = max(vmax, k);
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = n-1; i >0; i--) {
		if (x > v[i] - v[i - 1]) {
			x = v[i] - v[i - 1];
		}
	}
	int yee = vmax-vmin;
	for (int i = 0; i < n; i++) {
		if (((v[i]-vmin) % x) != 0) {
			x--;
			i = 0;
		}
	}
	int cnt = 0, ans = 0;
	for (int i = vmin; i <= vmax; i += x) {
		if (v[cnt] == i) cnt++;
		else ans++;
	}
	cout << ans << '\n';
}