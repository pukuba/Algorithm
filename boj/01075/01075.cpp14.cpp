//100으로나누고 백으로 곱해
#include <iostream>

using namespace std;
int main() {
	unsigned long long a, save;
	int n;
	cin >> a >> n;
	a /= 100;
	a *= 100;
	save = a;
	for (int i = 0; i <= 99; i++) {
		a += i;
		if (i < 10) {
			if (a%n == 0) {
				cout << "0" << i << '\n';
				return 0;
			}
		}
		else {
			if (a%n == 0) {
				cout << i << '\n';
				return 0;
			}
		}
		a = save;
	}
}