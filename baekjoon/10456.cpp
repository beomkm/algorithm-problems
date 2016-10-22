/*
http://tibyte.kr/255
*/

#include <cstdio>
#include <algorithm>

int main()
{
	int t, n, a, b;
	
	scanf("%d", &t);
	for(;t--;) {
		int dp[10060] = {0,};
		int tr[10060] = {0,};
		int tr7=0, tr30=0;
		scanf("%d", &n);
		for(int i=30; i<n+60; i++) {
			int min;
			if(i<n+30) 
				scanf("%d%d", &a, &b);
			else
				a = b = 0;
			tr[i] = b;
			tr7 -= tr[i-7];
			tr7 += b+b;
			//tr30 -= tr[i-30];
			//tr30 += b;
			
			tr30 = 0;
			int cont = 0;
			for(int j=i-29; j<=i; j++) {
				if(tr[j]>3) {
					tr30 += 6;
					++cont;
				}
				else {
					tr30 += tr[j]+tr[j];
					cont = 0;
				}
			}
			if(cont>6)
				tr30 -= 6;
				
			
			min = dp[i-1]+a+b+b;
			min = std::min(min, dp[i-1]+3+b+b);
			min = std::min(min, dp[i-1]+6);
			min = std::min(min, dp[i-7]+18+tr7);
			min = std::min(min, dp[i-7]+36);
			min = std::min(min, dp[i-30]+45+tr30);
			min = std::min(min, dp[i-30]+90);
			dp[i] = min;
			//printf("i=%d, min=%d\n\n", i, min);
		}
		printf("%d\n", dp[n+60-1]);
	}
	
	return 0;
}
