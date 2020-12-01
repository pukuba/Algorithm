#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,arr[111111],s=1,e=1,ans,sum,temp;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	ans = arr[1];
	while (s <= e && e != n + 1) {
		if (s == e) {
			temp = sum;
			sum += arr[e];
			e++;
			ans = max(ans, sum);
		}
		else if (0 < sum) {
			temp = sum;
			sum += arr[e];
			e++;
			if (s == e) continue;
			ans = max(ans, sum);
		}
		else {
			temp = sum;
			sum -= arr[s];
			s++;
			if (s == e) continue;
			ans = max(ans, sum);
		}
	}
	cout << ans << '\n';
}