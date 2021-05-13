#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int sum = 0, target = 3;

	while(target < 1000) {
		sum += target;
		target += 3;
	}
	target = 5;
	while(target < 1000) {
		sum += target;
		target += 5;
	}
	target = 15;
	while(target < 1000) {
		sum -= target;
		target += 15;
	}

	cout << "Ans: " << sum << endl;

	return 0;
}
