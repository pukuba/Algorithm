#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string str[5];
	int ans = 0, strsize;
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].length() > i) {
				cout << str[j][i];
			}
		}
	}
	cout << '\n';
}