#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[1000001];
int save[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cnt=0; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int j = 0; j < n; j++) {
		cnt = max(cnt, save[arr[j]] = save[arr[j] - 1] + 1);
	}
	cout << n - cnt << '\n';
}