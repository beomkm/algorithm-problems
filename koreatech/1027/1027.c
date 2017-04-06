int main()
{
	int n, f;
	scanf("%d", &n);
	char *i,*p;
	char s[100001], a[100001];
	
	for(;~scanf("%s",s);){
		i = s;
		p = a;
		*p = *i;
		++i;
		for(; *i; ++i) {
			++p;
			*p = *i;
			f = 0;
			if(*(i+1) != *p) {
				for(; p>a && *p == *(p-1); --p);
				f = 1;
			}
			if(f) --p;
		}
		*(p+1) = 0;
		printf("%s\n",a);
	}
}
