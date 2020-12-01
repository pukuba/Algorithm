#include <iostream>

using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	bool *check = new bool[n + 1];
	int count = 0, result = 0;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			for (int j = i; j <= n; j += i) {
				if (!check[j]) {
					check[j] = true, count++;
					if (count == m) result = j;
				}
			}
		}
	}
	cout << result << '\n';
}