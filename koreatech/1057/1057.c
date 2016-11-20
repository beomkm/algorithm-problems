/*
http://tibyte.kr/275
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T, L;//Testcase, Length
	int i, j;
	int s; //sum
	scanf("%d", &T);
	for(;~scanf("%d", &L);) {
		unsigned int t[10], d[10];
		
		for(s=i=0; i<10; i++)
			d[i] = 1;
		for(i=L-1; i--;) {
			memcpy(t, d, 40);
			d[0] = t[8];
			d[1] = t[2]+t[4];
			d[2] = t[1]+t[3]+t[5];
			d[3] = t[2]+t[6];
			d[4] = t[1]+t[5]+t[7];
			d[5] = t[2]+t[4]+t[6]+t[8];
			d[6] = t[3]+t[5]+t[9];
			d[7] = t[4]+t[8];
			d[8] = t[0]+t[5]+t[7]+t[9];
			d[9] = t[6]+t[8];
			for(j=0; j<10; j++) {
				d[j] %= 1000000007;
			}
		}
		
		for(i=0; i<10; i++) {
			s += d[i];
			s %= 1000000007;
		}
		
		printf("%d\n", s);
	}
	
	
	
	return 0;
}



