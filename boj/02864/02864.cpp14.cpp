#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '6') {
			s1[i] = '5';
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '6') {
			s2[i] = '5';
		}
	}
	int a = stoi(s1);
	int b = stoi(s2);
	cout << a + b << ' ';
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '5') {
			s1[i] = '6';
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '5') {
			s2[i] = '6';
		}
	}
	a = stoi(s1);
	b = stoi(s2);
	cout << a + b;
}