#include <iostream>

using namespace std;
int main() {
	int input[4];
	for (int i = 1; i < 4; i++) {
		cin >> input[i];
	}
	if (input[1] + input[2] + input[3] != 180) {
		cout << "Error";
	}
	else if (input[1] == input[2] && input[2] == input[3]) {
		cout << "Equilateral";
	}
	else if (input[1] == input[2] && input[2] != input[3] || input[2] == input[3] && input[3] != input[1] || input[1] == input[3] && input[2] != input[3]) {
		cout << "Isosceles";
	}
	else if (input[1] != input[2] && input[1] != input[3] && input[2] != input[3]) {
		cout << "Scalene";
	}

}