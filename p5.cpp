#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int ans = 2520;
	
	for(int i = 11; i <= 19; i += 2) {
		if((ans % i) != 0) {
			ans *= i;
		}
	}
	ans *= 2;
	
	cout << ans << endl;
	
	return 0;
}
