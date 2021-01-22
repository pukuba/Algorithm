#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int a_size = a.size();
	int b_size = b.size();
	a_size >= b_size ? cout << "go" : cout << "no";
}