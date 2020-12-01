#include <cstdio>

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	int arr[6] = { 500,100,50,10,5,1 };
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		while (1) {
			if (n - arr[i] >= 0) {
				n -= arr[i];
				ans++;
			}
			else break;
		}
	}
	printf("%d", ans);
 }