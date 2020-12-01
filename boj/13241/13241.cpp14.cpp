#include <iostream>

using namespace std;
int lcd(long long a,long long b)
{
	if (b == 0) {
		return a;
	}
	else return lcd(b, a%b);
}
int main() {
	long long a, b;
	cin >> a >> b;
		cout << a*b/lcd(a, b);
}