#include <iostream>

using namespace std;
int main() {
	int d[21];
	d[0] = 0, d[1]=1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
}