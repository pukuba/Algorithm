#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[1001];
bool check[1001];
void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	dfs(a[x]);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
			check[i] = false;
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			if (check[i] == false) {
				dfs(i);
				ans += 1;
			}
		}
		cout << ans << '\n';
	}
}