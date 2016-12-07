/*
http://tibyte.kr/279
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int main()
{
	int T;
	int N;
	int arr[100002];
	int xors;
	int xora, xorb;
	int det;
	
	
	scanf("%d", &T);
	for(;T--;){
		memset(arr, 0, sizeof(int)*100002);
		scanf("%d", &N);
		xors = xora = xorb = 0;
		
		for(int i=0; i<N; ++i) {
			scanf("%d", arr+i);
			xors ^= arr[i];
		}
		
		det = xors & -xors;
		
		for(int i=0; i<N; ++i) {
			if(arr[i]&det) {
				xora ^= arr[i];
			}
			else {
				xorb ^= arr[i];
			}
		}
		
		if(xora < xorb)
			printf("%d %d\n", xora, xorb);
		else
			printf("%d %d\n", xorb, xora);
	}
	
	
	return 0;
}
		
		
