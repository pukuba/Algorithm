#include <iostream>

using namespace std;
int d[11111], n, x;
long long ans;
int f(int x) {
	if (x <= 0) return 0;
	if (x == 1) return 1;
	if (d[x] != -1) return d[x];
	return d[x] = f(x - 3) + f(x - 2) + f(x - 1);
} 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	for (int i = 1; i <= 11; i++) d[i] = -1;
	cin >> x;
	f(10);
	while (x--) {
		cin >> n;
		cout << f(n+1) << '\n';
	}
}	