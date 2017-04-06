//http://tibyte.kr/284

#include <cstdio>
#include <cmath>
#include <climits>

int main()
{
	int T;
	int P;
	
	scanf("%d", &T);
	
	for(;T--;) {
		scanf("%d", &P);
		int acc = 0;
		int base = 0;
		int i = 0;
		int num;
		int digit;
		char nstr[10];
	
		
		for(;P>acc && i<8; i++) {
			base = acc;
			acc += (i+1)*9*(int)pow(10, i);
		}
		if(P>acc && i==8) {
			base = acc;
			i = 9;
		}
		
		digit = (P-(base+1))%i;
		num = (P-(base+1))/i + (int)pow(10, i-1);
		
		sprintf(nstr, "%d", num);
		printf("%c\n", nstr[digit]);
		
	}
	
	return 0;
}
	
