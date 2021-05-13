#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	bool nums[2000000];
	unsigned long sum = 0;

	memset(nums, 0, sizeof(nums));
	for(int i = 2; i < 2000000; i++) {
		if(!nums[i]) {
			sum += i;
		}
		for(int j = i; j < 2000000; j += i) {
			nums[j] = 1;
		}
	}
	cout << sum << endl;

	return 0;
}
