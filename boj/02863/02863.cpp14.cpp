#include <iostream>

using namespace std;
int main() {
	double a, b, c, d, save[4] = { 0 ,}, ans = 0, max = 0;
	cin >> a >> b >> c >> d;
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			save[0] = (a / c) + (b / d);
		}
		if (i == 1) {
			save[1] = (c / d) + (a / b);
		}
		if (i == 2) {
			save[2] = (d / b) + (c / a);
		}
		if (i == 3) {
			save[3] = (b / a) + (d / c);
		}
		if (save[i] > max) {
			max = save[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (save[i] == max) {
			cout << i;
			return 0;
		}
	}
}