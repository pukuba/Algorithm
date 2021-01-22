#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int check = 0;
int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int save = 0, keep = 0;
	for (int i = 0; i < 10; i++) {
		save += v[i];
		if (save == 100) {
			cout << "100";
			return 0;
		}
		if (save > 100) {
			keep = save;
			save -= v[i];
			break;
		}
		check++;
	}
	if (check == 10) {
		cout << save;
		return 0;
	}
	int a1=abs(save-100), a2=abs(keep-100);
	if (a2 <= a1) {
		cout << keep;
	}
	else {
		cout << save;
	}
}