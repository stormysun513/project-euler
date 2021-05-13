#include <iostream>

using namespace std;

int main() {

	int ans = 0, found = 0;

	for(int a = 1; a < 1000; a++) {
		for(int b = a; (a + b) < 1000; b++) {
			for(int c = b; (a + b + c) <= 1000; c++) {
				if((a + b + c) != 1000) {
					continue;
				}
				if(a * a + b * b == c * c) {
					found = 1;
					ans = a * b * c;
					break;
				}
			}
			if(found) {
				break;
			}
		}
		if(found) {
			break;
		}
	}
	cout << ans << endl;

	return 0;
}
