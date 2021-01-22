#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, ans = 0, cnt = 1;
vector<int> a;
int search(vector<vector<int>> &vec,int a, int b);
int main() {
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &v[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				search(v,i, j);
				a.push_back(ans);
			}
			ans = 0;
		}
	}
	cout << a.size() << '\n';
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size() ; i++) {
		cout << a[i] << '\n';
	}
}
int search(vector<vector<int>> &vec,int a, int b) {
	if (vec[a][b] == 1) {
		ans++;
		vec[a][b] = 0;
		if (a < n - 1) search(vec,a + 1, b);
		if (b < n - 1) search(vec,a, b + 1);
		if (a > 0) search(vec,a - 1, b);
		if (b > 0) search(vec,a, b - 1);
	}
	else {
		return 0;
	}
}