#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	unsigned int fib[2], sum = 0;
	int i = 2;

	fib[0] = fib[1] = 1;
	while(true) {
		int temp = fib[(i - 2) % 2] + fib[(i - 1) % 2];
		//cout << "fib[i]: " << temp << ", fib[i-2]: " << fib[(i - 2) % 2] << ", fib[i-1]: " << fib[(i - 1) % 2] << endl;
		if(temp > 4000000) {
			break;
		}
		if((temp % 2) == 0) {
			sum += temp;
		}
		fib[i % 2] = temp;
		i++;
	}

	cout << "Ans: " << sum << endl;
	
	return 0;
}
