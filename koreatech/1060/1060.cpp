/*
http://tibyte.kr/277
*/

#include <bits/stdc++.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
	char s[5001];
	int n;
	int i,j,k;
	int **d;
	d = (int**)malloc(5000*sizeof(int*));
	for(i=0; i<5000; i++){
		d[i]=(int*)malloc(5000*sizeof(int));
	}
	scanf("%s",s);
	n = strlen(s);
	
	
	for(i=0; i<n; i++) {
		d[i][i] = 0;
	}
	
	for(i=0; i<n-1; i++){
		if(s[i]!=s[i+1])
			d[i][i+1]=1;
		else
			d[i][i+1]=0;
	}
	
	for(i=3; i<=n; i++){ //section width
		for(j=0; j<=n-i; j++) { //section start
			if(s[j] == s[j+i-1]) {
				d[j][j+i-1] = d[j+1][j+i-2];
			}
			else {
				d[j][j+i-1] = 1+MIN(d[j][j+i-2],d[j+1][j+i-1]);
			}
		}
	}

	printf("%d\n", d[0][n-1]);
	
	for(i=0; i<5000; i++){
		free(d[i]);
	}
	free(d);
	
	return 0;
}


       
