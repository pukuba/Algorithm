#include <iostream>
#include <algorithm>

using namespace std;
bool check[246913];
int main() {
	check[1] = check[0] = true;
	for (int i = 2; i <= 246912; i++) {
		if (check[i] == true) continue;
		if (check[i] == false) {
			for (int j = i + i; j <= 246912; j += i) {
				check[j] = true;
			}
		}
	}
	while (1) {
		int n, ans = 0;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = n+1; i <= n * 2; i++) {
			if (check[i] == false) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}