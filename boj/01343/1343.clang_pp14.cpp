#include <iostream>
#include <string>

using namespace std;
string a, b;
bool check;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> a;
	for (int i = 0; i < a.size(); i++){
		b += a[i];
		if (b.size() >= 4) if (b[b.size() - 1] == 'X' && b[b.size() - 2] == 'X' && b[b.size() - 3] == 'X' && b[b.size() - 4] == 'X'){
			for (int j = 0; j < 4; j++) b.pop_back();
			for (int j = 0; j < 4; j++) b += 'A';
		}
	}
	for (int i = 1; i < b.size(); i++) if (b[i - 1] == 'X' && b[i] == 'X') b[i - 1] = b[i] = 'B';
	for (char c : b) if (c == 'X') check = 1;
	if (check) cout << -1;
	else cout << b;
}