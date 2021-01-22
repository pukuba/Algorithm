#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	int n, mx=0;
	cin >> n;
	int a[201], d[201];
	for (int i = 1; i <=n; i++) {
		cin >> a[i];
	}
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i]++;
			}
			mx = max(d[i], mx);
		}
	}
	cout << n - mx << '\n';
}