#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	else gcd(b, a%b);
}
int lcm(int a, int b) {
	return a * b / gcd(a,b);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while (tc--) {
		int n, m;
		scanf("%d %d",&n,&m);
		printf("%d %d\n",lcm(n,m),gcd(n,m));
	}
}