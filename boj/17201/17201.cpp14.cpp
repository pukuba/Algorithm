#include <iostream>
#include <string>

using namespace std;
int main() {
	int n;
	string str;
	cin >> n >> str;
	for (int i = 0; i < str.length(); i += 2) {
		if (str[0] != str[i]) {
			cout << "No"<<'\n';
			return 0;
		}
	}
	cout << "Yes" << '\n';
	return 0;
}