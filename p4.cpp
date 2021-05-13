#include <iostream>

using namespace std;

bool is_palindrome(int num) {
	int temp = num, revert = 0;
	while(temp) {
		revert = 10 * revert + temp % 10;
		temp /= 10;
	}
	return (num == revert);
}

int main(int argc, char **argv) {

	int ans = -1, found = 0;
	int start = 10000, end = 1000000;
	
	for(int i = end; i >= start; i--) {
		if(is_palindrome(i)) {
			for(int j = 100; j <= 999; j++) {
				if(i % j == 0 && (i / j) < 1000) {
					ans = i;
					found = 1;
					break;
				}
			}
		}
		if(found) {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
