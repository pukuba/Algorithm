#include <iostream>
#include <cstring>

using namespace std;
int gcd(int a, int b){ return b ? gcd(b, a%b) : a; }
int n, t, a[111];
long long ans;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t;
	while (t--){
		memset(a, 0, sizeof(a));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) ans += gcd(a[i], a[j]);
		cout << ans << '\n';
	}
}