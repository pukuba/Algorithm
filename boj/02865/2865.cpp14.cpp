#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	float n, m, k;
	cin >> n >> m >> k;
	vector<pair<float, int>> a(n*m);
	for (int i = 0; i < n*m; i++) {
		cin >> a[i].second >> a[i].first;
	}
	float ans = 0;
	int cnt = 0;
	vector<int> check;
	sort(a.begin(), a.end());
	for (int i = n*m-1; i>=0; i--) {
		if (a[i].second != 999) {
			int save = a[i].second;
			a[i].second = 999;
			cnt++;
			ans += a[i].first;
			for (int j = 0; j < n*m; j++) {
				if (a[j].second == save) a[j].second = 999;
			}
		}
		if (cnt == k) break;
	}
	printf("%.1f", ans);
}