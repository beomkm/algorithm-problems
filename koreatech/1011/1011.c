/*
http://tibyte.kr/267
*/

#include <stdio.h>

int main()
{
	int n, len;
	int cost, min;
	int d1, d2, d3;
	
	scanf("%d",&n);
	
	while(n--) {
		d1 = d2 = d3 = 0;
		scanf("%d",&len);
		
		while(len--) {
			scanf("%d",&cost);
			min = d1<d2?(d1<d3?d1:d3):(d2<d3?d2:d3);
			d3 = d2;
			d2 = d1;
			d1 = min+cost;
		}
		
		min = d1<d2?(d1<d3?d1:d3):(d2<d3?d2:d3);
		printf("%d\n", min);
	}
	return 0;
}
