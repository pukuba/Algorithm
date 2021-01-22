#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end(),cmp);
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
	cout << ans << '\n';
}