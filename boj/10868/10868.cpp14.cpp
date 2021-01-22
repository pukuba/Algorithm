#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define max_n 1000001
typedef long long ll;
const int H = (int)ceil(log2(max_n));
const int tree_size = (1 << (H + 1));
const long long _INF=9876543212;
using namespace std;
vector<ll> a(max_n, 0);
vector<ll> tree(tree_size, 0);
void init(int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2],tree[node * 2 + 1]);
    }
}

//i j는 구하고자 하는 지점.
ll query(int node, int start, int end, int i, int j) {
    if (j < start || end < i) return _INF;
    if (i <= start && end <= j) return tree[node];
    ll m1 = query(node * 2, start, (start + end) / 2, i, j);
    ll m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
    return min(m1 ,m2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(1, 1, n);
    for(int i=1; i<=m; i++){
        int s,e;
        cin>>s>>e;
        cout<<query(1,1,n,s,e)<<'\n';
    }
    return 0;
}
