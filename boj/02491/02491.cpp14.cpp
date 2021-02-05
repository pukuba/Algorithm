#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n, ans=1, save=1;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) continue;
		if (a[i-1] <= a[i]) {
			ans++;
			save = max(ans, save);
		}
		else {
			ans = 1;
		}
	}
	ans = 1;
	for (int i = 0; i < n; i++) {
		if(i==0){
			continue;
		}
		if (a[i-1] >= a[i]) {
			ans++;
			save = max(ans, save);
		}
		else {
			ans = 1;
		}
	}
	cout << save << '\n';
	
}