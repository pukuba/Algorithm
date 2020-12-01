#include <bits/stdc++.h>
using namespace std;

int Mn = 1e9;
int arr[250000];
int N, K, B;

int main() {
    scanf("%d%d%d", &N, &K, &B);
    for (int i = 0, a; i < B; i++) {
        scanf("%d", &a);
        arr[a] = 1;
    }
    for (int i = 1; i <= 222222; i++) {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= N; i++) {
    	if(i + K - 1 > N) break;
        Mn = min(Mn, arr[i + K - 1] - arr[i - 1]);
    }
    printf("%d\n", Mn);

    return 0;
}