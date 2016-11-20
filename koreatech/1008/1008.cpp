#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

int main() {
	int n,a,b;
	int lenC, lenS;//len Cycle, len String
	char s[100000];
	std::map<int, int> log;
	int k;
	
	scanf("%d", &n);
	
	for(;~scanf("%d%d",&a,&b);) {
		log.clear();
		k = 0;
		lenC = 0;
		
		sprintf(s, "%d.", a/b);
		lenS = strlen(s);
		a = a%b*10;
		
		while(a != 0) {
			log[a] = k++;
			
			sprintf(s+lenS, "%d", a/b);
			lenS = strlen(s);
			a = a%b*10;
			
			if(log.find(a) != log.end()) {
				lenC = k - log[a];
				break;
			}
		}
		
		if(lenC == 0) {
			sprintf(s+lenS, "(0)");
			printf("%s\n", s);
			continue;
		}
		
		printf("%.*s(%.*s)\n", lenS-lenC, s, lenC, s+lenS-lenC);
		
	}
	
	return 0;
}

