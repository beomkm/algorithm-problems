/*
http://tibyte.kr/273
*/

#include <cstdio>
#include <algorithm>

int main()
{
	int N;
	int arr[10000];
	int cnt = 0;
	int prv0;
	int prv;
	int i, j, k;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++) {
		scanf("%d", arr+i);
	}
	
	std::sort(arr, arr+N);
	
	prv0 = arr[0]-1;
	for(i=0; i<N; i++) {
		if(arr[i]==prv0)
			continue;
			
		prv0 = arr[i];

		j = i+1;
		k = N-1;
		prv = arr[j]-1;
		while(j<k) {
			if(arr[i]+arr[j]+arr[k] > 0)
				--k;
			else if(arr[i]+arr[j]+arr[k] < 0)
				++j;
			else {
				if(prv != arr[j]) {
					++cnt;
					prv = arr[j];
				}
				--k;
				++j;
			}
		}
	}

	
	printf("%d", cnt);
	
	return 0;
}


