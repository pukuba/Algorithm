#include <stdio.h>

int main() {
	int N, ans = 0;
	scanf("%d",&N);
	while (1) {
		if (N % 5 == 0) {
			printf("%d", (N / 5) + ans);
			return 0;
		}
		else {
			N -= 3;
			ans++;
		}
		if (N < 0) {
			printf("-1");
			return 0;
		}
	}
}