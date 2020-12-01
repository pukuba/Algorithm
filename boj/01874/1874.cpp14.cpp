#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<char> ans;
stack<int> a;
int arr[100001];
int main() {
	int n, cnt = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		a.push(i);
		ans.push_back('+');
		while (!a.empty()&&a.top()==arr[cnt]) {
			a.pop();
			ans.push_back('-');
			cnt++;
		}
	}
	if (!a.empty()) cout << "NO" << "\n";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout<<ans[i]<<'\n';
		}
	}
	return 0;
}