#include <iostream>
#include <string>
#include <algorithm>

using namespace std;  //(6개수 + 9 개수 +1 )/2;
int main() {
	int num[10] = { 0, };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		num[s[i]-'0']++;
	}
	int sum = (num[6] + num[9] + 1) / 2;
	int ans=max({ num[0],num[1],num[2],num[3],num[4],num[5],sum,num[7],num[8] });
	cout << ans << '\n';
}