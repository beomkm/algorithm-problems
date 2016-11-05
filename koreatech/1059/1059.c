/*
http://tibyte.kr/271
*/


#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int main()
{
	int n;
	int i,j,k;
	int a[100], d[100][100], minD[100][100], maxD[100][100];
	int *p = a;

	scanf("%d",&n);
	for(;~scanf("%d",p++););
	
	for(i=0; i<n; i++) {
		minD[i][i] = a[i];
		maxD[i][i] = a[i];
	}
	
	for(i=1; i<n; i++) {  
		for(j=0; j<n-i; j++) {   
		
			minD[j][j+i] = MIN(minD[j][j+i-1], a[j+i]);
			maxD[j][j+i] = MAX(maxD[j][j+i-1], a[j+i]);
			
			d[j][j+i] = maxD[j][j+i]-minD[j][j+i];
			
			for(k=j+1; k<j+i-1; k++) {
				d[j][j+i] = MAX(d[j][j+i], d[j][k]+d[k+1][j+i]);
			}
		}
	}
	
	printf("%d",d[0][n-1]);
	
	return 0;
}
	
