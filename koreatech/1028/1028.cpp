/*
http://tibyte.kr/268
*/

#include <bits/stdc++.h>

int main()
{
	int T;
	int len, max;
	char s[10001];
	scanf("%d", &T);
	
	for(;T--;) {
		scanf("%s", s);
		len = max = 1;
		int i;
		for(i=0; s[i]; ++i) {
			if(s[i]==s[i+1]) ++len;
			else {
				if(len>max) max = len;
				len = 1;
			}
		}
		printf("%d\n", i-max);
	}
	
	return 0;
}
