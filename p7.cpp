#include <iostream>

using namespace std;

#define MAX_SIZE (1 << 20)

int main(int argc, char **argv) {
	bool nums[MAX_SIZE] = {0};
	int count = 0, ans = -1;
	
	memset(nums, 0, sizeof(nums));
	nums[0] = nums[1] = 1;
	for(int i = 2; i < MAX_SIZE; i++) {
		if(nums[i] == 0) {
			ans = i;
			count++;
			if(count == 10001) {
				break;
			}
		}
		for(int j = i; j < MAX_SIZE; j += i) {
			nums[j] = 1;
		}
	}

	cout << count << ", " << ans << endl;

	return 0;
}
