#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool sosu[10000001];

int main() {
	int n;
	cin >> n;
	sosu[0] = 1; sosu[1] = 1;
	for (int i = 2; i <= 10000000; i++) {
		if (sosu[i] == false) {
			for (int j = i + i; j <= 10000000; j+=i) {
				sosu[j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= 10000000; i++) {
		if (sosu[i] == false) {
			ans++;
		}
		if (ans == n) {
			cout << i << '\n';
			return 0;
		}
	}
}