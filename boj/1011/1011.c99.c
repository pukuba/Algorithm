#include <stdio.h>
long long int T,x,y;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&x ,&y);
		long long int dis = y-x;
		long long int cnt = 0; //총 이동거리
		long long int ans=1;
		while(cnt<dis) 
		{
			ans++;
			cnt +=(ans/2);
		}
		printf("%d\n",ans-1);
	}
}