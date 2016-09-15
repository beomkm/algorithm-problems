
#include <bits/stdc++.h>

long long det(int sq[][500], int n, int zx, int zy)
{
	long long sumt, suma=0, sumb=0;
	
	if(n==1) return 1;
	
	sumt = 0;
	for(int i=0; i<n; i++)	
		sumt += sq[zy][i];
	sumb = sumt;
	
	sumt = 0;
	for(int i=0; i<n; i++)	
		sumt += sq[i][zx];
	if(sumt != sumb)
		return -1;
	
	if(zx==zy) {
		sumt = 0;
		for(int i=0; i<n; i++)	
			sumt += sq[i][i];
		if(sumt != sumb)
			return -1;
	}
		
	if(zx+zy == n-1) {
		sumt = 0;
		for(int i=0; i<n; i++)
			sumt += sq[i][n-i-1];
		if(sumt != sumb)
			return -1;
	}
	
	//horizontal
	for(int i=0; i<n; i++) {	
		sumt = 0;
		if(i == zy) continue;
		for(int j=0; j<n; j++)
			sumt += sq[i][j];
		if(suma == 0)
			suma = sumt;
		else if(suma != sumt)
			return -1;
	}
	
	//vertical
	for(int i=0; i<n; i++) {	
		sumt = 0;
		if(i == zx) continue;
		for(int j=0; j<n; j++)
			sumt += sq[j][i];
		if(suma != sumt)
			return -1;
	}

	if(zx != zy) {
		sumt = 0;
		for(int i=0; i<n; i++)
			sumt += sq[i][i];
		if(suma != sumt)
			return -1;
	}
	
	if(zx+zy != n-1) {
		sumt = 0;
		for(int i=0; i<n; i++)
			sumt += sq[i][n-i-1];
		if(suma != sumt)
			return -1;
	}
	
	if(suma == sumb || suma < sumb)
		return -1;
		
	return suma-sumb;
}

int main(void)
{
	int sq[500][500];
	int n;
	int zx, zy;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &sq[i][j]);
			if(sq[i][j] == 0) {
				zx = j;
				zy = i;
			}
		}
	}
	
	printf("%I64d", det(sq, n, zx, zy));
	
	return 0;
}
