#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int tc; cin>> tc;
	for (int i = 0; i < tc; i++) {
		int find;
		cin >> find;
		cout << upper_bound(a.begin(), a.end(), find) - lower_bound(a.begin(), a.end(), find) << ' ';
	}
	cout << '\n';
}