#include <cstdio>

int main() {
	int n, m, k, ans = 0, ans2 = 0;
	scanf("%d %d %d", &n, &m, &k); //여자 남자 인턴
	while (ans!=k) {
		if (n/2 >= m  ) {
			n--;
			ans++;
		}
		else if (n /2 < m){
			m--;
			ans++;
		}
	}
	while (n-2>=0&&m-1>=0) {
		ans2++;
		n -= 2;
		m -= 1;
	}
	printf("%d", ans2);
}