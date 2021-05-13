#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
	int ans = 0;
	long val = 600851475143L, temp;
	int sqrt_val = sqrt(val);

	// cout << sqrt_val << endl;
	temp = val;
	for(int i = 3; i <= sqrt_val; i += 2) {
		while(temp % i == 0) {
			ans = i;
			temp /= i;
		}
	}
	if(temp > 2) {
		ans = temp;
	}

	cout << "Ans: " << ans << endl;
	
	return 0;
}
