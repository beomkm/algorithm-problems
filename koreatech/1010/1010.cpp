//http://tibyte.kr/266
#include <iostream>

using namespace std;

bool isPrime(int n)
{
	//omit 1
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

void print(int n, int digit)
{
	if (digit==1) {
		cout << n << endl;
		return;
	}
	n *= 10;
	for (int i = 1; i < 10; i += 2) {
		if (i == 5) continue;
		if (isPrime(n + i)) {
			print(n + i, digit-1);
		}
	}
}

int main(void)
{ 
	int digit;
	cin >> digit;

	print(2, digit);
	print(3, digit);
	print(5, digit);
	print(7, digit);
	return 0;

}
