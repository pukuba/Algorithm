#include <iostream>

using namespace std;
int arr[5][5];
int ans = 0;
int ansyoudo = 0;
int main() {
	int x, cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		cin >> x;
		ans = 0;
		cnt++;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == x) {
					arr[i][j] = 99;
				}
			}
		}
					if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] == arr[0][3] && arr[0][3] == arr[0][4]) ans++;
					if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] == arr[1][3] && arr[1][3] == arr[1][4]) ans++;
					if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] == arr[2][3] && arr[2][3] == arr[2][4]) ans++;
					if (arr[3][0] == arr[3][1] && arr[3][1] == arr[3][2] && arr[3][2] == arr[3][3] && arr[3][3] == arr[3][4]) ans++;
					if (arr[4][0] == arr[4][1] && arr[4][1] == arr[4][2] && arr[4][2] == arr[4][3] && arr[4][3] == arr[4][4]) ans++;
					if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] == arr[3][0] && arr[3][0] == arr[4][0]) ans++;
					if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] == arr[3][1] && arr[3][1] == arr[4][1]) ans++;
					if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] == arr[3][2] && arr[3][2] == arr[4][2]) ans++;
					if (arr[0][3] == arr[1][3] && arr[1][3] == arr[2][3] && arr[2][3] == arr[3][3] && arr[3][3] == arr[4][3]) ans++;
					if (arr[0][4] == arr[1][4] && arr[1][4] == arr[2][4] && arr[2][4] == arr[3][4] && arr[3][4] == arr[4][4]) ans++;
					if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3] && arr[3][3] == arr[4][4]) ans++;
					if (arr[0][4] == arr[1][3] && arr[1][3] == arr[2][2] && arr[2][2] == arr[3][1] && arr[3][1] == arr[4][0]) ans++;
					if (ans >= 3) {
						cout << cnt << '\n';
						return 0;
					}
	}
}