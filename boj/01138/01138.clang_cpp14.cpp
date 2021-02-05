#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a[11];
vector<int> v;		
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) v.push_back(i);
	do{
		bool can = 1;
		for (int i = 0; i < v.size(); i++){
			int cnt = a[v[i]];
			for (int j = i - 1; j >= 0; j--){
				if (v[j] > v[i]) cnt--;
			}
			if (cnt) can = 0;
		}
		if (can){
			for (int i : v) cout << i << ' ';
			return 0;
		}
	} while (next_permutation(v.begin(), v.end()));
}