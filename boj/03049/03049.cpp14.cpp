#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << "0" << '\n';
		return 0;
	}
	cout << ((n - 1)*(n - 2)*(n - 3)*(n)) / 24 << '\n';
}