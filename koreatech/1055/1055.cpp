/*
http://tibyte.kr/269
*/

#include <cstdio>

int main()
{
	int T, N;
	int p, q, t;
	scanf("%d", &T);
	
	for(;T--;) {
		
		scanf("%d", &N);
		p=1;  //
		q=3;
		
		for(int i=2; i<N; i++){
			t = q;
			q += (2*p)%1000000007;
			q %= 1000000007;
			p = t;
		}
		
		if(N==1) q=1;
		
		printf("%d\n", q);
	}
}
